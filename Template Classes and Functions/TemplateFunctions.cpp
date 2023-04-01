#include <iostream>

template<typename T>
void print( T obj )
{
    std::cout << obj << std::endl;
}

int main()
{
    print<std::string>( "Test" );
    print<char>( 't' );
    print<int>( 7 );
    print<double>( 4.7 );

    print( '\n' );
    print( "Test 2" );

    return 0;
}