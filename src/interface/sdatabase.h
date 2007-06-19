/*
 * @brief :         Main application header
 * @author :     Jean-Michel Frouin
 * @date :        02/01/2007
 */

#ifndef _SDATABASE_H_
#define _SDATABASE_H_

/*!
 * @brief Main component (wxApp)
 */
class SDatabase: public wxApp
{
	public:

		/*!
		 *  Default constructor.
		 */
		SDatabase();
		/*!
		 * Destructor.
		 */
		~SDatabase();

		/*!
		 * @brief from wxApp.
		 */
		virtual bool OnInit();
};

DECLARE_APP(SDatabase)
#endif							 // _SDATABASE_H_
