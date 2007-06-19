#ifndef _FILELOG_H
#define _FILELOG_H

#include <fstream>
#include <sstream>

class CFileLog
{
	public :
		CFileLog(const std::string& Filename = "output.log");
		~CFileLog();

		template <class T> CFileLog& operator <<(const T& ToLog)
		{
			std::ostringstream Stream;
			Stream << ToLog;
			m_File << Stream.str();
			return *this;
		}

	private:
		std::ofstream m_File;
};
#endif							 // _FILELOG_H
