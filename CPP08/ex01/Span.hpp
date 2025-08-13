#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>


class Span{
private:
unsigned int N;
unsigned int index;
std::vector<int> elements;

Span();
Span(unsigned int value);
~Span();
Span(const Span &other);
Span &operator=(const Span& other);

void addNumber(int value);
void addNumbers(int *values);
int shortestSpan();
int longestSpan();
 class OutOfRange: public std::exception {
        public:
            const char* what() const throw();
    };
    class NotEnoughElements: public std::exception {
        public:
            const char* what() const throw() ;
    };
};

#endif