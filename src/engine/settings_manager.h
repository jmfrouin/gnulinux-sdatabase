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

#ifndef _SETTINGS_MANAGER_H_
#define _SETTINGS_MANAGER_H_

#include <wx/config.h>
#include <wx/wx.h>

#include <vector>

/*!
 * @brief A settings manager.
 */
class CSettingsManager
{
	public:
		/*!
		 * @brief Default constructor.
		 */
		CSettingsManager();
		/*!
		 * @brief 2nd constructor.
		 */
		int Construct();
		/*!
		 * @brief Destructor.
		 */
		virtual ~CSettingsManager();

		/*!
		 * @brief Store frame size and pos on clean exit (Quit from menu or CTRL+Q).
		 * @param	rect The current sdatabase size and pos.
		 */
		void StoreFrameSize(wxRect rect);
		/*!
		 * @brief Retrieve frame size and pos on startup.
		 */
		wxRect DetermineFrameSize ();

		/*!
		 * @brief Store find settings.
		 * @param	_reverse	True, if reverse if selected from Find dialog.
		 * @param	_bookmark	True, if bookmark if selected from Find dialog.
		 */
		void StoreFindSettings(bool _reverse, bool _bookmark);
		/*!
		 * @brief Load bookmark setting for Find dialog.
		 * @todo	Remove the s at the end of name
		 */
		bool LoadFindBookmarkSettings();
		/*!
		 * @brief Load reverse setting for Find dialog.
		 * @todo	Remove the s at the end of name
		 */
		bool LoadFindReverseSettings();

	private:
		wxConfig* m_Config;
};
#endif							 // _SETTINGS_MANAGER_H_
