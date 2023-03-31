#include <iostream>
#include <fstream>

int main()
{
    std::string inFileName = "text.txt";
    std::ifstream inFile;

    inFile.open( inFileName );
    if( inFile.is_open() )
    {
        std::string line;

        while( inFile )
        {
            getline( inFile, line );
            std::cout << line << std::endl;
        }

        inFile.close();
    }
    else
    {
        std::cout << "Cannot open file: " << inFileName << std::endl;
    }
}