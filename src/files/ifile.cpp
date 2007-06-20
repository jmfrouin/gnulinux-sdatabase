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

#include "ifile.h"
#include <iostream>

#if defined LEAK_DETECTOR
#include <leak/leak_detector.h>
#endif

IFile::IFile()
{
	#if defined DEBUG
	std::cout << "[DEBUG] [IFile] IFile" << std::endl;
	#endif
}


//Add a test for tuple longer than columns number

IFile::~IFile()
{
	#if defined DEBUG
	std::cout << "[DEBUG] [IFile] ~IFile" << std::endl;
	#endif
}
