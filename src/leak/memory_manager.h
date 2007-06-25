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

#ifndef _MEMORY_MANAGER_H
#define _MEMORY_MANAGER_H

#include <fstream>
#include <map>
#include <stack>
#include <string>

#include <log/ilog.h>
#include <config.h>

#define MAJOR_MM 0
#define MINOR_MM 3
#define BUG_MM 0
#define VERSION_MEMORY_MANAGER VERSION(MAJOR_MM,MINOR_MM,BUG_MM)

/*!
 * @brief Memory manager, in fact for the moment it's only a leak detector.
 * @note Historical :
 * @note 	v0.3.0 : Define version using define.\nUse bash colors.
 * @note	v0.2.0 : Initial version.
 */
class CMemoryManager : public ILog
{
	public :
		/*!
		 * @brief	Default constructor.
		 */
		CMemoryManager();
		/*!
		 * @brief	Destructor.
		 */
		~CMemoryManager();

		/*!
		 * @brief	Do memory allocation.
		 * @param	_size Size to allocate.
		 * @param	_file Store the file where delete is did.
		 * @param	_line Store the line where delete is did.
		 * @param	_array Pointer point on array type ?.
		 */
		void* Allocate(std::size_t _size, const std::string& _file, int _line, bool _array);
		/*!
		 * @brief	Free memory.
		 * @param	_ptr Pointer on memory zone to free.
		 * @param	_array Pointer point on array type ?.
		 */
		void Free(void* _ptr, bool _array);
		/*!
		 * @brief	Default constructor.
		 * @param	_file Store the file where delete is did.
		 * @param	_line Store the line where delete is did.
		 */
		void NextDelete(const std::string& _file, int _line);

		/*!
		 * @brief From ILog
		 */
		void Report();

	private:
		/*!
		 * @brief Memory stucture.
		 */
		struct TBlock
		{
			std::size_t             Size;
			std::string             File;
			unsigned int            Line;
			bool                    Array;
			static std::size_t      Total;
		};

		typedef std::map<void*, TBlock> TBlockMap;

		TBlockMap          m_Blocks;
		std::stack<TBlock> m_DeleteStack;
};
#endif							 // _MEMORY_MANAGER_H
