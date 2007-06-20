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

#include "xmlfile.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

bool CXMLFile::OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows)
{
	return true;
}


bool CXMLFile::WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols)
{
	return true;
}
