#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <def.h>

/*!
 * @brief A database toolbox.
 */
class CTools
{
	public:
		/*!
		 * @brief Default constructor.
		 */
		CTools();
		/*!
		 * @brief 2nd constructor.
		 */
		int Construct();
		/*!
		 * @brief Destructor.
		 */
		~CTools();

	public:
		/*!
		 * @brief Sort a TTable.
		 * @param	_input The TTable unsorted(database).
		 * @param	_output The TTable sorted(database).
		 * @param	_column The column used to sort _input.
		 * @param	_mode	0 = <, 1 = >
		 */
		int SortTable(TTable* _input, TTable& _output, int _column, bool _mode);

		/*!
		 * @brief Find in a TTable.
		 * @param	_string			The string we find.
		 * @param	_rescol			The col were we found _string.
		 * @param	_resrow			The row were we found _string.
		 * @param	_table			The base were we do the find.
		 * @param	_cols			The number of cols of _table.
		 * @param	_rows			The number of rows of _table.
		 * @param	_fromlastpos	Did we find from last position ?
		 * @param	_reverse		Did we do a reverse find from last position ?
		 */
		bool Find(wxString _string, int& _rescol, int& _resrow, TTable* _table, int _cols, int _rows, bool _fromlastpos = true, bool _reverse = false);

	private:
		int        m_FindLastPos;///<Find stuff
		wxString*  m_FindLastString;///<Find stuff
};
#endif							 //_TOOLS_H_
