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

#include <algorithm>
#include <string>

#include <performance/performance_analysis.h>
#include "tools.h"

#define LENGTH 2

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

CTools::CTools()
{

}


int CTools::Construct()
{
	m_FindLastPos = -1;
	m_FindLastString = NULL;

	m_FindLastString = new wxString("");
	if(m_FindLastString)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


CTools::~CTools()
{
	if(m_FindLastString)
	{
		delete m_FindLastString;
	}
}


int CTools::SortTable(TTable* _input, TTable& _output, int _column, bool _mode)
{
	//g_pa->AddFunction("int CTools::SortTable(TTable* _input, TTable& _output, int _column, bool _mode)");
	//g_pa->StartTiming();
	//Create a vector of string that we will sort
	TTuple _maxtuple;
	std::string _max;

	if(_input->empty())
	{
		return 1;
	}

	TTable::iterator _it=_input->begin();

	_max.assign((*_it)[_column]);
	_maxtuple.assign( _it->begin(), _it->end() );

	//Find Max
	for(; _it != _input->end(); ++_it)
	{
		if(std::lexicographical_compare(_max.begin(), _max.size()>LENGTH ? _max.begin()+LENGTH : _max.end(),
			(*_it)[_column].begin(), (*_it)[_column].size() > LENGTH ? (*_it)[_column].begin() + LENGTH : (*_it)[_column].end()) == _mode)
		{
			_max.assign((*_it)[_column]);
			_maxtuple.clear();
			_maxtuple.assign( _it->begin(), _it->end() );
		}
	}

	_input->remove(_maxtuple);
	_output.push_back(_maxtuple);
	//g_pa->StartTiming();
	return SortTable(_input, _output, _column, _mode);
}


//bool pred(const std::string& lhs, const std::string& rhs)
//{
//    return std::lexicographical_compare(lhs.begin(), lhs.size()>10 ?
//        lhs.begin()+10 : lhs.end(), rhs.begin(), rhs.size()>10 ? rhs.begin()+10 :
//        rhs.end());
//}

//FIXME : Seem this function is now buggy : CTools::Find
bool CTools::Find(wxString _string, int& _rescol, int& _resrow, TTable* _table, int _cols, int _rows, bool _fromlastpos, bool _reverse)
{
	TTable::iterator it;

	if(_reverse)
	{
		it = _table->end();
	}
	else
	{
		it = _table->begin();
	}

	int ret;

	if(_reverse)
	{
		ret = _rows;
	}
	else
	{
		ret = 0;
	}

	#if defined DEBUG
	std::cout << "[DEBUG] [CManager] Find : _fromlastpos = " <<  _fromlastpos << std::endl;
	std::cout << "[DEBUG] [CManager] Find : m_FindLastPos  = " <<  m_FindLastPos << std::endl;
	#endif

	if(_fromlastpos)
	{
		if(_reverse)
		{
			ret = m_FindLastPos - 1;
		}
		else
		{
			ret = m_FindLastPos + 1;
		}

		if(_reverse)
		{
			for(int i = _rows; i > 0; --i)
			{
				--it;
			}
		}
		else
		{
			for(int i = 0; i < ret; ++i)
			{
				++it;
			}
		}

	}
	#if defined DEBUG && VERBOSE
	std::cout << "[DEBUG][CManager] Find Starting here : " << (*it)[0] << std::endl;
	#endif
	//FIXME : Fix reverse mode
	if(_reverse)
	{
		for (; it != _table->begin(); --it)
		{
			for(unsigned int i = 0; i < it->size(); ++i)
			{
				if((*it)[i].Find(_string) != wxNOT_FOUND)
				{
					(*m_FindLastString) = _string;
					m_FindLastPos = ret;
					#if defined DEBUG
					std::cout << (*it)[i] << " =? " << _string << "(" << m_FindLastPos << ")" << std::endl;
					#endif
					//Push row
					_resrow = ret;
					//Push Col
					_rescol = i;
					//And finally return
					return true;
				}
			}
			--ret;
		}
	}
	else
	{
		for (; it != _table->end(); ++it)
		{
			for(unsigned int i = 0; i < it->size(); ++i)
			{
				if((*it)[i].Find(_string) != wxNOT_FOUND)
				{
					(*m_FindLastString) = _string;
					m_FindLastPos = ret;
					#if defined DEBUG
					std::cout << (*it)[i] << " =? " << _string << "(" << m_FindLastPos << ")" << std::endl;
					#endif
					//Push row
					_resrow = ret;
					//Push Col
					_rescol = i;
					//And finally return
					return true;
				}
			}
			++ret;
		}
	}

	if(_reverse)
	{
		m_FindLastPos = _rows + 1;
	}
	else
	{
		m_FindLastPos = -1;
	}

	return false;
}
