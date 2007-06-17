#include <iostream>
#include <fstream>

#include "csvfile.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

bool CCSVFile::OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows)
{
	#if defined DEBUG
	std::cout << "[DEBUG] [CCSVFile] [OpenFile] " << _filename << std::endl;
	#endif

	_cols = 1;
	_rows = 0;

	std::ifstream inputStream;
	inputStream.open(_filename.mb_str());

	#if defined DEBUG
	std::cout << "[DEBUG] [CCSVFile] Opening : " << _filename << std::endl;
	#endif

	if(!inputStream)
	{
		std::cerr << "[ERROR] [CCSVFile] Error opening input stream" << std::endl;
		return 0;
	}

	char n;
	bool _label = false;

	_title.clear();

	wxString temp;

	// Read labels
	while(!inputStream.eof())
	{
		inputStream.read(&n, sizeof(char));

		if(n == ',')
		{
			_title.push_back(temp);
			temp.clear();
			_cols++;
		}
		else if(n == '\n')
		{
			_title.push_back(temp);
			temp.clear();
			if(!_label)
			{
				_label = true;
			}
			break;
		}
		else
		{
			temp +=n;
		}

	}

	#if defined DEBUG && VERBOSE
	std::cout << "[DEBUG] [CCSVFile] Fill structure" << std::endl;
	#endif

	temp.clear();
	//Now fill the structure
	while(!inputStream.eof())
	{
		inputStream.read(&n, sizeof(char));
		static TTuple tuple;

		if(n == ',')
		{
			tuple.push_back(temp);
			temp.clear();
			#if defined DEBUG && VERBOSE
			std::cout << "[DEBUG] [CCSVFile] Found one item" << std::endl;
			#endif
		}
		else if(n == '\n')
		{
			if(!temp.empty())
			{
				tuple.push_back(temp);
				temp.clear();
				_table.push_back(tuple);
				tuple.clear();
				++_rows;
				#if defined DEBUG && VERBOSE
				std::cout << "[DEBUG] [CCSVFile] Adding tuple to Table" << std::endl;
				#endif
			}
		}
		else
		{
			temp += n;
		}
	}
	inputStream.close();

	#if defined DEBUG && VERBOSE
	//FIXME
	Affiche();
	#endif

	#if defined DEBUG
	std::cout << "[DEBUG] [CSVFile] : I found " << _cols << " columns !" << std::endl;
	#endif

	return true;
}


bool CCSVFile::WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols)
{
	std::ofstream outputStream;
	outputStream.open(_filename.mb_str());

	for(unsigned int i=0; i<(_title.size()-1); ++i)
	{
		outputStream << _title[i].mb_str() << ",";
	}
	outputStream << _title[_title.size()-1].mb_str();
	outputStream << "\n";

	TTable::iterator it;

	for (it = _table.begin(); it != _table.end(); ++it)
	{
		for(unsigned int i=0; i<(it->size()-1); ++i)
		{
			outputStream << (*it)[i].mb_str() << ",";
		}
		outputStream << (*it)[it->size()-1].mb_str();
		outputStream << "\n";
	}

	outputStream.close();
	return true;
}
