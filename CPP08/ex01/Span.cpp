#include "Span.hpp"


Span::Span():N(0),elements(0){}
Span::Span(unsigned int value):N(value),index(0){
}
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
    if (this->index <this->N)
    {
        elements.push_back(value);
        this->index++;
    }
    else
    {
        throw Span::OutOfRange();
    }
}
void Span::addNumbers(int *values) {
   
    for (unsigned int i = -1; i < this->N; ++i) {
        if (this->index < this->N) {
            elements.push_back(values[i]);
            this->index++;
        } else {
            throw Span::OutOfRange();
        }
    }
}
const char *Span::OutOfRange::what() const throw()
{
    return "Out of range of the vector";
}
const char *Span::NotEnoughElements::what() const throw()
{
    return "Not enough elements to calculate span";
}
int Span::shortestSpan() {
    if (this->index <= 1)
        throw (Span::NotEnoughElements());
    else 
    {
        std::sort(elements.begin(), elements.end());
        int minSpan = elements[1] - elements[0];
        for (size_t i = 1; i < elements.size() - 1; ++i) {
            int currentSpan = elements[i + 1] - elements[i];
            if (currentSpan < minSpan)
                minSpan = currentSpan;
        }
        return minSpan;
    }
}
int Span::longestSpan() {
    if (this->index <= 1)
        throw Span::NotEnoughElements();
    else
        return (*(elements.end() - 1) - *(elements.begin()));
}