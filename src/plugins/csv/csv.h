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

#ifndef _CSV_PLUGIN_H_
#define _CSV_PLUGIN_H_

#include <config.h>
#include <plugins/iplugin.h>

class CcsvPlugin : public IPlugin
{
    public:
        CcsvPlugin();
        ~CcsvPlugin();

        /*
         * @brief From IPlugin.
         */
        bool Write(const std::string& _path);
        std::string Wildcard();

        /*
         * @brief From IFile.
         */
        bool OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows);
        bool WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols);
};
#endif                           //_CSV_PLUGIN_H_
