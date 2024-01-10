#include <iostream>
#include "Complex.h"

using namespace complexNamespace;

int main( int argc, char const* argv[] )
{
    double real = 1.0;
    double imag = 4.7;
    Complex myComplex( real, imag );
    Complex myComplex2 = myComplex;

    myComplex = myComplex2;

    std::cout << "myComplex: " << myComplex << "\nmyComplex2:" << myComplex2 << std::endl;

    return 0;
}
