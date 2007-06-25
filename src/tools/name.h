#ifndef _NAME_H_
#define _NAME_H_

#include <config.h>
#include <string>

/**
 * @brief A base class who named an object.
 */
class CName 
{
	public:
		/*!
		*@brief Default constructor.
		*/
		CName();
	
		/*!
		*@brief Destructor.
		*/
		virtual ~CName();
		
		/*!
		*@brief Retrieve the current name.
		*@return A string which contain the name.
		*/
		virtual const std::string& getName();

		/*!
		*@brief Set the current name.
		*@param _Name A string which contain the name.
		*/
		virtual void setName(const std::string& _Name);
	
	private:
		std::string 	m_Name;		///< The name.
		
};
#endif 	//_NAME_H_
