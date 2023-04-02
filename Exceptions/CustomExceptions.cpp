#include <iostream>

class MyException : public std::exception
{
public:
    MyException(/* args */);
    ~MyException();
    virtual const char* what() const throw();
};

MyException::MyException() {}

MyException::~MyException() {}

const char* MyException::what() const throw()
{
    return "An exception caught!\n";
}


class Wrong
{
public:
    Wrong();
    ~Wrong();
    void goesWrong();
};

Wrong::Wrong() {}

Wrong::~Wrong() {}

void Wrong::goesWrong()
{
    throw MyException();
}

int main()
{
    Wrong wrong;

    try
    {
        wrong.goesWrong();
    }
    catch( MyException& e )
    {
        std::cout << e.what() << "\n";
    }

    return 0;
}