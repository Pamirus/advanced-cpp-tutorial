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

    void print();
};

Person::Person() : mName( "" ), mAge( 0 )
{
    std::cout << "Constructor" << std::endl;
}

Person::Person( const Person& other ) : mName( "" ), mAge( 0 )
{
    std::cout << "Copy constructor" << std::endl;
    mName = other.getName();
    mAge = other.getAge();
}

Person::Person( std::string name, int age ) : mName( name ), mAge( age )
{
    std::cout << "Member initializer list" << std::endl;
}

Person::~Person() {}

std::string Person::getName() const
{
    return mName;
}

int Person::getAge() const
{
    return mAge;
}

void Person::print()
{
    std::cout << getName() << ": " << getAge() << std::endl;
}


int main()
{
    std::map<int, Person> people;

    people[ 56 ] = Person( "Mike", 40 );
    people[ 56 ].print();

    people[ 0 ] = Person( "Vicky", 30 );
    people[ 0 ].print();

    people[ 1 ] = Person( "Raj", 20 );
    people[ 1 ].print();

    people.insert( std::make_pair( 55, Person( "Bob", 45 ) ) );
    people[ 55 ].print();

    people.insert( std::make_pair( 57, Person( "Sue", 24 ) ) );
    people[ 57 ].print();

    std::cout << "\nListing all elements: " << std::endl;
    for( std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++ )
    {
        it->second.print();
    }

    return 0;
}