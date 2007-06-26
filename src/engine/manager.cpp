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

#include <files/csvfile.h>
#include "manager.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

//------------------------------------------------------------------------------------------------
// Constructors & destructor
//------------------------------------------------------------------------------------------------
CManager::CManager()
{
}

int CManager::Construct():
m_File(0), m_Tools(0), m_Table(0), m_Cols(1), m_Rows(0)
{
    m_Table = new TTable;
    m_Tools = new CTools;

    if(m_Table && m_Tools)
    {
        m_Tools->Construct();
        return 1;
    }
    else
    {
        return 0;
    }
}

CManager::~CManager()
{
    if(m_File)
    {
        delete m_File;
    }

    if(m_Table)
    {
        delete m_Table;
    }

    if(m_Tools)
    {
        delete m_Tools;
    }
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
// File manipulation
//------------------------------------------------------------------------------------------------

bool CManager::OpenFile(const wxString _filename)
{
#if defined DEBUG
    std::cout << "CManager handle now " << _filename.mb_str() << std::endl;
#endif

    //If a file is already open we first need to close it :)
    if(m_File)
    {
        delete m_File;
    }

    m_File = new CCSVFile();
    m_Table->clear();

    return m_File->OpenFile(_filename, *m_Table, m_Title, m_Cols, m_Rows);
}

wxString CManager::GetFilename()
{
    return m_Filename;
}

void CManager::WriteFile ()
{
    m_File->WriteFile(wxString(_T("poulpe.csv")), *m_Table, m_Title, m_Cols);
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
// Misc
//------------------------------------------------------------------------------------------------
int CManager::GetRows ()
{
    return m_Rows;
}

int CManager::GetCols()
{
    return m_Cols;
}

std::vector<wxString>& CManager::GetTitles ()
{
    return m_Title;
}

void CManager::Append(TTuple _tuple)
{
    m_Table->push_back(_tuple);
}

TTable* CManager::GetTable ()
{
    return m_Table;
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//						CTools calls
//------------------------------------------------------------------------------------------------

int CManager::SortTable(int _column, bool _mode)
{
    TTable temp;
    m_Tools->SortTable(m_Table, temp, _column, _mode);
    m_Table->clear();
    m_Table->assign( temp.begin(), temp.end() );
    return 1;
}

bool CManager::Find(wxString _search, int& _col, int& _row, bool _fromlastpos, bool _reverse)
{
    return m_Tools->Find(_search, _col, _row, m_Table, m_Cols, m_Rows, _fromlastpos, _reverse);
}

//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//				DEBUG Functions
//------------------------------------------------------------------------------------------------

#if defined DEBUG
void CManager::Display()
{
    TTable::iterator it;

    for(it = m_Table->begin(); it != m_Table->end(); ++it)
    {
        std::cout << "[DEBUG] [IFile] " << "[size = " << it->size() << "] ";
        for(unsigned int i=0; i<it->size(); ++i)
        {
            std::cout << (*it)[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Columns : " << std::endl;

    for(unsigned int i = 0; i < m_Title.size(); ++i)
    {
        std::cout << m_Title[i] << std::endl;
    }
}
#endif
//------------------------------------------------------------------------------------------------
