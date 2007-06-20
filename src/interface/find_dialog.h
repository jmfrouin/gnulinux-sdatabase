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

#ifndef _FIND_DIALOG_H_
#define _FIND_DIALOG_H_

#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

#include <vector>

/*!
 * @brief Find dialog box.
 */
class CFindDialog: public wxDialog
{
	public:
		/*!
		 * @brief Default constructor.
		 * @param parent A pointer on parent wxWindow
		 * @param _bookmark If true, bookmark result
		 * @param _reverse If true, do a reverse find
		 * @todo Write a 2nd constructor.
		 */
		CFindDialog(wxWindow * parent, bool _bookmark, bool _reverse);

	protected:
		void OnFind(wxCommandEvent& event);

	private:
		wxFrame*        m_Parent;
		wxTextCtrl*     m_Text;
		wxCheckBox*     m_Bookmark;
		wxCheckBox*     m_Reverse;

	private:
		DECLARE_EVENT_TABLE();

};
#endif							 // _FIND_DIALOG_H_
