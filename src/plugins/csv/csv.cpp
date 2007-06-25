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

bool CcsvPlugin::Write(const std::string& _path)
{
	bool l_ret = false;

	return l_ret;
}

std::string CcsvPlugin::Wildcard()
{
	return "csv (Comma Separated Value) files (*.csv)|*.csv";
}

CPluginInitializer<CcsvPlugin> g_csv;
