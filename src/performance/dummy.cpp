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
