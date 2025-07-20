#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <stdexcept>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

    static void convertChar(const std::string &str);
    static void convertInt(const std::string &str);
    static void convertFloat(const std::string &str);
    static void convertDouble(const std::string &str);

public:
    static void convert(const std::string &str);
};

#endif