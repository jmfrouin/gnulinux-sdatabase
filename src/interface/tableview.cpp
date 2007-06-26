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

#include "tableview.h"
#include <interface/interface.h>
#include <wx/wx.h>

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

BEGIN_EVENT_TABLE(CTableView, wxListCtrl)
EVT_LIST_BEGIN_DRAG(LIST_CTRL, CTableView::OnBeginDrag)
EVT_LIST_ITEM_ACTIVATED(LIST_CTRL, CTableView::OnItemSelected)
EVT_LIST_COL_CLICK(LIST_CTRL, CTableView::OnColClick)
EVT_CONTEXT_MENU(CTableView::OnContextMenu)
END_EVENT_TABLE()

// CTableView

void CTableView::OnCacheHint(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnCacheHint" << std::endl;
#endif
}

void CTableView::SetColumnImage(int col, int image)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] SetColumnImage" << std::endl;
#endif
    wxListItem item;
    item.SetMask(wxLIST_MASK_IMAGE);
    item.SetImage(image);
    SetColumn(col, item);
}

void CTableView::OnColClick(wxListEvent& event)
{
    int col = event.GetColumn();
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnColClick" << std::endl;
#endif
    // FIXME : Put a "sort" icon
    static bool x = false;
    x = !x;
    SetColumnImage(col, 4);
    ((CMainFrame*)m_Parent)->OnSortTable(col);
}

void CTableView::OnColRightClick(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnColRightClick" << std::endl;
#endif
    int col = event.GetColumn();
    if ( col != -1 )
    {
        SetColumnImage(col, -1);
    }

    // Show popupmenu at position
    wxMenu menu(wxT("Test"));
    menu.Append(LIST_ABOUT, _T("&About"));
    PopupMenu(&menu, event.GetPoint());
}

void CTableView::OnColDragging(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnColDragging" << std::endl;
#endif
    //LogColEvent( event, wxT("OnColDragging") );
}

void CTableView::OnColEndDrag(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnColEndDrag" << std::endl;
#endif
    //LogColEvent( event, wxT("OnColEndDrag") );
}

void CTableView::OnBeginDrag(wxListEvent& event)
{
    //const wxPoint& pt = event.m_pointDrag;
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnBeginDrag" << std::endl;
#endif
    //int flags;
    //wxLogMessage( wxT("OnBeginDrag at (%d, %d), item %ld."),
    //pt.x, pt.y, HitTest(pt, flags) );
}

void CTableView::OnBeginRDrag(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnBeginRDrag" << std::endl;
#endif
    //wxLogMessage( wxT("OnBeginRDrag at %d,%d."),
    //event.m_pointDrag.x, event.m_pointDrag.y );
}

void CTableView::OnBeginLabelEdit(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnBeginLabelEdit" << std::endl;
#endif
    //wxLogMessage( wxT("OnBeginLabelEdit: %s"), event.m_item.m_text.c_str());
}

void CTableView::OnEndLabelEdit(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnEndLabelEdit" << std::endl;
#endif
    //wxLogMessage( wxT("OnEndLabelEdit: %s"),
    //event.IsEditCancelled() ? _T("[cancelled]")
                                 //: event.m_item.m_text.c_str());
}

void CTableView::OnDeleteItem(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnDeleteItem" << std::endl;
#endif
    //LogEvent(event, _T("OnDeleteItem"));
}

void CTableView::OnDeleteAllItems(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnDeleteAllItems" << std::endl;
#endif
    //LogEvent(event, _T("OnDeleteAllItems"));
}

