#ifndef _IPLUGIN_H_
#define _IPLUGIN_H_

#include <config.h>
#include <string>
#include <tools/name.h>

/**
 * @brief Plugin Interface
 */
class IPlugin : public CName
{
	public:
		/*!
		 * @brief dtor.
		 */
		virtual ~IPlugin(){}

		/*!
		* @brief Write database in the plugin format.
		* @param _path Location of file to write.
		*/
		virtual bool Write(const std::string& _path) = 0;
};
#endif 	//_IPLUGIN_H_
