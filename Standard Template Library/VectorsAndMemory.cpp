#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers( 0 );
    std::cout << "Numbers array size is " << numbers.size() << std::endl;

    int capacity = numbers.capacity();

    for( int i = 0; i < 10000; i++ )
    {
        if( numbers.capacity() != capacity )
        {
            capacity = numbers.capacity();
            std::cout << "Capacity is " << numbers.capacity() << std::endl;
        }

        numbers.push_back( i );
    }

    std::cout << "Numbers array's size before the clear() is " << numbers.size() << std::endl;
    numbers.clear();
    std::cout << "Numbers array's size after the clear() is " << numbers.size() << "\n"
        << "Capacity after the clear() is " << numbers.capacity() << std::endl;

    numbers.resize( 100 );
    std::cout << "Size after the resizing is " << numbers.size() << "\n"
        << "Capacity after the resizing is " << numbers.capacity() << std::endl;

    numbers.reserve( 100000 );
    std::cout << "Size after the reserve is " << numbers.size() << "\n"
        << "Capacity after the reserve is " << numbers.capacity() << std::endl;

    return 0;
}