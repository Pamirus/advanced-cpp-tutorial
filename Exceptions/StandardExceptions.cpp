#include <iostream>

class CanGoWrong
{
private:
    char* pMemory;
public:
    CanGoWrong();
    ~CanGoWrong();
};

CanGoWrong::CanGoWrong()
{
    pMemory = new char[ 99999999999999999999999999999999999999999999999999999999 ];
}

CanGoWrong::~CanGoWrong()
{
    delete[] pMemory;
}


int main()
{
    try
    {
        CanGoWrong wrong;
    }
    // catch( const std::exception& e )
    // {
    //     std::cerr << e.what() << '\n';
    // }
    catch( const std::bad_alloc& e )
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    std::cout << "Still running.\n";

    return 0;
}