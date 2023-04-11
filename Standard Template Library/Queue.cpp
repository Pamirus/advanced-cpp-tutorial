#include <iostream>
#include <queue>

class QueueClass
{
private:
    std::string mName;
public:
    QueueClass( std::string mName );
    ~QueueClass();
    std::string getName() const;
    void print() const;
    bool operator<( const QueueClass& other ) const;
};

QueueClass::QueueClass( std::string mName ) : mName( mName ) {}

QueueClass::~QueueClass() {}

std::string QueueClass::getName() const
{
    return mName;
}

void QueueClass::print() const
{
    std::cout << "Name: " << getName() << std::endl;
}

bool QueueClass::operator<( const QueueClass& other ) const
{
    return mName < other.mName;
}

int main()
{
    std::queue<QueueClass> myQueue;
    myQueue.push( QueueClass( "John" ) );
    myQueue.push( QueueClass( "Vicky" ) );
    myQueue.push( QueueClass( "Ivy" ) );
    myQueue.push( QueueClass( "Sue" ) );
    myQueue.push( QueueClass( "Bob" ) );

    QueueClass stackObj = myQueue.front();
    stackObj.print();

    myQueue.pop();
    QueueClass stackObj2 = myQueue.front();
    stackObj2.print();

    std::cout << std::endl;

    /*
        // This is invaild, because the object is being destroyed.

        while( myQueue.size() != 0 )
        {
        myQueue.pop();
        StackAndQueue stackObj3 = myQueue.top();
        stackObj3.print();
        }
    */

    while( myQueue.size() != 0 )
    {
        QueueClass& stackObj = myQueue.front();
        stackObj.print();
        myQueue.pop();
    }

    std::cout << std::endl;

    myQueue.back().print();

    return 0;
}