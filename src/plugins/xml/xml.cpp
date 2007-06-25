#include <iostream>
#include <plugins/plugin_initializer.h>
#include "xml.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CxmlPlugin::CxmlPlugin()
{
	setName("CxmlPlugin");
}

CxmlPlugin::~CxmlPlugin()
{
}

bool CxmlPlugin::Write(const std::string& _path)
{
	bool l_ret = false;

	return l_ret;
}

CPluginInitializer<CxmlPlugin> g_xml;
