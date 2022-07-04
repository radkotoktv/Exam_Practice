#include <iostream>
#include <fstream>
int main()
{
    // _________________________________________________________________________________________
    std::ofstream binaryFileOut("numbers.bin", std::ios::binary); // makes a binary file;
    binaryFileOut.seekp(0); // sets "put" pointer to beginning of file (to position 0);
    if (!binaryFileOut.is_open()) // tests if the file has opened correctly;
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 5; ++i)
    {
        int number = i + 1;
        // casting to const char*;
        // sizeof - size in bytes;
        binaryFileOut.write(reinterpret_cast<const char*>(&number), sizeof(number));
        // 1 char = 1 byte -> array of chars = array of bytes;
        // 1 int = 2 or 4 bytes (array of bytes);
    }
    binaryFileOut.close(); //always close the file after you're done with it;
    // _________________________________________________________________________________________
    std::ifstream binaryFileIn("numbers.bin", std::ios::binary);
    if (!binaryFileIn.is_open()) // tests if the file has opened correctly;
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }
    binaryFileIn.seekg(0, std::ios::end); // setting the "get" pointer to the end of the file;
    
    std::size_t endOfFile = binaryFileIn.tellg(); // saving the position of the end of the file;

    binaryFileIn.seekg(0, std::ios::beg); // moving back to the beginning of the file;

    while (binaryFileIn.tellg() < endOfFile) // reading until end of file
    {
        int number;

        //casting to char*
        binaryFileIn.read(reinterpret_cast<char*>(&number), sizeof(number));
        std::cout << number << " ";
    }
    std::cout << std::endl;
    binaryFileIn.close(); // always close the file after you're done with it;
    
    return 0;
}