#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>


class BitcoinExchange{
    private:
    std::map<std::string,double> data;
public:
BitcoinExchange();
BitcoinExchange(const BitcoinExchange &other);
BitcoinExchange &operator=(const BitcoinExchange &other);
~BitcoinExchange();
void parseline(std::string line);
int getclosestval();
double parsedata();
double getvalue(const std::string& date);
};

#endif