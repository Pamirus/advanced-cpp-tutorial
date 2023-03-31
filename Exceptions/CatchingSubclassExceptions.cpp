#include <iostream>

void goesWrong()
{
    bool error1 = true;
    bool error2 = false;

    if( error1 )
    {
        throw std::bad_alloc();
    }
    else if( error2 )
    {
        throw std::exception();
    }
}

int main()
{
    try
    {
        goesWrong();
    }
    catch( const std::bad_alloc& e )
    {
        std::cout << "Catching bad_alloc: " << e.what() << '\n';
    }
    catch( const std::exception& e ) // if this statement comes first, it will catch the bad_alloc as an exception
    {
        std::cout << "Catching exception: " << e.what() << '\n';
    }

    return 0;
}