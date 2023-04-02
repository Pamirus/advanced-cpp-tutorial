#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> strings;
    strings.push_back( "one" );
    strings.push_back( "two" );
    strings.push_back( "three" );

    // for( int i; i < strings.size(); i++ )
    // {
    //     std::cout << strings[ i ] << std::endl;
    // }

    // Preferring the iterators to print vector elements instead of the classical loops is beneficial to the memory.
    for( std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++ )
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    std::vector<std::string>::iterator it = strings.begin();
    it += 2;
    std::cout << *it << std::endl;

    return 0;
}