#if WXWIN_COMPATIBILITY_2_4
void CTableView::OnGetInfo(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnGetInfo" << std::endl;
#endif
    wxString msg;

    msg << _T("OnGetInfo (") << event.m_item.m_itemId << _T(", ") << event.m_item.m_col << _T(")");
    if ( event.m_item.m_mask & wxLIST_MASK_STATE )
        msg << _T(" wxLIST_MASK_STATE");
    if ( event.m_item.m_mask & wxLIST_MASK_TEXT )
        msg << _T(" wxLIST_MASK_TEXT");
    if ( event.m_item.m_mask & wxLIST_MASK_IMAGE )
        msg << _T(" wxLIST_MASK_IMAGE");
    if ( event.m_item.m_mask & wxLIST_MASK_DATA )
        msg << _T(" wxLIST_MASK_DATA");
    if ( event.m_item.m_mask & wxLIST_SET_ITEM )
        msg << _T(" wxLIST_SET_ITEM");
    if ( event.m_item.m_mask & wxLIST_MASK_WIDTH )
        msg << _T(" wxLIST_MASK_WIDTH");
    if ( event.m_item.m_mask & wxLIST_MASK_FORMAT )
        msg << _T(" wxLIST_MASK_WIDTH");

    if ( event.m_item.m_mask & wxLIST_MASK_TEXT )
    {
        event.m_item.m_text = _T("My callback text");
    }

    //wxLogMessage(msg);
}

void CTableView::OnSetInfo(wxListEvent& event)
{
    //LogEvent(event, _T("OnSetInfo"));
}
#endif

void CTableView::OnSelected(wxListEvent& event)
{
    //LogEvent(event, _T("OnSelected"));
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnSelected" << std::endl;
#endif
    if ( GetWindowStyle() & wxLC_REPORT )
    {
        wxListItem info;
        info.m_itemId = event.m_itemIndex;
        info.m_col = 1;
        info.m_mask = wxLIST_MASK_TEXT;
        if ( GetItem(info) )
        {
            //wxLogMessage(wxT("Value of the 2nd field of the selected item: %s"),
            //info.m_text.c_str());
        }
        else
        {
            wxFAIL_MSG(wxT("wxListCtrl::GetItem() failed"));
        }
    }
}

void CTableView::OnDeselected(wxListEvent& event)
{
    //LogEvent(event, _T("OnDeselected"));
}

void CTableView::OnActivated(wxListEvent& event)
{
    //LogEvent(event, _T("OnActivated"));
}

void CTableView::OnFocused(wxListEvent& event)
{
    //LogEvent(event, _T("OnFocused"));

    event.Skip();
}

void CTableView::OnListKeyDown(wxListEvent& event)
{
    long item;
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnListKeyDown" << std::endl;
#endif
    switch ( event.GetKeyCode() )
    {
        case 'c':                // colorize
        case 'C':
        {
            wxListItem info;
            info.m_itemId = event.GetIndex();
            GetItem(info);

            wxListItemAttr *attr = info.GetAttributes();
            if ( !attr || !attr->HasTextColour() )
            {
                info.SetTextColour(*wxCYAN);

                SetItem(info);

                RefreshItem(info.m_itemId);
            }
        }
        break;

        case 'n':                // next
        case 'N':
            item = GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_FOCUSED);
            if ( item++ == GetItemCount() - 1 )
            {
                item = 0;
            }

            wxLogMessage(_T("Focusing item %ld"), item);

            SetItemState(item, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED);
            EnsureVisible(item);
            break;

        case 'r':                // show bounding Rect
        case 'R':
        {
            item = event.GetIndex();
            wxRect r;
            if ( !GetItemRect(item, r) )
            {
                wxLogError(_T("Failed to retrieve rect of item %ld"), item);
                break;
            }

            wxLogMessage(_T("Bounding rect of item %ld is (%d, %d)-(%d, %d)"),
                item, r.x, r.y, r.x + r.width, r.y + r.height);
        }
        break;

        case WXK_DELETE:
            item = GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
            while ( item != -1 )
            {
                DeleteItem(item);

                wxLogMessage(_T("Item %ld deleted"), item);

                // -1 because the indices were shifted by DeleteItem()
                item = GetNextItem(item - 1,
                    wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
            }
            break;

        case WXK_INSERT:
            if ( GetWindowStyle() & wxLC_REPORT )
            {
                if ( GetWindowStyle() & wxLC_VIRTUAL )
                {
                    SetItemCount(GetItemCount() + 1);
                }
                else             // !virtual
                {
                    //InsertTableItem(event.GetIndex());
                }
            }
            //else: fall through

        default:
            LogEvent(event, _T("OnListKeyDown"));

            event.Skip();
    }
}

