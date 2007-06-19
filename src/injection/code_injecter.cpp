#include "code_injecter.h"

CCodeInjecter::CCodeInjecter():
m_File("_codeinjection.log"),
#if defined windows
m_GCCPath("c:\\Dev-Cpp\\bin\\g++.exe"),
#else
m_GCCPath("g++"),
m_ASPath("as"),
#endif
m_ASOptions(" -o "),
m_GCCOptions(" -S -o "),		 //-fverbose-asm -dletters ?
m_UserFunctionFound(false)
{

}


CCodeInjecter::~CCodeInjecter()
{
	ReportCodeInjection();
}


/*
 * @brief : _file is the file where we inject code for performance analysis and leak memory
 */
void CCodeInjecter::SetFile(std::string _file)
{
	m_FileName.assign(_file);
}


int CCodeInjecter::Inject()
{
	if(!CreateASM())
		return 0;
	if(!ASMPatch())
		return 0;
	if(!BuildObject())
		return 0;

	return 1;
}


/*
 *@brief : In order to inject code, we need to convert c++ code to asm code
 */
int CCodeInjecter::CreateASM()
{
	std::string _gcc(m_GCCPath);
	_gcc.append(m_GCCOptions);
	_gcc.append(m_FileName);
	_gcc.append(".s");
	_gcc.append(" ");
	_gcc.append(m_FileName);
	_gcc.append(".cpp");

	#if defined DEBUG
	std::cout << _gcc << std::endl;
	#endif

	system(_gcc.c_str());

	return 1;
}


/*
 *@brief : Now we can patch the assembler file (.s) in order to inject our code
 */
int CCodeInjecter::ASMPatch()
{
	std::string _input(m_FileName.c_str());
	_input.append(".s");
	std::ifstream original_asm(_input.c_str());
	std::string _output(m_FileName.c_str());
	_output.append("_patched.s");
	std::ofstream patched_asm(_output.c_str());

	if (!original_asm.is_open())
	{
		return 0;
	}

	if (!patched_asm.is_open())
	{
		original_asm.close();
		return 0;
	}

	#if defined DEBUG
	std::cout << "I inject " << _input << " in " << _output << std::endl;
	#endif

	while(!original_asm.eof())
	{
		//We grab one line
		std::string _temp;
		getline(original_asm, _temp);
		//We search for .globl pattern

		int res = (int)_temp.find("leave");
		//std::cout << res << m_UserFunctionFound << " / ";
		if(res >= 0 && m_UserFunctionFound)
		{
			patched_asm << "    call    _ZN6CDummy6dummy2Ev" << std::endl;
			#if defined DEBUG
			std::cout << "Insering call    _ZN6CDummy6dummy2Ev" << std::endl;
			#endif
			patched_asm << _temp << std::endl;
			getline(original_asm, _temp);
		}

		res = (int)_temp.find(".globl");
		//std::cout << " : " << res << _temp << std::endl;

		if(res >= 0)
		{
			//OK we have a function, we need to first check that it's a user function and not a system one
			//We need to eat :) the next line which contain the definition
			patched_asm << _temp << std::endl;
			getline(original_asm, _temp);

			//Now get the next line which contain the function name
			patched_asm << _temp << std::endl;
			getline(original_asm, _temp);

			//Now _temp contain the function name :
			int UserFunction = (int)_temp.find("_ZN");
			if(UserFunction == 0)
			{
				//Ok it seem to be a user function, we will do a last check :)
				int UserFunction2 = (int)_temp.find("Ev");
				if(UserFunction2 >= 0)
				{
					//Ok now we are sure we have found a user function
					#if defined DEBUG
					std::cout << "Found " << _temp << std::endl;
					#endif
					m_FunctionsList.push_back(_temp);
					m_UserFunctionFound = true;
				}
			}
			patched_asm << _temp << std::endl;
		}
		else
		{
			//We haven't found a user function so we just copy this line in output file
			patched_asm << _temp << std::endl;
		}
	}

	original_asm.close();
	patched_asm.close();
	return 1;
}


int CCodeInjecter::BuildObject()
{
	std::string _as(m_ASPath);
	_as.append(m_ASOptions);
	_as.append(m_FileName);
	_as.append(".o ");
	_as.append(m_FileName);
	_as.append("_patched.s");
	_as.append(" ");

	#if defined DEBUG
	std::cout << _as << std::endl;
	#endif

	system(_as.c_str());

	return 1;
}


void CCodeInjecter::ReportCodeInjection()
{
	m_File << "-----------------------------------------------------------------" << std::endl;
	m_File << "Code Injecter v " << VERSION_CODE_INJECTER << " - Report " << std::endl;
	m_File << "-----------------------------------------------------------------" << std::endl;

	m_File << "I found " << m_FunctionsList.size() << " user functions." << std::endl;

	for(unsigned int i=0; i < m_FunctionsList.size(); ++i)
	{
		m_File << m_FunctionsList[i] << std::endl;
	}

	//m_File << "Injection in : " << m_FileName << " succesfully works." << std::endl;
	m_File << "-----------------------------------------------------------------" << std::endl;
}
