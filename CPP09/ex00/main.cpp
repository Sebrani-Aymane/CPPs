
#include "BitcoinExchange.hpp"
int main(int ac,char **av)
{
    if (ac !=2)
    {
        std::cout <<"Usage <./btc inputfile.exemple>"<<std::endl;
        return 1;
    }
    BitcoinExchange btc;
    std::ifstream inputFile(av[1]);
    if (inputFile.is_open()) {
        std::string line;
        getline(inputFile,line);
        if (line != "date | value")
            {
                std::cout <<"bad file header"<<std::endl;
                inputFile.close();
                return 1;
            }
        while (getline(inputFile, line)) {
                btc.parseline(line);
        }
        inputFile.close();
    } else
        std::cout << "Failed to open the file." << std::endl;
    return 0;
}