#ifndef _CCSVFile_H_
#define _CCSVFile_H_

#include "ifile.h"

/*!
 * @brief CSV plugin : import/export as csv.
 */
class CCSVFile : public IFile
{
	public:
		/*!
		 * @brief From IFile.
		 */
		bool OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows);
		bool WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols);
};
#endif							 // _CCCSVFile_H_
