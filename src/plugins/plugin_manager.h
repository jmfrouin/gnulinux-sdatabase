#ifndef _PLUGIN_MANAGER_H_
#define _PLUGIN_MANAGER_H_

#include <config.h>
#include <map>
#include <string>
#include "iplugin.h"

/*!
*@brief Common source code of all plugins.
*@note This code will be put in a dynamic library (libmanager.so).
*/
class CPluginManager
{
	public:
		/*!
		* @brief Grab the singleton instance.
		*/
		static CPluginManager* instance();	

		/*!
		* @brief Stop the plugin manager.
		*/
		static void stop();	

		/*!
		*@brief Load all available plugins. 
		*@param path The folder location.
		*@return Number of plugins founded.
		*/
		int loadPlugins (const std::string& path);

		/*!
		*@brief Add a new plugin to the list of available plugins.
		*@param _toadd Plugin to add.
		*/
		void add(IPlugin* _toadd);

		/*!
		*@brief Return Wildcard for all available plugins.
		*/
		std::string Wildcard();

	private:
		/*!
		* @brief ctor.
		*/
		CPluginManager(){};

		/*!
		* @brief dtor.
		*/
		~CPluginManager();

	private:
		static CPluginManager* 		m_Singleton; 	///< The singleton itself.
		std::map<std::string, IPlugin*> m_PluginsList;	///< List of available plugins.
};
#endif 	//_PLUGIN_MANAGER_H_
