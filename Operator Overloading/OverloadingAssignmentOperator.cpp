#include <iostream>

class OverloadingAssignmentOperator
{
private:
    int mID;
    std::string mName;
public:
    OverloadingAssignmentOperator();                                                // Constructor
    OverloadingAssignmentOperator( int mID, std::string mName );                    // Parameterized constructor
    OverloadingAssignmentOperator( const OverloadingAssignmentOperator& other );    // Copy constructor, rule of three
    ~OverloadingAssignmentOperator();                                               // Destructor
    void print();
    const OverloadingAssignmentOperator& operator=( const OverloadingAssignmentOperator& other );
};

OverloadingAssignmentOperator::OverloadingAssignmentOperator() : mID( 0 ), mName( "NaN" )
{
}

OverloadingAssignmentOperator::OverloadingAssignmentOperator( int mID, std::string mName ) : mID( mID ), mName( mName )
{
}

OverloadingAssignmentOperator::OverloadingAssignmentOperator( const OverloadingAssignmentOperator& other )
{
    std::cout << "Copy constructor runs." << std::endl;
    mID = other.mID;
    mName = other.mName;
}

OverloadingAssignmentOperator::~OverloadingAssignmentOperator()
{
}

void OverloadingAssignmentOperator::print()
{
    std::cout << "ID: " << mID << " Name: " << mName << std::endl;
}

const OverloadingAssignmentOperator& OverloadingAssignmentOperator::operator=( const OverloadingAssignmentOperator& other )
{
    std::cout << "Assignment runs." << std::endl;
    mID = other.mID;
    mName = other.mName;

    return *this;
}

void emptyLine()
{
    std::cout << std::endl;
}

int main( int argc, char const* argv[] )
{
    OverloadingAssignmentOperator object( 7, "Mike" );
    object.print();

    OverloadingAssignmentOperator objectBob( 9, "Bob" );
    objectBob.print();

    // emptyLine();
    // objectBob = object;
    // objectBob.print();

    // emptyLine();
    // OverloadingAssignmentOperator objectEmpty;
    // objectEmpty = objectBob = object;
    // objectEmpty.print();

    emptyLine();
    OverloadingAssignmentOperator objectEmpty;
    objectEmpty.operator=( objectBob );
    objectEmpty.print();

    emptyLine();
    OverloadingAssignmentOperator objectEmpty2 = object;
    objectEmpty2.print();

    return 0;
}
