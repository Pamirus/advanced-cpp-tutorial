#include <iostream>
#include <set>

class SetClass
{
private:
    int mID;
    std::string mName;
public:
    SetClass();
    SetClass( int mID, std::string mName );
    ~SetClass();
    std::string getName() const;
    int getID() const;
    void print() const;
    bool operator<( const SetClass& other ) const;
};

SetClass::SetClass() : mID( 0 ), mName( "" ) {}

SetClass::SetClass( int mID, std::string mName ) : mID( mID ), mName( mName ) {}

SetClass::~SetClass() {}

std::string SetClass::getName() const
{
    return mName;
}

int SetClass::getID() const
{
    return mID;
}

void SetClass::print() const
{
    std::cout << getName() << ": " << getID() << std::endl;
}

bool SetClass::operator<( const SetClass& other ) const
{
    return mName < other.mName;
}


int main()
{
    std::set<int> numbers;
    numbers.insert( 50 );
    numbers.insert( 10 );
    numbers.insert( 30 );
    numbers.insert( 30 );
    numbers.insert( 40 );
    for( std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++ )
        std::cout << *it << std::endl;

    std::cout << std::endl;
    std::set<int>::iterator itFind = numbers.find( 30 );

    if( itFind != numbers.end() )
        std::cout << "Found: " << *itFind << std::endl;

    if( numbers.count( 30 ) )
        std::cout << "Number found." << std::endl;

    std::cout << std::endl;

    std::set<SetClass> mySet;
    mySet.insert( SetClass( 30, "Mike" ) );
    mySet.insert( SetClass( 20, "Ivy" ) );
    mySet.insert( SetClass( 40, "Davis" ) );

    for( std::set<SetClass>::iterator it = mySet.begin(); it != mySet.end(); it++ )
    {
        it->print();
    }

    return 0;
}