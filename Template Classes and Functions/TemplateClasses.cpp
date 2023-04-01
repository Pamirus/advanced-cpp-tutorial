#include <iostream>

template<class T>

class TemplateClasses
{
private:
    T obj;
public:
    TemplateClasses( T obj )
    {
        this->obj = obj;
    }

    void print()
    {
        std::cout << obj << std::endl;
    }
};

int main()
{
    TemplateClasses<std::string> templateClasses( "Test" );
    templateClasses.print();

    return 0;
}