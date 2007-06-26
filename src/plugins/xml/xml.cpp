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
#include "xml.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CPluginInitializer<CxmlPlugin> g_xml;

CxmlPlugin::CxmlPlugin()
{
    setName("CxmlPlugin");
}

CxmlPlugin::~CxmlPlugin()
{
}

std::string CxmlPlugin::Wildcard()
{
    return "xml (Extensive Markup Language) files (*.xml)|*.xml";
}

bool CxmlPlugin::OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows)
{
    return true;
}

bool CxmlPlugin::WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols)
{
    return true;
}
