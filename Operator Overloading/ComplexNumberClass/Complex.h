#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

namespace complexNamespace
{
    class Complex
    {
    private:
        double real;
        double imaginary;

    public:
        Complex(/* args */ );
        Complex( double real, double imaginary );
        Complex( const Complex& other );

        const Complex& operator=( const Complex& other );

        double getReal() const { return real; }
        double getImaginary() const { return imaginary; }
    };

    std::ostream& operator<<( std::ostream& out, const Complex& c );
}

#endif