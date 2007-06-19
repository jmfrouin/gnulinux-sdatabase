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
