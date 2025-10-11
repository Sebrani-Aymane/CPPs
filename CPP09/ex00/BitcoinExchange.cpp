#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
        *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
        if (this!=&other)
            this->data = other.data;
        return *this;
}
BitcoinExchange::~BitcoinExchange(){}

bool isLeap(int year)
{
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool parseDatevalue(std::string date,double value)
{
        while (date[0]==' ')
                date.erase(0,1);
        if (date[4]!='-'|| date[7]!='-'){
                std::cout <<"invalid date Format \"yyyy-mm-dd\""<<std::endl;
        return false;
        }
        int year = std::strtod(date.substr(0,4).c_str(),NULL);
        int month = std::strtod(date.substr(5,2).c_str(),NULL);
        int day = std::strtod(date.substr(8,2).c_str(),NULL);

        if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            std::cout << "Error: bad date input => " << date << " (Range invalid)" << std::endl;
            return false ;
        }
        int daysofmonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeap(year))
        {
            if (day > 29)
            {
                std::cout << "Error: bad date input => " << date << " (Not a valid day in leap February)" << std::endl;
                return false ;
            }
        }
        else if (day > daysofmonths[month])
        {
            std::cout << "Error: bad date input => " << date << " (Not a valid day in month)" << std::endl;
            return false ;
        }
        if (year == 2009 && month == 1 && day <2)
        {
                std::cout << "Error: date is before minimum allowed date 2009-01-02 => " << date<< std::endl;
                return false;
        }
         if (value<0)
         {
                 std::cout << "Error: not a positive number."<<std::endl;
return false;
         }
        else if (value >1000)
             {
                     std::cout <<"Error: too large a number." <<std::endl;
return false;
             }  
        return true;

}
double BitcoinExchange::parsedata()
{
        std::ifstream inputFile("data.csv");
    if (inputFile.is_open()) {
        std::string line;
        getline(inputFile,line);
        if (line != "date,exchange_rate")
        {
                std::cout <<"bad file header"<<std::endl;
                inputFile.close();
                return 1;
        }
        while (getline(inputFile, line)) {
                size_t commaPos = line.find(',');
            if (commaPos == std::string::npos)
                continue;
            
            std::string date = line.substr(0, commaPos);
            double price = std::strtod(line.substr(commaPos + 1).c_str(), NULL);
            data[date] = price;
        }
        inputFile.close();
    } else
        std::cout << "Failed to open the file." << std::endl;
    return 0;
}
double BitcoinExchange::getvalue(const std::string& date)
{

    if (data.empty())
        return -1.0;
    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if (it == data.end()) 
{
       --it;
       return it->second;
}


    if (it->first == date) {
        return it->second;
    }

    if (it == data.begin()) {
        return -1.0;
    }
    --it;
    return it->second;
}
void  BitcoinExchange::parseline(std::string line)
{
        size_t pipepos = line.find('|');
        if (pipepos == std::string::npos)
        {
                std::cout<<"Error: bad input => "<<line<<std::endl;
                return;
        }
        char *ptr;
        std::string date = line.substr(0,pipepos);
        double value  = std::strtod(line.substr(pipepos+2,line.size()-1).c_str(),&ptr);
        if (*ptr != '\0')
            return;
        if (!parseDatevalue(date,value))
                return;
        parsedata();
        std::cout << date<<" => "<< value<< " = "<<value*getvalue(date)<<std::endl;

}