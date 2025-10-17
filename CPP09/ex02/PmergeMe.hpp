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
    void parse_data(std::vector<unsigned long long> &data,int *pairs);
    void handle_mid(std::vector<unsigned long long> &data,int *pairs);
    bool is_sorted(std::vector<unsigned long long> &data);

};

#endif