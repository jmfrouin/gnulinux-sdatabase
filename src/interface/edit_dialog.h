#ifndef _EDIT_DIALOG_H_
#define _EDIT_DIALOG_H_

#include <vector>

#include <wx/dialog.h>
#include <def.h>

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

#endif   // _EDIT_DIALOG_H_
