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
