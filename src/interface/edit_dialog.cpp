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
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/valtext.h>

#include "edit_dialog.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

CEditDialog::CEditDialog(wxWindow * parent, TTuple& _title, TTuple& _tuple, wxString _BoxTitle) :
wxDialog(parent, wxID_ANY, _BoxTitle, wxDefaultPosition, wxDefaultSize)
{
	wxBoxSizer * topsizer = new wxBoxSizer( wxVERTICAL );
	wxGridSizer * sizer = new wxGridSizer(2);

	for(unsigned int i=0; i<_tuple.size(); ++i)
	{
		sizer->Add(new wxStaticText(this, -1, _title[i], wxDefaultPosition, wxDefaultSize, 0), 0, wxALL, 5 );
		sizer->Add(new wxTextCtrl(this, -1, _tuple[i], wxDefaultPosition, wxDefaultSize, 0, wxTextValidator(wxFILTER_NONE, &_tuple[i])), 0, wxALL, 5);
	}

	topsizer->Add(sizer, 0, wxALIGN_CENTER);

	wxStdDialogButtonSizer * sizer2 = new wxStdDialogButtonSizer();
	sizer2->AddButton( new wxButton(this, wxID_OK) );
	sizer2->Realize();
	topsizer->Add(sizer2, 0, wxALL | wxCENTER, 10);

	SetSizer( topsizer );
	topsizer->SetSizeHints( this );
}
