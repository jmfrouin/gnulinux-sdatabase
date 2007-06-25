#ifndef _XML_PLUGIN_H_
#define _XML_PLUGIN_H_

#include <config.h>
#include <plugins/iplugin.h>

class CxmlPlugin : public IPlugin
{
	public:
		CxmlPlugin();
		~CxmlPlugin();

		/*
		* @brief From IPlugin.
		*/
		bool Write(const std::string& _path);
		std::string Wildcard();
};

#endif 	//_XML_PLUGIN_H_

