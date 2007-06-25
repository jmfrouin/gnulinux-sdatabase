#ifndef _PLUGIN_FACTORY_MANAGER_H_
#define _PLUGIN_FACTORY_MANAGER_H_

#include <config.h>
#include <map>
#include <string>

#include "plugin_factory.h"

/*!
*@brief Common source code of all plugins.
*@note This code will be put in a dynamic library (libmanager.so).
*/
class PluginFactoryManager
{
	public:
		~PluginFactoryManager();

		///Grab the singleton instance
		static PluginFactoryManager* instance();	

		/*!
		*@brief Load all available plugins. 
		*@return Number of plugins founded.
		*/
		int loadPlugins (const std::string& path);
		Plugin* createObject (const std::string& name);
	
	private:
		PluginFactoryManager(){};

	public:
		std::map<std::string, PluginFactory*> factories;

	private:
		static PluginFactoryManager* 	m_Singleton; 	///< The singleton itself
};
#endif 	//_PLUGIN_FACTORY_MANAGER_H_
