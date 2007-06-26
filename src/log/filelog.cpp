/*
-------------------------------------------------------------------------
Project : sdatabase
-------------------------------------------------------------------------
Creator : Frouin Jean-Michel
-------------------------------------------------------------------------
$Date$
$Rev$
$Author$
-------------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
-------------------------------------------------------------------------
*/

#include "filelog.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

CFileLog::CFileLog(const std::string& Filename) :
m_File(Filename.c_str())
{
    m_File << "  ===========================================" << "\n";
    m_File << "   CFileLog  v0.1 - Event log - " << "\n";
    m_File << "  ===========================================" << "\n" << "\n";
}

CFileLog::~CFileLog()
{
    m_File << "\n";
    m_File << "  ===========================================" << "\n";
    m_File << "   CFileLog closed " << "\n";
    m_File << "  ===========================================" << "\n";
}
