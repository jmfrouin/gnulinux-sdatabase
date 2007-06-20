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

/*
 * @brief :      New table creation dialog
 * @author :     Jean-Michel Frouin
 * @date :       09/01/2007
 */

#ifndef _NEW_TABLE_DIALOG_H_
#define _NEW_TABLE_DIALOG_H_

#include <wx/dialog.h>
#include <def.h>

/*!
 * @brief Dialog called when a new base is created.
 */
class CNewTableDialog: public wxDialog
{
	public:
		/*!
		 * @brief Default constructor.
		 * @param parent Parent pointer.
		 */
		CNewTableDialog(wxWindow * parent);

	private:
		int         m_Number;
};
#endif							 // _NEW_TABLE_DIALOG_H_
