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

#ifndef _IFILE_H_
#define _IFILE_H_

#include <wx/string.h>
#include <config.h>

/*!
 * @brief File manipulation plugins interface.
 */
class IFile
{
	public:
		/*!
		 * @brief	Default constructor.
		 */
		IFile();
		/*!
		 * @brief	Destructor.
		 */
		virtual ~IFile();

	public:
		/*!
		 * @brief	Open a file in sdatabase.
		 * @param	_filename	The filename to open.
		 * @param	_table		The table to fill.
		 * @param	_title		Title list to fill.
		 * @param	_cols		Number of columns.
		 * @param	_rows		Number of rows.
		 * @return	bool		True if evertyhing goes fine, false otherwise.
		 */
		virtual bool OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows) = 0;
		/*!
		 * @brief	Write database in a file.
		 * @param	_filename	The filename to write.
		 * @param	_table		The table to write.
		 * @param	_title		Title list to write.
		 * @param	_cols		Number of columns.
		 * @return	bool		True if evertyhing goes fine, false otherwise.
		 */
		virtual bool WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols) = 0;
};
#endif							 // _IFILE_H_
