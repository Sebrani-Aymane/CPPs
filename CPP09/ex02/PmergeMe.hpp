#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <ctime>

class PmergeMe{
    private:
        std::vector<unsigned long long> data;
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();


};

#endif