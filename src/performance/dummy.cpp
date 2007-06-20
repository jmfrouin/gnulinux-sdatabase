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
#include <math.h>

#include "dummy.h"
#include "perf_analysis.h"

void CDummy::dummy()
{
	//Performance analysis
	g_pa->AddFunction("CDummy::dummy");
	g_pa->StartTiming();
	float a=0.9,b=0.1;
	for(int i=0; i<50000; ++i)
	{
		a*=cos(sin(tan(acos(asin(atan(b))))));
		a = log(a);
	}
	g_pa->EndTiming();
}


void CDummy::dummy2()
{
	//Performance analysis
	g_pa->AddFunction("CDummy::dummy2");
	g_pa->StartTiming();
	float a=0.7,b=0.1;
	for(int i=0; i<500000; ++i)
	{
		a*=cos(sin(tan(acos(asin(atan(b))))));
		a = log(a);
	}
	g_pa->EndTiming();
}
