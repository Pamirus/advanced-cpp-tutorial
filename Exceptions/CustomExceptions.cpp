#include <iostream>

class MyException : public std::exception
{
private:
    /* data */
public:
    MyException(/* args */);
    ~MyException();
    virtual const char* what() const throw();
};

MyException::MyException(/* args */)
{
}

MyException::~MyException()
{
}

const char* MyException::what() const throw()
{
    return "An exception caught!\n";
}


class Wrong
{
private:
    /* data */
public:
    Wrong(/* args */);
    ~Wrong();
    void goesWrong();
};

Wrong::Wrong(/* args */)
{
}

Wrong::~Wrong()
{
}

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