#ifndef _PLUGIN_FACTORY_H_
#define _PLUGIN_FACTORY_H_

#include <config.h>
#include <string>
#include "plugin_interface.h"

/**
 * @brief Plugin Factory Interface
 */
class PluginFactory
{
	public:
		/*!
		 * @brief dtor.
		 */
		virtual ~PluginFactory(){}

		/*!
		 * @brief Get name.
		 * @note Can be replaced by a CName heritage.
		 */
		virtual std::string getName() = 0;
		virtual Plugin* createInstance() = 0; 
};
#endif 	//_PLUGIN_FACTORY_H_
