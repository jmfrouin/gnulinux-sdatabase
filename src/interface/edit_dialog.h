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

#ifndef _EDIT_DIALOG_H_
#define _EDIT_DIALOG_H_

#include <vector>

#include <wx/dialog.h>
#include <config.h>

/*!
 * @brief Edit dialog for insertion in database
 */
class CEditDialog: public wxDialog
{
    public:
        /*!
         * @brief Default Construtor.
         * @param parent Parent pointer.
         * @param _title Database headers (vector of wxString).
         * @param _tuple A vector of string which will receive the added line.
         * @param _BoxTitle Title of editbox in order to re-use it later
         * @todo Write a 2nd constructor.
         */
        CEditDialog(wxWindow * parent, TTuple& _title, TTuple& _tuple, wxString _BoxTitle);
};
#endif                           // _EDIT_DIALOG_H_
