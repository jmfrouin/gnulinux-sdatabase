#include "filelog.h"

#if defined LEAK_DETECTOR
    #include <leak/leak_detector.h>
#endif

CFileLog::CFileLog(const std::string& Filename) :
m_File(Filename.c_str())
{
    m_File << "  ===========================================" << std::endl;
    m_File << "   CFileLog  v0.1 - Event log - " << std::endl;
    m_File << "  ===========================================" << std::endl << std::endl;
}

CFileLog::~CFileLog()
{
    m_File << std::endl;
    m_File << "  ===========================================" << std::endl;
    m_File << "   CFileLog closed " << std::endl;
    m_File << "  ===========================================" << std::endl;
}

