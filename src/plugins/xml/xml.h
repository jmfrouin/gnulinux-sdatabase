/*
-------------------------------------------------------------------------
Project : sdatabase
-------------------------------------------------------------------------
Creator : Frouin Jean-Michel
-------------------------------------------------------------------------
$Date$
$Rev$
$Author$
-------------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
-------------------------------------------------------------------------
*/

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
#endif                           //_XML_PLUGIN_H_
