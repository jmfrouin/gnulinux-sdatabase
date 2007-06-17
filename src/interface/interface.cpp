#include <vector>
#include <list>
#include <iostream>

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/toolbar.h>
#include <wx/log.h>
#include <wx/filedlg.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/config.h>

#include <interface/edit_dialog.h>
#include <interface/new_table_dialog.h>

#include "interface.h"
#include "def.h"

#if defined LEAK_DETECTOR
    #include <leak/leak_detector.h>
#endif

//XPM that will be used
#include <bitmaps/mondrian.xpm>
#include <bitmaps/small1.xpm>
#include <bitmaps/new.xpm>
#include <bitmaps/open.xpm>
#include <bitmaps/save.xpm>
#include <bitmaps/dvd.xpm>
#include <bitmaps/found.xpm>
#include <bitmaps/sortdown.xpm>
#include <bitmaps/sortup.xpm>

BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
    EVT_MENU (FILE_QUIT, CMainFrame::OnQuit)
	EVT_MENU (FILE_NEW, CMainFrame::OnNew)
    EVT_MENU (FILE_OPEN, CMainFrame::OnOpen)
    EVT_MENU (FILE_SAVE, CMainFrame::OnSave)

    EVT_MENU (EDIT_ADD, CMainFrame::OnAdd)
    EVT_MENU (EDIT_DEL, CMainFrame::OnDel)
    EVT_MENU (EDIT_FIND, CMainFrame::OnFind)
    EVT_MENU (EDIT_CLEANFINDED, CMainFrame::OnClearFinded)

    EVT_MENU (MISC_ABOUT, CMainFrame::OnAbout)
END_EVENT_TABLE ()

//-----------------------------------------------------------------------------------------------
// Constructors & Destructor.
//-----------------------------------------------------------------------------------------------

CMainFrame::CMainFrame(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
:m_imageListNormal(0),m_imageListSmall(0), m_imageListToolbar(0),
/*m_Panel(0)*/m_SplitWindow(0), m_FileExplorer(0), m_TableView(0), m_Manager(0), m_SettingsManager(0),
m_TBShowToolTips(true), m_SmallTB(true)
{
   Create(parent, id, caption, pos, size, style);
}

CMainFrame::~CMainFrame()
{
    if(m_Manager)
    {
        delete m_Manager;
    }

    if(m_SettingsManager)
    {
        delete m_SettingsManager;
    }

    if(m_imageListSmall)
    {
        delete m_imageListSmall;
    }

    if(m_imageListToolbar)
    {
        delete m_imageListToolbar;
    }
}

bool CMainFrame::Create(wxWindow* parent, wxWindowID id, const wxString& caption,
                        const wxPoint& pos, const wxSize& size, long style)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : Adding managers" << std::endl;
#endif

    m_Manager = new CManager();
    m_SettingsManager = new CSettingsManager();

    if(!m_SettingsManager->Construct() || !m_Manager->Construct())
    {
        return FALSE;
    }

#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : wxFrame::Create(...)" << std::endl;
#endif

   wxFrame::Create(parent, id, caption, pos, size, style);
   SetSize(m_SettingsManager->DetermineFrameSize());
   // Give it an icon
   SetIcon( wxICON(mondrian) );

#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : Adding image" << std::endl;
#endif

    //m_imageListNormal = new wxImageList(32, 32, true);
    m_imageListSmall = new wxImageList(16, 16, true);
    m_imageListSmall->Add(wxIcon(dvd_xpm));
    m_imageListSmall->Add(wxIcon(found_xpm));
    m_imageListSmall->Add(wxIcon(open_xpm));
    m_imageListSmall->Add(wxIcon(sortdown_xpm));
    m_imageListSmall->Add(wxIcon(sortup_xpm));

#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : Adding menu " << std::endl;
#endif

    // Add menu
    wxMenu *menuFile = new wxMenu;
	menuFile->Append(FILE_NEW, _T("&New\tCtrl-n"));
	menuFile->AppendSeparator();
    menuFile->Append(FILE_OPEN, _T("&Open\tCtrl-o"));
    menuFile->Append(FILE_SAVE, _T("&Save\tCtrl-s"));
    menuFile->AppendSeparator();
    menuFile->Append(FILE_QUIT, _T("E&xit\tCtrl-q"));
    //Edit menu
    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append(EDIT_ADD, _T("&Add\tCtrl-a"));
    menuEdit->Append(EDIT_DEL, _T("&Delete\tCtrl-d"));
    menuEdit->AppendSeparator();
    menuEdit->Append(EDIT_FIND, _T("&Find\tCtrl-f"));
    menuEdit->Append(EDIT_CLEANFINDED, _T("&Clear finded marks\tCtrl-c"));
    //Misc menu
    wxMenu *menuMisc = new wxMenu;
    menuMisc->Append(MISC_ABOUT, _T("&About"));

    wxMenuBar *menubar = new wxMenuBar;
    menubar->Append(menuFile, _T("&File"));
    menubar->Append(menuEdit, _T("&Edit"));
    menubar->Append(menuMisc, _T("&Misc"));
    SetMenuBar(menubar);

#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : Adding panel" << std::endl;
#endif

	m_SplitWindow = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxSP_NO_XP_THEME|wxNO_BORDER );
	m_SplitWindow->SetMinimumPaneSize(0);
	m_FileExplorer = new CFileExplorer(this, m_SplitWindow, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
	m_TableView = new CTableView(this, m_SplitWindow, LIST_CTRL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT | wxSUNKEN_BORDER | wxLC_HRULES);
	m_SplitWindow->SplitVertically(m_FileExplorer, m_TableView, 200);


#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Create(...) : CreateStatusBar" << std::endl;
#endif

    //We create 3 StatusBar boxes
    CreateStatusBar(3);

    //Now add a toolbar
    m_ToolbarPos = TOOLBAR_TOP;
    // Create the toolbar
    RecreateToolbar();

   return TRUE;
}

