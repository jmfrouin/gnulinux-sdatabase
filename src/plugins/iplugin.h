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

#ifndef _IPLUGIN_H_
#define _IPLUGIN_H_

#include <config.h>
#include <string>
#include <tools/name.h>
#include <tools/ifile.h>

/**
 * @brief Plugin Interface
 */
class IPlugin : public CName, public IFile
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

        /*!
         * @brief Wildcard of plugin for open / save FileDialog.
         */
        virtual std::string Wildcard() = 0;
};
#endif                           //_IPLUGIN_H_
