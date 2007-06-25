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

#ifndef _CMANAGER_H_
#define _CMANAGER_H_

#include <iostream>
#include <wx/wx.h>
#include <engine/tools.h>
#include <files/ifile.h>
#include <vector>
#include <config.h>

/*!
 * @brief The database manager
 */
class CManager
{
	public:
		/*!
		 * @brief	Default constructor.
		 */
		CManager();
		/*!
		 * @brief	2nd constructor.
		 * @return	1 on success, 0 on failure.
		 */
		int Construct();
		/*!
		 * @brief	Destructor.
		 */
		virtual ~CManager();

	public:

		/*!
		 * @brief	Retrieve the number of rows of current database.
		 * @return	The number of rows.
		 */
		int GetRows ();

		/*!
		 * @brief	Retrieve the number of cols of current database.
		 * @return	The number of cols.
		 */
		int GetCols ();

		/*!
		 * @brief	Retrieve a pointer on current database.
		 * @return	Pointer on it.
		 */
		TTable* GetTable ();

		/*!
		 * @brief	Retrieve the title of cols of current database.
		 * @return	A vector of string where 1 string is 1 title.
		 */
		std::vector<wxString>& GetTitles();

		/*!
		 * @brief	Append a tuple to the database.
		 * @param	_tuple	Tuple to add.
		 */
		void Append(TTuple _tuple);

	#if defined DEBUG
		/*!
		 * @brief	Debug display.
		 */
		virtual void Display();
	#endif

		/*!
		 * @brief from CTools
		 */
		int SortTable(int _column, bool _mode);

		/*!
		 * @brief from CTools
		 */
		bool Find(wxString _search, int& _col, int& _row, bool _fromlastpos, bool _reverse);

		/*!
		 * @brief Retrieve the current database filename;
		 */
		wxString GetFilename ();

		/*!
		 * @brief from IFile
		 */
		void WriteFile ();
		/*!
		 * @brief from IFile
		 */
		bool OpenFile(const wxString _filename);

	private:
		IFile*      m_File;		 ///<Pointer on export / import plugin
		CTools*     m_Tools;	 ///<Tools for base manipulations (Pointer here to remember to call Construct()

		//Table manipulation
		wxString    m_Filename;	 ///< Current base filename
		int         m_Cols;		 ///< Number of columns of current base
		int         m_Rows;		 ///< Number of rows of current base
		TTable*     m_Table;	 ///< The base itself
		TTuple      m_Title;	 ///< Titles of current base
};
#endif							 // _CMANAGER_H_
