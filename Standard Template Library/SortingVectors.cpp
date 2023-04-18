#include <iostream>
#include <vector>
#include <algorithm>

class SortingVectors
{
private:
    int mID;
    std::string mName;
public:
    SortingVectors( int mID, std::string mName );
    ~SortingVectors();
    void print();
    bool operator<( const SortingVectors& other ) const;
    friend bool compare( const SortingVectors& first, const SortingVectors& second );
};

SortingVectors::SortingVectors( int mID, std::string mName ) : mID( mID ), mName( mName )
{
}

SortingVectors::~SortingVectors()
{
}

void SortingVectors::print()
{
    std::cout << "ID: " << mID << ", Name: " << mName << std::endl;
}

bool SortingVectors::operator<( const SortingVectors& other ) const
{
    return mName == other.mName ? mID < other.mID : mName < other.mName;
}

bool compare( const SortingVectors& first, const SortingVectors& second )
{
    return first.mName < second.mName;
}

int main( int argc, char const* argv[] )
{
    std::vector<SortingVectors> sortingVectors;

    sortingVectors.push_back( SortingVectors( 3, "Vicky" ) );
    sortingVectors.push_back( SortingVectors( 0, "Mike" ) );
    sortingVectors.push_back( SortingVectors( 2, "Raj" ) );
    sortingVectors.push_back( SortingVectors( 1, "Sue" ) );

    std::sort( sortingVectors.begin(), sortingVectors.end(), compare );
    for( int i = 0; i < sortingVectors.size(); i++ )
    {
        sortingVectors[ i ].print();
    }

    return 0;
}