#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages;
    ages[ "Mike" ] = 40;
    ages[ "Raj" ] = 20;
    ages[ "Vicky" ] = 30;

    ages.insert( std::make_pair( "Peter", 100 ) );

    if( ages.find( "Vicky" ) != ages.end() )
        std::cout << "Key is found: " << ages[ "Vicky" ] << std::endl;
    else
        std::cout << "Key is not found." << std::endl;

    for( std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++ )
    {
        std::pair<std::string, int> age = *it;

        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}