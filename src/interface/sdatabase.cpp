/*
 * @brief :      Main application
 * @author :     Jean-Michel Frouin
 * @date :       02/01/2007
 */
#include <iostream>
#include <wx/wx.h>
#include <performance/performance_analysis.h>
#include <def.h>

#include "interface.h"
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
	CMainFrame* _main = new CMainFrame(NULL);
	_main->Show(true);

	g_pa->EndTiming();
	return true;
}
