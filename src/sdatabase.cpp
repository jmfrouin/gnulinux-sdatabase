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
 * @brief :      Main application
 * @author :     Jean-Michel Frouin
 * @date :       02/01/2007
 */
#include <iostream>
#include <wx/wx.h>
#include <performance/performance_analysis.h>
#include <config.h>

#include <interface/interface.h>
#include <plugins/plugin_manager.h>
#include "sdatabase.h"

IMPLEMENT_APP(SDatabase)

#include <leak/memory_manager.h>

CPerformanceAnalysis* g_pa;
CMemoryManager g_mm;

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

SDatabase::SDatabase() : wxApp()
{
	g_pa = new CPerformanceAnalysis();
}

SDatabase::~SDatabase()
{
	std::cout << "~SDatabase()" << std::endl;
	CPluginManager* l_pfm = CPluginManager::instance();
	l_pfm->stop();
	delete g_pa;
}

bool SDatabase::OnInit()
{
	//Performance analysis
	g_pa->AddFunction("bool SDatabase::OnInit()");
	g_pa->StartTiming();

	wxApp::OnInit();
	SetAppName (APP_NAME);
	SetVendorName (APP_VENDOR);
	CMainFrame* l_Main = new CMainFrame(NULL);
	__loadPlugins("plugins");
	l_Main->Show(true);
	g_pa->EndTiming();
	return true;
}

bool SDatabase::__loadPlugins(const std::string& _path)
{
	bool l_ret = false;
	CPluginManager* l_pfm = CPluginManager::instance();
	l_ret = l_pfm->loadPlugins(_path);
	return l_ret;
}
