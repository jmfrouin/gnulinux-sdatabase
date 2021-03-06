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

#include "settings_manager.h"
#include <config.h>

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

CSettingsManager::CSettingsManager():
m_Config(0)
{
#if defined DEBUG
    std::cout << "[DEBUG] [CSettingsManager] CSettingsManager()" << std::endl;
#endif
}

int CSettingsManager::Construct()
{
#if defined DEBUG
    std::cout << "[DEBUG] [CSettingsManager] Construct()" << std::endl;
#endif
    m_Config = new wxConfig (APP_NAME);
    if(!m_Config)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

CSettingsManager::~CSettingsManager()
{
    if(m_Config)
    {
        delete m_Config;
    }
}

void CSettingsManager::StoreFrameSize(wxRect rect)
{
    // store size
    wxString key = LOCATION + wxString("0");
    m_Config->Write (key + wxT("/") + LOCATION_X, rect.x);
    m_Config->Write (key + wxT("/") + LOCATION_Y, rect.y);
    m_Config->Write (key + wxT("/") + LOCATION_W, rect.width);
    m_Config->Write (key + wxT("/") + LOCATION_H, rect.height);
}

// From : http://wyoguide.sourceforge.net/guidelines/content.html
wxRect CSettingsManager::DetermineFrameSize ()
{
    const int minFrameWidth = 80;
    const int minFrameHight = 80;
    wxSize scr = wxGetDisplaySize();

    wxRect rect;

    wxString key = LOCATION + wxString("0");
    if (m_Config->Exists (key))
    {
        rect.x = m_Config->Read (key + _T("/") + LOCATION_X, rect.x);
        rect.y = m_Config->Read (key + _T("/") + LOCATION_Y, rect.y);
        rect.width = m_Config->Read (key + _T("/") + LOCATION_W, rect.width);
        rect.height = m_Config->Read (key + _T("/") + LOCATION_H, rect.height);
    }

    // check for reasonable values (within screen)
    rect.x = wxMin (abs (rect.x), (scr.x - minFrameWidth));
    rect.y = wxMin (abs (rect.y), (scr.y - minFrameHight));
    rect.width = wxMax (abs (rect.width), (minFrameWidth));
    rect.width = wxMin (abs (rect.width), (scr.x - rect.x));
    rect.height = wxMax (abs (rect.height), (minFrameHight));
    rect.height = wxMin (abs (rect.height), (scr.y - rect.y));

    return rect;
}

// Find settings
void CSettingsManager::StoreFindSettings(bool _reverse, bool _bookmark)
{
    wxString key = LOCATION + wxString("0");
    m_Config->Write (key + wxT("/") + FIND_REVERSE, _reverse);
    m_Config->Write (key + wxT("/") + FIND_BOOKMARK, _bookmark);

#if defined DEBUG
    std::cout << "[DEBUG] [CSettingsManager] StoreFindSettings(...)" << std::endl;
    std::cout << "Reverse : " << _reverse << std::endl;
    std::cout << "Bookmark : " << _bookmark << std::endl;
#endif
}

bool CSettingsManager::LoadFindBookmarkSettings()
{
    bool l_Bookmark = false;

    wxString key = LOCATION + wxString("0");
    m_Config->Read (key + _T("/") + FIND_BOOKMARK, l_Bookmark);

#if defined DEBUG
    std::cout << "[DEBUG] [CSettingsManager] LoadFindSettings()" << std::endl;
    std::cout << "Bookmark : " << l_Bookmark << std::endl;
#endif

    return l_Bookmark;
}

bool CSettingsManager::LoadFindReverseSettings()
{
    bool l_Reverse = false;

    wxString key = LOCATION + wxString("0");
    m_Config->Read (key + _T("/") + FIND_REVERSE, l_Reverse);

#if defined DEBUG
    std::cout << "[DEBUG] [CSettingsManager] LoadFindSettings()" << std::endl;
    std::cout << "Reverse : " << l_Reverse << std::endl;
#endif

    return l_Reverse;
}
