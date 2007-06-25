#ifndef _PLUGIN_INITIALIZER_H_
#define _PLUGIN_INITIALIZER_H_

#include <config.h>
#include <iostream>

template <class T>
class CPluginInitializer
{
	public:
		CPluginInitializer()
		{
			T* l_obj = new T;
		}
};

#endif 	//_PLUGIN_INITIALIZER_H_
