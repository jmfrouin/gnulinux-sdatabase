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

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <wx/splitter.h>

#include <engine/manager.h>
#include <engine/settings_manager.h>
#include <interface/tableview.h>
#include <interface/file_explorer.h>
#include <interface/find_dialog.h>
#include <def.h>

/*!
 * @brief The UI of sdatabase derived from wxFrame
 */
class CMainFrame: public wxFrame
{
	public:
		/*!
		 * @brief Default constructor.
		 * @param parent A pointer on parent wxWindow.
		 * @param id ID of this UI.
		 * @param caption Caption of sdatabase set by default on APP_NAME
		 * @param pos Position of sdatabase.
		 * @param size Size of sdatabase.
		 * @param style Style of sdatabase by default set to wxDEFAULT_FRAME_STYLE.
		 */
		CMainFrame (wxWindow* parent, wxWindowID id = -1,
			const wxString& caption = APP_NAME,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxDEFAULT_FRAME_STYLE);
		/*!
		 * @brief Destructor.
		 */
		~CMainFrame();
		/*!
		 * @brief 2nd constructor.
		 * @note Never called by user.
		 * @param parent A pointer on parent wxWindow.
		 * @param id ID of this UI.
		 * @param caption Caption of sdatabase set by default on APP_NAME
		 * @param pos Position of sdatabase.
		 * @param size Size of sdatabase.
		 * @param style Style of sdatabase by default set to wxDEFAULT_FRAME_STYLE.
		 */
		bool Create (wxWindow* parent, wxWindowID id = -1,
			const wxString& caption = APP_NAME,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxDEFAULT_FRAME_STYLE);

		/* void DoSize ();*/

	private:
		/*!
		 * @brief This function is called when sdatabase quit in order to save pos and size.
		 */
		void StoreFrameSize (wxRect rect);
		/*!
		 * @brief Recreate list of CTableview.
		 * @param flags Flags which change RecreateList execution.
		 */
		void RecreateList(long flags);
		/*!
		 * @brief Initialise list of CTableview.
		 */
		void InitList();
		/*!
		 * @brief Recreate the sdatabase's Toolbar.
		 */
		void RecreateToolbar();
		/*!
		 * @brief Update sdatabase's status bar.
		 */
		void UpdateStatusBar();

	protected:
		/*!
		 * @brief wxCallbacks called when Quit is selected.
		 * @note From File menu
		 */
		void OnQuit (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when New is selected.
		 * @note From File menu
		 */
		void OnNew (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when Open is selected.
		 * @note From File menu
		 */
		void OnOpen (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when Save is selected.
		 * @note From File menu
		 */
		void OnSave (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when About is selected.
		 * @note From Misc menu
		 */
		void OnAbout (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when Add is selected.
		 * @note From Edit menu
		 */
		void OnAdd (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when Del is selected.
		 * @note From Edit menu
		 */
		void OnDel (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when Find is selected.
		 * @note From Edit menu
		 */
		void OnFind (wxCommandEvent& event);
		/*!
		 * @brief wxCallbacks called when ClearFinded is selected.
		 * @note From Edit menu
		 */
		void OnClearFinded (wxCommandEvent& event);

	public:
		/*!
		 * @brief Call when an item is selected in CTableView.
		 * @note CTableview callback.
		 * @param index The index of currently selected item.
		 */
		void OnTableItemSel(int index);
		/*!
		 * @brief Call when user click on a column in CTableView in order to sort it.
		 * @note CTableview callback.
		 * @param index The index of currently selected column.
		 */
		void OnSortTable(int index);
		/*!
		 * @brief Call when user click on a item in CFileExplorer in order to open it.
		 * @note CFileExplorer callback.
		 * @param _filename The filename of opened file.
		 */
		void OnOpenFile(wxString _filename);

		/*!
		 * @brief Call when user have fill the Find dialog.
		 * @note CFindDialog callback.
		 * @param _search The string to search.
		 * @param _bookmark If true, bookmark result.
		 * @param _reverse If true, do a reverse search (from bottom to top).
		 */
		void Find(const wxString _search, bool _bookmarks = false, bool _reverse = false);

	private:

		wxImageList*            m_imageListNormal;
		wxImageList*            m_imageListToolbar;
		wxImageList*            m_imageListSmall;

		wxSplitterWindow*       m_SplitWindow;
		CFileExplorer*          m_FileExplorer;
		CTableView *            m_TableView;
		CManager*               m_Manager;
		CSettingsManager*       m_SettingsManager;

		//Toolbar stuff
		Toolbar_Positions        m_ToolbarPos;
		bool                    m_TBShowToolTips;
		bool                    m_SmallTB;

		DECLARE_NO_COPY_CLASS(CMainFrame)
			DECLARE_EVENT_TABLE()
};
#endif							 // _INTERFACE_H_
