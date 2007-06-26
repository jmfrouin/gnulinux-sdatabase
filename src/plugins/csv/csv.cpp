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

CPluginInitializer<CcsvPlugin> g_csv;
