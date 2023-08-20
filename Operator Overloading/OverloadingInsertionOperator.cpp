#include <iostream>

class OverloadingInsertionOperator
{
private:
    int mID;
    std::string mName;
public:
    OverloadingInsertionOperator();                                                // Constructor
    OverloadingInsertionOperator( int mID, std::string mName );                    // Parameterized constructor
    OverloadingInsertionOperator( const OverloadingInsertionOperator& other );    // Copy constructor, rule of three
    ~OverloadingInsertionOperator();                                               // Destructor
    const OverloadingInsertionOperator& operator=( const OverloadingInsertionOperator& other );
    friend std::ostream& operator<<( std::ostream& out, const OverloadingInsertionOperator& object );
};

OverloadingInsertionOperator::OverloadingInsertionOperator(): mID( 0 ), mName( "NaN" )
{
}

OverloadingInsertionOperator::OverloadingInsertionOperator( int mID, std::string mName ): mID( mID ), mName( mName )
{
}

OverloadingInsertionOperator::OverloadingInsertionOperator( const OverloadingInsertionOperator& other )
{
    std::cout << "Copy constructor runs." << std::endl;
    mID = other.mID;
    mName = other.mName;
}

OverloadingInsertionOperator::~OverloadingInsertionOperator()
{
}

const OverloadingInsertionOperator& OverloadingInsertionOperator::operator=( const OverloadingInsertionOperator& other )
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

std::ostream& operator<<( std::ostream& out, const OverloadingInsertionOperator& object )
{
    out << object.mID << ": " << object.mName;

    return out;
}

int main( int argc, char const* argv[] )
{
    OverloadingInsertionOperator object( 7, "Mike" );
    OverloadingInsertionOperator object2( 9, "Bob" );
    
    std::cout << object << "\n" << object2 << std::endl;

    return 0;
}