//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Misc.
//-----------------------------------------------------------------------------------------------

void CMainFrame::StoreFrameSize (wxRect rect)
{
    m_SettingsManager->StoreFrameSize(rect);
}

//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Callbacks
//-----------------------------------------------------------------------------------------------

void CMainFrame::OnQuit (wxCommandEvent& WXUNUSED(event))
{
    StoreFrameSize(GetRect ());
    Close(true);
}

void CMainFrame::OnSave (wxCommandEvent& WXUNUSED(event))
{
    m_Manager->WriteFile();
}

void CMainFrame::OnNew (wxCommandEvent& WXUNUSED(event))
{
	CNewTableDialog _dialog(this);

	if (_dialog.ShowModal() == wxID_OK)
	{
		m_TableView->ClearAll();
	}

}

void CMainFrame::OnOpen (wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog dialog(this, _T("Please select a SDatabase file"), wxEmptyString, wxEmptyString, _T("csv (Comma Separated Value) files (*.csv)|*.csv"));

    dialog.SetDirectory(wxGetHomeDir());
    dialog.CentreOnParent();

    if (dialog.ShowModal() == wxID_OK)
    {
        OnOpenFile(dialog.GetPath());
    }
}

void CMainFrame::OnAbout (wxCommandEvent& WXUNUSED(event))
{
    wxMessageDialog dialog(this, _T("A simple database CManager\nJean-Michel Frouin (c) 2007"), wxT("About"), wxOK|wxCANCEL);
    dialog.ShowModal();
}

void CMainFrame::OnAdd (wxCommandEvent& WXUNUSED(event))
{
    TTuple temp;

    for(int i = 0; i < m_Manager->GetCols(); ++i)
    {
        temp.push_back(wxT(""));
    }

    CEditDialog _dialog(this, m_Manager->GetTitles(), temp, wxT("Add a new line"));

    if(_dialog.ShowModal()==wxID_OK)
    {
		bool Record = false;
		for(unsigned int i=0; i<temp.size(); ++i)
		{
			if(!temp[i].empty())
			{
				Record = true;
				break;
			}
		}

		if(Record)
		{
			m_Manager->Append(temp);
			RecreateList(wxLC_REPORT | wxLC_SINGLE_SEL);
		}
    }

}

void CMainFrame::OnDel (wxCommandEvent& WXUNUSED(event))
{
    wxMessageDialog dialog(this, _T("A simple database CManager\nJean-Michel Frouin (c) 2007"), wxT("About"), wxOK|wxCANCEL);
    dialog.ShowModal();
}


void CMainFrame::OnClearFinded (wxCommandEvent& WXUNUSED(event))
{
    for(int i = 0; i < m_Manager->GetRows(); ++i)
    {
        for(int j = 0; j < m_Manager->GetCols(); ++j)
        {
            wxListItem info;
            info.SetImage(-1);
            info.SetId(i);
            info.SetColumn(j);
            m_TableView->SetItem(info);
        }
    }
}

//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Tableview callbacks
//-----------------------------------------------------------------------------------------------

