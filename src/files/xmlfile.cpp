#include "xmlfile.h"

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

bool CXMLFile::OpenFile(const wxString _filename, TTable& _table, TTuple& _title, int& _cols, int& _rows)
{
	return true;
}


bool CXMLFile::WriteFile(const wxString _filename, TTable _table, TTuple _title, int _cols)
{
	return true;
}
