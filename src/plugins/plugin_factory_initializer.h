#ifndef _PLUGIN_FACTORY_INITIALIZER_H_
#define _PLUGIN_FACTORY_INITIALIZER_H_

#include <config.h>
#include <iostream>
#include "plugin_factory_manager.h"

	template <class T>
	class PluginFactoryInitializer
	{
		public:
			PluginFactoryInitializer(const CString& _path)
			{
				if(CSApi::Instance())
				{
					T* l_fact = new T;
					std::cout << "[DBG] Adding factory : " << _path << " named " << l_fact->getName() << '\n';
					CDirectory<CFactory>::instance()->addObject(l_fact, _path);
				}
			}
	};

#endif 	//_PLUGIN_FACTORY_INITIALIZER_H_
