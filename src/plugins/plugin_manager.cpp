#include <dlfcn.h>	///In order to load dyn lib
#include <dirent.h>	///For path manipulation
#include <iostream>
#include <string>

#include "plugin_manager.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CPluginManager* CPluginManager::m_Singleton = 0;

CPluginManager::~CPluginManager()
{
	std::cout << "STOPPPPPP" << '\n';
	std::map<std::string, IPlugin*>::iterator _it;
	for(_it = m_PluginsList.begin(); _it != m_PluginsList.end(); ++_it)
	{
		std::cout << (*_it).first << '\n';
	}
}

CPluginManager* CPluginManager::instance()
{
	if (m_Singleton == 0)
	{	
		m_Singleton = new CPluginManager;
	}
	return m_Singleton;
}

void CPluginManager::stop()
{
	delete m_Singleton;
}

int CPluginManager::loadPlugins(const std::string& path)
{
	struct dirent** namelist;
	int l_res = 0;
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
				std::cout << " " << tmp << " loaded ! " << std::endl;
				l_res++;
			}
			else
			{
				std::cerr << "ERR : " << dlerror() << std::endl;
			}
		}
	}
	std::cout << l_res << '\n';
	return l_res;
}

void CPluginManager::add(IPlugin* _toadd)
{
	m_PluginsList.insert(make_pair(_toadd->getName(), _toadd));	
}

std::string CPluginManager::Wildcard()
{
	std::string l_ret;

	std::map<std::string, IPlugin*>::iterator _it;
	for(_it = m_PluginsList.begin(); _it != m_PluginsList.end(); ++_it)
	{
		l_ret.append(((*_it).second)->Wildcard());
		l_ret.append("|");
	}

	return l_ret;
}
