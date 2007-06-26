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

#ifndef _CFILE_EXPLORER_H_
#define _CFILE_EXPLORER_H_

#include <wx/wx.h>
#include <wx/dirctrl.h>

class CMainFrame;

/*!
 * @brief Left Panel of sdatabase (This panel is used to easyly & quickly open databases).
 */
class CFileExplorer: public wxGenericDirCtrl
{
    public:
        /*!
         * @brief Default constructor.
         * @param parentframe A pointer used for callbacks.
         * @param parent A pointer of parent wxWindow which use it.
         * @param id ID of CFileExplorer.
         * @param pos Position of CFileExplorer.
         * @param size Size of CFileExplorer.
         * @todo parentframe == parent ??
         * @todo Add a 2nd constructor.
         */
        CFileExplorer(wxFrame* parentframe, wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size)
            :wxGenericDirCtrl(parent, id, _T(""), pos, size, 0, _T("csv files (*.csv)|*.csv"), 0 ), m_Parent(parentframe)
        {
#if defined DEBUG
            std::cout << "[DEBUG] [CFileExplorer] CFileExplorer()" << std::endl;
#endif
        }

        /*!
         * @brief Destructor
         */
        ~CFileExplorer()
        {
#if defined DEBUG
            std::cout << "[DEBUG] [CFileExplorer] ~CFileExplorer()" << std::endl;
#endif
        }

    protected:
        /*!
         * @brief wxCallbacks called when a file is selected.
         */
        void OnSel (wxTreeEvent& event);

    private:

        wxFrame*        m_Parent;///< Pointer for callback

        DECLARE_NO_COPY_CLASS(CFileExplorer)
            DECLARE_EVENT_TABLE()
};
#endif                           // _CFILE_EXPLORER_H_
