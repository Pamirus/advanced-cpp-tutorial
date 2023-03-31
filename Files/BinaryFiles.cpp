#include <iostream>
#include <fstream>

#pragma pack(push, 1)
struct Person
{
    char name[ 50 ];
    int age;
    double weight;
};
#pragma pack(pop)

int main()
{
    Person person = { "Gandalf", 192, 75.4 };

    std::string fileName = "test.bin";

    // Write file here
    std::ofstream outputFile;

    outputFile.open( fileName, std::ios::binary );

    if( outputFile.is_open() )
    {
        outputFile.write( reinterpret_cast< char* >( &person ), sizeof( Person ) );

        outputFile.close();
    }
    else
    {
        std::cout << "Could not write the file: " << fileName << std::endl;
    }

    // Read file here
    Person personOther = {};
    std::ifstream inputFile;

    inputFile.open( fileName, std::ios::binary );

    if( inputFile.is_open() )
    {
        inputFile.read( reinterpret_cast< char* >( &personOther ), sizeof( Person ) );

        inputFile.close();
    }
    else
    {
        std::cout << "Could not read the file: " << fileName << std::endl;
    }

    std::cout << "Person's name is " << personOther.name
        << ", and their age is " << personOther.age
        << ", and their weight is " << personOther.weight << std::endl;

    return 0;
}