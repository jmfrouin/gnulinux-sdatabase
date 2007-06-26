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

/*
 * @brief :         Main application header
 * @author :     Jean-Michel Frouin
 * @date :        02/01/2007
 */

#ifndef _SDATABASE_H_
#define _SDATABASE_H_

#include <string>

/*!
 * @brief Main component (wxApp)
 */
class SDatabase: public wxApp
{
    public:

        /*!
         *  Default constructor.
         */
        SDatabase();
        /*!
         * Destructor.
         */
        ~SDatabase();

        /*!
         * @brief from wxApp.
         */
        virtual bool OnInit();

    private:
        /*!
         * @brief Load output format plugins.
         */
        bool __loadPlugins(const std::string& _path);
};

DECLARE_APP(SDatabase)
#endif                           // _SDATABASE_H_
