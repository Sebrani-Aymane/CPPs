#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <string>
#include <iostream>
#include <iomanip>
class Helpers {
public:
static int getType(const std::string &str);
    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isLiteral(const std::string &str);
    static void printFloat(float value);
    static void printDouble(double value) ;
};
#endif