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

#ifndef _CODE_INJECTER_H_
#define _CODE_INJECTER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define VERSION_CODE_INJECTER 0.1

/*!
 * @brief Inject asm code in another asm code.
 * @note In order to simply include performance analysis.
 */
class CCodeInjecter
{
	public:
		/*!
		 * @brief	Default constructor.
		 */
		CCodeInjecter();
		/*!
		 * @brief	Destructor.
		 */
		~CCodeInjecter();

		void    SetFile(std::string _file);
		int        Inject();

	private:
		int        CreateASM();
		int        ASMPatch();
		int        BuildObject();
		void    ReportCodeInjection();

	private:
		std::string                    m_FileName;
		// Report file
		// FIXME : Interface pour ce putain de m_File
		std::ofstream                m_File;
		//Tools paths
		std::string                    m_GCCPath;
		std::string                    m_ASPath;
		std::string                    m_GCCOptions;
		std::string                    m_ASOptions;
		//Various settings
		bool                            m_UserFunctionFound;
		//Global informations
		std::vector<std::string> m_FunctionsList;
};
#endif							 //_CODE_INJECTER_H_
