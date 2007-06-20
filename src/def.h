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

/*
 * @brief :      Commons definition file
 * @author :     Jean-Michel Frouin
 * @date :       09/01/2007
 */

#ifndef _DEF_H_
#define _DEF_H_

#include <wx/toolbar.h>
#include <list>
#include <vector>

//General app infos
#define MAJOR 0
#define MINOR 4
#define BUG 0
#define t(u) #u
#define VERSION(M,m,b) t(M) "." t(m) "." t(b)
#define VER VERSION(MAJOR,MINOR,BUG)

const wxString APP_NAME = _T("SDatabase v0.32");
const wxString APP_VENDOR = _T("JMFSoft");

//Frame size & location infos
const wxString LOCATION = _T("SDatabase");
const wxString LOCATION_X = _T("xpos");
const wxString LOCATION_Y = _T("ypos");
const wxString LOCATION_W = _T("width");
const wxString LOCATION_H = _T("height");

//Find dialog settings
const wxString FIND_REVERSE = wxT("FIND_REVERSE");
const wxString FIND_BOOKMARK = wxT("FIND_BOOKMARK");

enum
{
	LIST_ABOUT = wxID_ABOUT,

	//Menu enums
	MISC_ABOUT = wxID_ABOUT,
	FILE_QUIT = wxID_EXIT,
	FILE_OPEN = wxID_HIGHEST,
	FILE_NEW,
	FILE_SAVE,

	EDIT_ADD,
	EDIT_DEL,
	EDIT_FIND,
	EDIT_CLEANFINDED,

	ID_TOOLBAR,
	ID_COMBO,

	DIALOG_FIND,
	LIST_CTRL,

	//Find dialog
	ID_FIND,

};

//Toolbar enums
enum Toolbar_Positions
{
	TOOLBAR_LEFT,
	TOOLBAR_TOP,
	TOOLBAR_RIGHT,
	TOOLBAR_BOTTOM
};

static const long TOOLBAR_STYLE = wxTB_FLAT | wxTB_DOCKABLE | wxTB_TEXT;

typedef std::vector<wxString> TTuple;
typedef std::list<TTuple> TTable;
#endif							 // _DEF_H_
