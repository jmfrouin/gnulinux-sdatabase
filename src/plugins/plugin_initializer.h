#ifndef _PLUGIN_INITIALIZER_H_
#define _PLUGIN_INITIALIZER_H_

#include <config.h>
#include <iostream>

#include "plugin_manager.h"

template <class T>
class CPluginInitializer
{
	public:
		CPluginInitializer()
		{
			CPluginManager* l_pfm = CPluginManager::instance();
			T* l_obj = new T;
			l_pfm->add(l_obj);
		}
};

#endif 	//_PLUGIN_INITIALIZER_H_
