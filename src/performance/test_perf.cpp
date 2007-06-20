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

#include <iostream>
#include "performance_analysis.h"
#include "dummy.h"

CPerformanceAnalysis* g_pa;

int main(int agrc, char** argv)
{
	g_pa = new CPerformanceAnalysis();
	CDummy test;
	for(int i=0; i<10; ++i)
		test.dummy();
	for(int i=0; i<50; ++i)
		test.dummy2();

	//temp
	delete g_pa;
	system("PAUSE");
	return 1;
}
