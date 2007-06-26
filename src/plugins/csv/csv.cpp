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

#include <iostream>
#include <plugins/plugin_initializer.h>
#include "csv.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CPluginInitializer<CcsvPlugin> g_csv;

CcsvPlugin::CcsvPlugin()
{
    setName("CcsvPlugin");
}

CcsvPlugin::~CcsvPlugin()
{
}

bool CcsvPlugin::Write(const std::string& _path)
{
    bool l_ret = false;

    return l_ret;
}

std::string CcsvPlugin::Wildcard()
{
    return "csv (Comma Separated Value) files (*.csv)|*.csv";
}

bool CcsvPlugin::OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows)
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

bool CcsvPlugin::WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols)
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
