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

#ifndef _CXMLFile_H_
#define _CXMLFile_H_

#include "ifile.h"

/*!
 * @brief XML plugin : import/export as XML.
 */
class CXMLFile : public IFile
{
	public:
		/*!
		 * @brief From IFile.
		 */
		bool OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows);
		bool WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols);
};
#endif							 // _CXMLFile_H_
