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

#include "code_injecter.h"

int main(int argc, char **argv)
{
    CCodeInjecter _CodeInjecter;
    _CodeInjecter.SetFile(argv[1]);
    _CodeInjecter.Inject();
    std::cout << "Injection done !" << std::endl;
    return 1;
}
