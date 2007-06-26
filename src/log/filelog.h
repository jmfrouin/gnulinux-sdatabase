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
#endif                           // _FILELOG_H
