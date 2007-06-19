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
