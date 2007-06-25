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

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/valtext.h>

#include "find_dialog.h"

#include <interface/interface.h>
#include <config.h>

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

BEGIN_EVENT_TABLE(CFindDialog, wxDialog)
EVT_BUTTON(ID_FIND, CFindDialog::OnFind)
END_EVENT_TABLE()

CFindDialog::CFindDialog(wxWindow * parent, bool _bookmark, bool _reverse):
wxDialog(parent, wxID_ANY, wxT("Find"), wxDefaultPosition, wxDefaultSize), m_Parent((wxFrame*)parent)
{
	wxValidator::SetBellOnError(true);

	wxStaticBox* itemStaticBoxSizer2Static = new wxStaticBox(this, wxID_ANY, _("Find dialog"));
	wxStaticBoxSizer* itemStaticBoxSizer2 = new wxStaticBoxSizer(itemStaticBoxSizer2Static, wxVERTICAL);
	SetSizer(itemStaticBoxSizer2);

	wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	itemStaticBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxSHAPED|wxADJUST_MINSIZE, 5);

	wxStaticText* itemStaticText4 = new wxStaticText( this, wxID_STATIC, _("Search for "), wxDefaultPosition, wxDefaultSize, 0 );
	itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

	m_Text = new wxTextCtrl( this, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_Text->SetFocus();
	itemBoxSizer3->Add(m_Text, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	itemStaticBoxSizer2->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

	m_Bookmark = new wxCheckBox( this, wxID_ANY, _("Bookmark"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Bookmark->SetValue(_bookmark);
	itemBoxSizer6->Add(m_Bookmark, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	m_Reverse = new wxCheckBox( this, wxID_ANY, _("Reverse"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Reverse->SetValue(_reverse);
	itemBoxSizer6->Add(m_Reverse, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	itemStaticBoxSizer2->Add(itemBoxSizer9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

	wxButton* itemButton10 = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	itemBoxSizer9->Add(itemButton10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	wxButton* itemButton11 = new wxButton( this, ID_FIND, _("Find"), wxDefaultPosition, wxDefaultSize, 0 );
	itemBoxSizer9->Add(itemButton11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

	if (GetSizer())
	{
		GetSizer()->SetSizeHints(this);
	}
	Centre();

}


//Callbacks
void CFindDialog::OnFind(wxCommandEvent& event)
{
	((CMainFrame*)m_Parent)->Find(m_Text->GetValue(), m_Bookmark->GetValue(), m_Reverse->GetValue());
}
