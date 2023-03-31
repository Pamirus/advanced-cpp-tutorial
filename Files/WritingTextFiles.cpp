#include <iostream>
#include <fstream>

int main()
{
    // std::ofstream outFile;
    std::fstream outFile;

    std::string outFileName = "text.txt";
    outFile.open( outFileName );

    if( outFile.is_open() )
    {
        outFile << "Turkey's population: ";
        outFile << 84780000 << std::endl;
        outFile << "Germany's population: ";
        outFile << 67750000 << std::endl;
        outFile.close();
    }
    else
    {
        std::cout << "File could not created: " << outFileName << std::endl;
    }

    return 0;
}