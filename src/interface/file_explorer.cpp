#include <interface/interface.h>

#include "file_explorer.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

BEGIN_EVENT_TABLE(CFileExplorer, wxGenericDirCtrl)
	EVT_TREE_ITEM_ACTIVATED(wxID_ANY, CFileExplorer::OnSel)
END_EVENT_TABLE ()

void CFileExplorer::OnSel(wxTreeEvent& event)
{
	((CMainFrame*)m_Parent)->OnOpenFile(GetFilePath());
}
