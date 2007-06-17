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