void CMainFrame::OnTableItemSel(int index)
{
#if defined DEBUG
    std::cout << "[DEBUG] [INTERFACE:CMAINFRAME] [OnTableItemSel(int index)] Start" << std::endl;
#endif

    TTable::iterator it = m_Manager->GetTable()->begin();

    for(int i = 0; i < index ;++i)
    {
        ++it;
    }

    CEditDialog _dialog(this, m_Manager->GetTitles(), (*it), wxT("Edit line"));

    if(_dialog.ShowModal()==wxID_OK)
    {
        m_TableView->Hide();
        m_TableView->DeleteItem(index);
        m_TableView->InsertTableItem((*it), index);
        m_TableView->Show();
    }

#if defined DEBUG
    std::cout << "[DEBUG] [INTERFACE:CMAINFRAME] [OnTableItemSel(int index)] End" << std::endl;
#endif
}

void CMainFrame::OnSortTable(int index)
{
    static int lastindex = 0;
    static bool mode = true;

    if(lastindex == index)
    {
        mode = !mode;
    }
    else
    {
        mode = true;
        lastindex = index;
    }

    m_Manager->SortTable(index, mode);
    RecreateList(wxLC_REPORT | wxLC_SINGLE_SEL);
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// CFileExplorer callback
//-----------------------------------------------------------------------------------------------

void CMainFrame::OnOpenFile(wxString _filename)
{
	if(m_Manager->OpenFile(_filename))
	{
		RecreateList(wxLC_REPORT | wxLC_SINGLE_SEL);
	}
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Find dialog managment
//-----------------------------------------------------------------------------------------------

void CMainFrame::OnFind( wxCommandEvent& WXUNUSED(event) )
{
    CFindDialog _dialog(this, m_SettingsManager->LoadFindBookmarkSettings(), m_SettingsManager->LoadFindReverseSettings());
    _dialog.ShowModal();
}

void CMainFrame::Find(const wxString _search, bool _bookmarks, bool _reverse)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CMainFrame] Find" << _search.mb_str() << std::endl;
#endif
    m_SettingsManager->StoreFindSettings(_reverse, _bookmarks);

	int _col, _row;
    
	if(m_Manager->Find(_search, _col, _row, true, _reverse))
    {
        if(_bookmarks)
        {
            //Create image for the founded item
            wxListItem info;
            //We used image 1 for bookmark
            info.SetImage(1);
            info.SetId(_row);
            info.SetColumn(_col);
            m_TableView->SetItem(info);
        }
        m_TableView->SetItemState(_row, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED);
        m_TableView->SetItemState(_row, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
        m_TableView->EnsureVisible(_row);
    }
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Recreate base list
//-----------------------------------------------------------------------------------------------

void CMainFrame::RecreateList(long flags)
{
    // we could avoid recreating it if we don't set/clear the wxLC_VIRTUAL
    // style, but it is more trouble to do it than not
#if 0
    if ( !m_TableView || ((flags & wxLC_VIRTUAL) !=
            (m_TableView->GetWindowStyleFlag() & wxLC_VIRTUAL)) )
#endif
    {
		m_TableView->ClearAll();
		
		switch ( flags & wxLC_MASK_TYPE )
        {
            case wxLC_LIST:
                //InitWithListItems();
                break;

            case wxLC_ICON:
                //InitWithIconItems(withText);
                break;

            case wxLC_SMALL_ICON:
                //InitWithIconItems(withText, true);
                break;

            case wxLC_REPORT:
                InitList();
                break;

            default:
                wxFAIL_MSG( _T("unknown listctrl mode") );
        }
    }

    UpdateStatusBar();
}

void CMainFrame::InitList()
{
    m_TableView->SetImageList(m_imageListSmall, wxIMAGE_LIST_SMALL);
    std::vector<wxString> temp = m_Manager->GetTitles();
    wxListItem itemCol;

    this->SetStatusText(_T("Loading file ... please wait"),0);

    for(unsigned int i=0; i<temp.size(); ++i)
    {
        itemCol.SetText(temp[i]);
        itemCol.SetAlign(wxLIST_FORMAT_CENTRE);
        itemCol.SetImage(-1);
        m_TableView->InsertColumn(i, itemCol);
    }

    // to speed up inserting we hide the control temporarily
    m_TableView->Hide();

    typedef std::vector<wxString> TTuple;
    typedef std::list<TTuple> TTable;

    TTable::iterator it;

    int j=0;
    for (it = m_Manager->GetTable()->begin(); it != m_Manager->GetTable()->end(); ++it)
    {
        m_TableView->InsertTableItem((*it), j++);
    }

    m_TableView->Show();

    m_TableView->SetTextColour(*wxBLUE);
    m_TableView->SetBackgroundColour(*wxLIGHT_GREY);

    for(unsigned int i=0; i<temp.size(); ++i)
    {
        m_TableView->SetColumnWidth( i, wxLIST_AUTOSIZE );
    }
}
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
void CMainFrame::UpdateStatusBar ()
{
    this->SetStatusText(APP_NAME,0);
    this->SetStatusText(_T("File : ") + m_Manager->GetFilename(),1);
    this->SetStatusText(wxString().Format(_T("Records : %d "),m_Manager->GetRows()),2);
}

void CMainFrame::RecreateToolbar ()
{
    // delete and recreate the toolbar
    wxToolBarBase *toolBar = GetToolBar();
    long style = toolBar ? toolBar->GetWindowStyle() : TOOLBAR_STYLE;
    delete toolBar;

    SetToolBar(NULL);

    style &= ~(wxTB_HORIZONTAL | wxTB_VERTICAL | wxTB_BOTTOM | wxTB_RIGHT | wxTB_HORZ_LAYOUT);

    switch( m_ToolbarPos )
    {
    case TOOLBAR_LEFT:
        style |= wxTB_LEFT;
        break;
    case TOOLBAR_TOP:
        style |= wxTB_TOP;
        break;
    case TOOLBAR_RIGHT:
        style |= wxTB_RIGHT;
        break;
    case TOOLBAR_BOTTOM:
        style |= wxTB_BOTTOM;
        break;
    }

    if (m_TBShowToolTips)
        style &= ~wxTB_NO_TOOLTIPS;
    else
        style |= wxTB_NO_TOOLTIPS;

    toolBar = CreateToolBar(style, ID_TOOLBAR);

    // Set up toolbar
    enum
    {
        TB_new,
        TB_open,
        TB_save,
        TB_Max
    };

    //wxBitmap toolBarBitmaps[TB_Max];

    m_imageListToolbar = new wxImageList(16, 16, true);

    #define INIT_TOOL(file) \
        m_imageListToolbar->Add(wxIcon(file##_xpm));

    INIT_TOOL(new);
    INIT_TOOL(open);
    INIT_TOOL(save);

//#define INIT_TOOL_BMP(bmp) \
//    toolBarBitmaps[TB_##bmp] = wxBitmap(bmp##_xpm)
//
//    INIT_TOOL_BMP(new);
//    INIT_TOOL_BMP(open);

    int w = m_imageListToolbar->GetBitmap(TB_new).GetWidth(),
        h = m_imageListToolbar->GetBitmap(TB_new).GetHeight();

    // If user want a small TB we need to resize ToolBar Bitmaps
    if ( !m_SmallTB )
    {
        w *= 2;
        h *= 2;

        for ( size_t n = TB_new; n < TB_Max; ++n )
        {
            m_imageListToolbar->GetBitmap(n).ConvertToImage().Scale(w, h);
        }
    }

    toolBar->SetToolBitmapSize(wxSize(w, h));

    toolBar->AddTool(FILE_NEW, _T("New"), m_imageListToolbar->GetBitmap(TB_new), wxNullBitmap, wxITEM_NORMAL,
        _T("New base"), _T("Create a new database"));
    toolBar->AddTool(FILE_OPEN, _T("Open"), m_imageListToolbar->GetBitmap(TB_open), wxNullBitmap, wxITEM_NORMAL,
        _T("Open base"), _T("Open a database"));
    toolBar->AddSeparator();

    // the generic toolbar doesn't really support this
#if wxUSE_TOOLBAR_NATIVE && !defined(__WXX11__) || defined(__WXUNIVERSAL__)
    // Disable last base combobox for vertical toolbar :)
    if ( !( toolBar->IsVertical() ) )
    {
        wxComboBox *combo = new wxComboBox(toolBar, ID_COMBO, wxEmptyString,
            wxDefaultPosition, wxSize(200,wxDefaultCoord) );
        combo->Append(_T("F:\\Films.csv"));
        combo->Append(_T("C:\\poulpe.csv"));
        toolBar->AddControl(combo);

        //wxSpinCtrl *spin = new wxSpinCtrl( toolBar, ID_SPIN, wxT("0"), wxDefaultPosition, wxSize(80,wxDefaultCoord), 0, 100, 0 );
        //toolBar->AddControl( spin );
    }
#endif

    toolBar->Realize();
    toolBar->SetRows(!(toolBar->IsVertical()) ? 1 : 10);
}

//-----------------------------------------------------------------------------------------------
