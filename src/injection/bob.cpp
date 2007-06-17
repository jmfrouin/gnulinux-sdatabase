#include <iostream>

#include <performance/performance_analysis.h>
#include "bob.h"

void Bob::bob()
{
	g_pa->AddFunction("CDummy::dummy");
	g_pa->StartTiming();
	std::cout << "Raoul la moule" << std::endl;
	g_pa->EndTiming();
}
