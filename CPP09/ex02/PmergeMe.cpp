#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this!=&other)
    {
        this->data=other.data;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

