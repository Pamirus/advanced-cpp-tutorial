#include <iostream>

void mightGoWrong()
{
    bool error1 = true;
    bool error2 = false;
    bool error3 = false;

    if( error1 )
    {
        throw 7;
    }
    else if( error2 )
    {
        throw std::string( "Something else went wrong!" );
    }
    else if( error3 )
    {
        const char* e = "p";
        throw e;
    }
}

void useMightGoWrong()
{
    mightGoWrong();
}

int main()
{
    try
    {
        useMightGoWrong();
    }
    catch( int e )
    {
        std::cout << "Error code: " << e << std::endl;
    }
    catch( char const* e )
    {
        std::cout << "Error message: " << e << std::endl;
    }
    catch( std::string e )
    {
        std::cout << "Error string: " << e << std::endl;
    }

    std::cout << "Still running." << std::endl;

    return 0;
}