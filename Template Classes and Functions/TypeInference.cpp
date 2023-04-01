#include <iostream>

template<typename T>
void print( T obj )
{
    std::cout << "Template print(): " << obj << std::endl;
}

void print( int value )
{
    std::cout << "Non-template print(): " << value << std::endl;
}

template<typename T>
void show()
{
    std::cout << T() << std::endl;
}

int main()
{
    print( 7 );
    print<int>( 7 );
    print<>( 7 );

    show<double>();

    return 0;
}