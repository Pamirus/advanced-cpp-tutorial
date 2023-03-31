#include <iostream>
#include <fstream>

int main()
{
    std::string fileName = "text.txt";
    std::ifstream inputFile;

    inputFile.open( fileName );
    if( inputFile.is_open() == false )
    {
        return 1;
    }

    while( inputFile )
    {
        std::string line;
        getline( inputFile, line, ':' );

        int population;
        inputFile >> population;

        // inputFile.get();
        inputFile >> std::ws; // this is more robust, whitespace read which is used in C++11
        
        if( !inputFile )
        {
            break;
        }

        std::cout << "'" << line << " -- " << population << std::endl;
    }

    inputFile.close();

    return 0;
}