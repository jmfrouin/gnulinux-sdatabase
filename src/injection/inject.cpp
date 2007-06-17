#include <iostream>

#include "code_injecter.h"

int main(int argc, char **argv)
{
    CCodeInjecter _CodeInjecter;
    _CodeInjecter.SetFile(argv[1]);
    _CodeInjecter.Inject();
    std::cout << "Injection done !" << std::endl;
    return 1;
}
