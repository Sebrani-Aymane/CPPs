#include "Span.hpp"


Span::Span():N(0),elements(0){}
Span::Span(unsigned int value):N(value),elements(0){}
Span::~Span(){}
Span::Span(const Span &other)
{
    *this = other;

}
Span &Span::operator=(const Span &other){
if (this != &other)
    {
        this->N=other.N;
        this->elements= other.elements;
    }
    return(*this);
}

void Span::addNumber(int value){
    if (this->index <N)
    {
        elements.push_back(value);
    }
    throw Span::OutOfRange();

}
const char *Span::OutOfRange::what() const throw()
{
    return "Out of range of the vector";
}

int Span::shortestSpan() {
}

int Span::longestSpan() {
    if (this->index <= 1)
        throw std::exception();
    else
        return (*(elements.end() - 1) - *(elements.begin()));
}