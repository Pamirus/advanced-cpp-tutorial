#include <iostream>
#include <map>

class Person
{
private:
    std::string mName;
    int mAge;

public:
    Person();
    Person( const Person& other );
    Person( std::string name, int age );
    ~Person();

    std::string getName() const;
    int getAge() const;

    void print() const;
    bool operator < ( const Person& other ) const;
};

Person::Person() : mName( "" ), mAge( 0 ) {}

Person::Person( const Person& other ) : mName( "" ), mAge( 0 )
{
    mName = other.getName();
    mAge = other.getAge();
}

Person::Person( std::string name, int age ) : mName( name ), mAge( age ) {}

Person::~Person() {}

std::string Person::getName() const
{
    return mName;
}

int Person::getAge() const
{
    return mAge;
}

void Person::print() const
{
    std::cout << getName() << ": " << getAge() << std::endl;
}

bool Person::operator < ( const Person& other ) const
{
    if( mName != other.getName() )
        return mName < other.getName();
    else
        return mAge < other.getAge();
}


int main()
{
    std::map< Person, int > people;

    people[ Person( "Mike", 40 ) ] = 56;
    people[ Person( "Mike", 30 ) ] = 0;
    people[ Person( "Sue", 18 ) ] = 2;
    people[ Person( "Raj", 20 ) ] = 1;

    std::cout << "\nListing all elements: " << std::endl;
    for( std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++ )
    {
        it->first.print();
    }

    return 0;
}