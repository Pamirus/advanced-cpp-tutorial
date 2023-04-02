#include <iostream>
#include <list>

template<typename T>
void print( std::list<T>& list )
{
    for( std::list<int>::iterator it = list.begin(); it != list.end(); it++ )
        std::cout << *it << std::endl;
}

int main()
{
    std::list<int> numbers;
    numbers.push_back( 1 );
    numbers.push_back( 2 );
    numbers.push_back( 3 );
    print( numbers );
    std::cout << std::endl;

    numbers.push_front( 4 );
    print( numbers );
    std::cout << std::endl;

    std::list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert( it, 100 );
    print( numbers );
    std::cout << std::endl;

    it++;
    numbers.erase( it );
    print( numbers );
    std::cout << std::endl;

    for( std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++ )
    {
        if( *it == 1 )
            numbers.insert( it, 1234 );

        if( *it == 2 )
            it = numbers.erase( it );
        else
            it++;
    }

    print( numbers );

    return 0;
}