void CTableView::OnChar(wxKeyEvent& event)
{
    wxLogMessage(_T("Got char event."));

    switch ( event.GetKeyCode() )
    {
        case 'n':
        case 'N':
        case 'c':
        case 'C':
            // these are the keys we process ourselves
            break;

        default:
            event.Skip();
    }
}

void CTableView::LogEvent(const wxListEvent& event, const wxChar *eventName)
{
    wxLogMessage(_T("Item %ld: %s (item text = %s, data = %ld)"),
        event.GetIndex(), eventName,
        event.GetText().c_str(), event.GetData());
}

wxString CTableView::OnGetItemText(long WXUNUSED(item), long WXUNUSED(column)) const
{
    //if ( GetItemCount() == WXSIZEOF(SMALL_VIRTUAL_VIEW_ITEMS) )
    //{
    //return SMALL_VIRTUAL_VIEW_ITEMS[item][column];
    //}
    //else
    //{
    //return wxString::Format(_T("Column %ld of item %ld"), column, item);
    //}
    return wxString(_T("Poulpe"));
}

int CTableView::OnGetItemImage(long WXUNUSED(item)) const
{
    return 0;
}

wxListItemAttr *CTableView::OnGetItemAttr(long item) const
{
    return item % 2 ? NULL : (wxListItemAttr *)&m_attr;
}

void CTableView::InsertTableItem(std::vector<wxString> _list,int index)
{
#if defined VERBOSE
    std::cout << "[DEBUG] [CTableView] InsertTableItem : " ;
    for(int j=0; j<_list.size(); ++j)
    {
        std::cout << _list[j].mb_str() << " ";
    }
    std::cout << std::endl;
    std::cout << "[DEBUG] [CTableView] InsertTableItem : " << index << std::endl;
#endif

    /*static int bob = 0;
    bob=((bob+1)%3);*/
                                 //, bob);
    long tmp = InsertItem(index, _list[0]);
    //SetItemData(tmp, i);

    for(unsigned int i=0; i<_list.size(); ++i)
    {
        /*static int bob2 = 0;
        bob2=((bob2+1)%3);*/
                                 //, bob2);
        SetItem(tmp, i, _list[i]);
    }
}

void CTableView::OnContextMenu(wxContextMenuEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnContextMenu" << std::endl;
#endif
    wxPoint point = event.GetPosition();
    // If from keyboard
    if (point.x == -1 && point.y == -1)
    {
        wxSize size = GetSize();
        point.x = size.x / 2;
        point.y = size.y / 2;
    }
    else
    {
        point = ScreenToClient(point);
    }
    ShowContextMenu(point);
}

void CTableView::ShowContextMenu(const wxPoint& pos)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] ShowContextMenu" << std::endl;
#endif
    wxMenu menu;

    menu.Append(wxID_ABOUT, _T("&About"));
    menu.AppendSeparator();
    menu.Append(wxID_EXIT, _T("E&xit"));

    PopupMenu(&menu, pos.x, pos.y);
}

//WXUNUSED((event)
void CTableView::OnItemSelected(wxListEvent& event)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnItemSelected : Start" << std::endl;
#endif
    long index = event.GetIndex();
    ((CMainFrame*)m_Parent)->OnTableItemSel(index);

#if defined DEBUG
    std::cout << "[DEBUG] [CTableView] OnItemSelected : End" << std::endl;
#endif

}
