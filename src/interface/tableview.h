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

#ifndef _CTABLEVIEW_H_
#define _CTABLEVIEW_H_

#include <vector>
#include <iostream>

#include <wx/listctrl.h>

#include <config.h>

/*!
 * @brief Right panel of sdatabase (Display the current opened database).
 * @todo Finish writting.
 */
class CTableView: public wxListCtrl
{
    public:
        /*!
         * @brief Default constructor.
         * @param parent A pointer on parent wxWindow.
         * @param parentframe A pointer on parent wxFrame.
         * @param id ID of this UI.
         * @param pos Position of CTableView.
         * @param size Size of CTableView.
         * @param style Style of CTableView.
         * @todo Check if parentframe == parent
         */
        CTableView(wxFrame* parentframe, wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
            : wxListCtrl(parent, id, pos, size, style), m_attr(*wxBLUE, *wxLIGHT_GREY, wxNullFont),m_Parent(parentframe)
        {
            //EnableContextMenu();
#if defined DEBUG
            std::cout << "[DEBUG] [CTableView] CTableView()" << std::endl;
#endif
        }

        /*!
         * @brief Destructor.
         */
        ~CTableView()
        {
#if defined DEBUG
            std::cout << "[DEBUG] [CTableView] ~CTableView()" << std::endl;
#endif
        }

        /*!
         * @brief Insert an item in database.
         * @param _list Item to add.
         * @param i
         */
        void InsertTableItem(std::vector<wxString> _list, int i);
        /*!
         * @brief Call when an item is selected.
         */
        void OnItemSelected(wxListEvent& event);
        /*!
         * @brief Call when user click on column (for sorting by example).
         */
        void OnColClick(wxListEvent& event);

        void OnColRightClick(wxListEvent& event);
        void OnColBeginDrag(wxListEvent& event);
        void OnColDragging(wxListEvent& event);
        void OnColEndDrag(wxListEvent& event);
        void OnBeginDrag(wxListEvent& event);
        void OnBeginRDrag(wxListEvent& event);
        void OnBeginLabelEdit(wxListEvent& event);
        void OnEndLabelEdit(wxListEvent& event);
        void OnDeleteItem(wxListEvent& event);
        void OnDeleteAllItems(wxListEvent& event);
        void OnGetInfo(wxListEvent& event);
        void OnSetInfo(wxListEvent& event);
        void OnSelected(wxListEvent& event);
        void OnDeselected(wxListEvent& event);
        void OnListKeyDown(wxListEvent& event);
        void OnActivated(wxListEvent& event);
        void OnFocused(wxListEvent& event);
        void OnCacheHint(wxListEvent& event);

        void OnChar(wxKeyEvent& event);

        void OnContextMenu(wxContextMenuEvent& event);

    private:
        void ShowContextMenu(const wxPoint& pos);
        void SetColumnImage(int col, int image);

        void LogEvent(const wxListEvent& event, const wxChar *eventName);
        void LogColEvent(const wxListEvent& event, const wxChar *eventName);

        virtual wxString OnGetItemText(long item, long column) const;
        virtual int OnGetItemImage(long item) const;
        virtual wxListItemAttr *OnGetItemAttr(long item) const;

        wxListItemAttr    m_attr;
        wxFrame*        m_Parent;

        DECLARE_NO_COPY_CLASS(CTableView)
            DECLARE_EVENT_TABLE()
};
#endif                           // _CTABLEVIEW_H_
