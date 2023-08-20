#include <iostream>

class OverloadingInsertationOperator
{
private:
    int mID;
    std::string mName;
public:
    OverloadingInsertationOperator();                                                // Constructor
    OverloadingInsertationOperator( int mID, std::string mName );                    // Parameterized constructor
    OverloadingInsertationOperator( const OverloadingInsertationOperator& other );    // Copy constructor, rule of three
    ~OverloadingInsertationOperator();                                               // Destructor
    const OverloadingInsertationOperator& operator=( const OverloadingInsertationOperator& other );
    friend std::ostream& operator<<( std::ostream& out, const OverloadingInsertationOperator& object );
};

OverloadingInsertationOperator::OverloadingInsertationOperator(): mID( 0 ), mName( "NaN" )
{
}

OverloadingInsertationOperator::OverloadingInsertationOperator( int mID, std::string mName ): mID( mID ), mName( mName )
{
}

OverloadingInsertationOperator::OverloadingInsertationOperator( const OverloadingInsertationOperator& other )
{
    std::cout << "Copy constructor runs." << std::endl;
    mID = other.mID;
    mName = other.mName;
}

OverloadingInsertationOperator::~OverloadingInsertationOperator()
{
}

const OverloadingInsertationOperator& OverloadingInsertationOperator::operator=( const OverloadingInsertationOperator& other )
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

std::ostream& operator<<( std::ostream& out, const OverloadingInsertationOperator& object )
{
    out << object.mID << ": " << object.mName;

    return out;
}

int main( int argc, char const* argv[] )
{
    OverloadingInsertationOperator object( 7, "Mike" );
    OverloadingInsertationOperator object2( 9, "Bob" );
    
    std::cout << object << "\n" << object2 << std::endl;

    return 0;
}