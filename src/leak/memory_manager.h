#ifndef _MEMORY_MANAGER_H
#define _MEMORY_MANAGER_H

#include <fstream>
#include <map>
#include <stack>
#include <string>

#include <log/ilog.h>

#define VERSION_MEMORY_MANAGER 0.2

/*!
 * @brief Memory manager, in fact for the moment it's only a leak detector.
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
