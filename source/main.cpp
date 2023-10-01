#include <iostream>

#include "func.h"

int main(int argc, char* argv[]){

    std::cout << "Prog startet\n";
    std::cout << "3 + 4 = " << sum(3,4) << "\n";
    std::cout << "3 - 4 = " << sub(3,4) << "\n";
    std::cout << "Done!\n";

    return 0;
}