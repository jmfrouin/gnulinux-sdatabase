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

#ifndef _ILOG_H
#define _ILOG_H

#include <fstream>

/*!
 * @brief Log manipulation interface
 */
class ILog
{
	public:
		/*!
		 * @brief	Default constructor.
		 */
		ILog();
		/*!
		 * @brief	Destructor.
		 */
		virtual ~ILog();

		/*!
		 * @brief	Write report.
		 */
		virtual void Report() = 0;

	public:
		std::ofstream      m_File;
};
#endif							 //_ILOG_H_
