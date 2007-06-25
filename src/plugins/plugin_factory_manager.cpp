#include <dlfcn.h>	///In order to load dyn lib
#include <dirent.h>	///For path manipulation
#include <iostream>
#include <string>

#include "plugin_interface.h"
#include "plugin_factory_manager.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

PluginFactoryManager* PluginFactoryManager::m_Singleton = 0;

PluginFactoryManager::~PluginFactoryManager()
{
	
}

PluginFactoryManager* PluginFactoryManager::instance()
{
	if (m_Singleton == 0)
	{	
		m_Singleton = new PluginFactoryManager;
	}
	return m_Singleton;
}

int PluginFactoryManager::loadPlugins(const std::string& path)
{
	struct dirent** namelist;
	int res = 0;
	int n = scandir(path.c_str(), &namelist, 0, alphasort);
	while (n-- > 0)
	{
		std::string tmp = path;
		tmp += "/";
		tmp += namelist[n]->d_name;

		if (tmp.length() > 8)
		{
			void* handler = dlopen (tmp.c_str(), RTLD_NOW);
			if (handler != 0)
			{
#if defined DEBUG
				std::cout << " " << tmp << " loaded ! " << std::endl;
#endif
				res++;
			}
			else
			{
				std::cerr << "ERR : " << dlerror() << std::endl;
			}
		}
	}
	return res;
}

Plugin* PluginFactoryManager::createObject(const std::string& name)
{
	if (factories.find(name) != factories.end())
	{
		PluginFactory* fact = factories[name];
		return fact->createInstance();
	}
	return 0;
}

