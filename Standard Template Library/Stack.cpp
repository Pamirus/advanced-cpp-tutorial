#include <iostream>
#include <stack>

class StackClass
{
private:
    std::string mName;
public:
    StackClass( std::string mName );
    ~StackClass();
    std::string getName() const;
    void print() const;
    bool operator<( const StackClass& other ) const;
};

StackClass::StackClass( std::string mName ) : mName( mName ) {}

StackClass::~StackClass() {}

std::string StackClass::getName() const
{
    return mName;
}

void StackClass::print() const
{
    std::cout << "Name: " << getName() << std::endl;
}

bool StackClass::operator<( const StackClass& other ) const
{
    return mName < other.mName;
}

int main()
{
    std::stack<StackClass> myStack;
    myStack.push( StackClass( "John" ) );
    myStack.push( StackClass( "Vicky" ) );
    myStack.push( StackClass( "Ivy" ) );
    myStack.push( StackClass( "Sue" ) );
    myStack.push( StackClass( "Bob" ) );

    StackClass stackObj = myStack.top();
    stackObj.print();

    myStack.pop();
    StackClass stackObj2 = myStack.top();
    stackObj2.print();

    std::cout << std::endl;

    /*
        // This is invaild, because the object is being destroyed.

        while( myStack.size() != 0 )
        {
        myStack.pop();
        StackClass stackObj3 = myStack.top();
        stackObj3.print();
        }
    */

    while( myStack.size() != 0 )
    {
        StackClass& stackObj = myStack.top();
        stackObj.print();
        myStack.pop();
    }

    return 0;
}