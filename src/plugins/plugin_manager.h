#ifndef _PLUGIN_MANAGER_H_
#define _PLUGIN_MANAGER_H_

#include <config.h>
#include <map>
#include <string>

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
		*@return Number of plugins founded.
		*/
		int loadPlugins (const std::string& path);

	private:
		/*!
		* @brief ctor.
		*/
		CPluginManager(){};

		/*!
		* @brief dtor.
		*/
		~CPluginManager(){};

	private:
		static CPluginManager* 	m_Singleton; 	///< The singleton itself
};
#endif 	//_PLUGIN_MANAGER_H_
