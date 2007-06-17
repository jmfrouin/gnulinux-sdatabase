#include <iostream>

#include <performance/performance_analysis.h>
#include "bob.h"

CPerformanceAnalysis* g_pa;

int main(int argc, char **argv)
{
    	g_pa = new CPerformanceAnalysis();
	Bob a;
	a.bob();
    	delete g_pa;
	return 1;
}
