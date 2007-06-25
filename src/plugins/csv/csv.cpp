#include <iostream>
#include <plugins/plugin_initializer.h>
#include "csv.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CcsvPlugin::CcsvPlugin()
{
	setName("CcsvPlugin");
}

CcsvPlugin::~CcsvPlugin()
{
}

bool CcsvPlugin::Write()
{
	bool l_ret = false;

	return l_ret;
}

CPluginInitializer<CcsvPlugin> g_csv;
