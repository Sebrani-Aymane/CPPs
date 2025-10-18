#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "PmergeMe.hpp"
#include <stdexcept>
#include <climits>
#include <deque>
#include <ctime>
#include <cmath>

template <typename T>
T generate_jacobsthal_order(int n) {
    T order;
    if (n <= 0) 
        return order;
    std::vector<size_t> jac;
    jac.push_back(0);
    if (n > 1) 
        jac.push_back(1);
    while (true) {
        int next = jac.back() + 2 * jac[jac.size() - 2];
        if (next >= n) break;
        jac.push_back(next);
    }
    int prev = n;
    for (int i = jac.size() - 1; i >= 0; --i) {
        int j = jac[i];
        for (int k = prev - 1; k >= j; --k) {
            order.push_back(k);
        }
        prev = j;
    }
    return order;
}
template <typename T>
bool is_sorted(T &data)
{
    for (size_t i=0;i <data.size();i++)
    {
        if (i+1<data.size() &&data[i+1]<data[i])
           return false;
    }
    return true;
}

template <typename T>
void parse_data(T  &data, int *pairs)
{
    if (!pairs || *pairs < 1)
        return;
    if (data.size() <= 1 || is_sorted(data)) 
        return;
    int pair_sz = (*pairs);
    int datasize = data.size();
    if (pair_sz > datasize / 2) {
        *pairs = datasize / 2;
        if (*pairs < 1)
            return;
    pair_sz = *pairs;
    }
    for (int i = 0; i + 2 * pair_sz <=datasize; i += 2 * pair_sz)
    {
        int left_end = i + pair_sz - 1;
        int right_end = i + 2 * pair_sz - 1;
        
        if (data[left_end] > data[right_end])
        {
            for (int j = 0; j < pair_sz; j++)
                std::swap(data[i + j], data[i + pair_sz + j]);
        }
    }
    if (pair_sz * 2 < datasize / 2 && !is_sorted(data) && pair_sz * 2 < datasize) {
        *pairs *= 2;
        parse_data(data, pairs);
    }
    T main_chain;
    T pend;
    int block_sz = 2 * pair_sz;
    int complete_blocks = static_cast<int>(data.size()) / block_sz;
    for (int b = 0; b < complete_blocks; ++b) {
        int base = b * block_sz;
        int j;
        for (j = 0; j < pair_sz; ++j)
            main_chain.push_back(data[base + pair_sz + j]);
        for (j = 0; j < pair_sz; ++j)
            pend.push_back(data[base + j]);
    }
    int remaining_start = complete_blocks * block_sz;
    for (size_t i = remaining_start; i < data.size(); ++i)
        pend.push_back(data[i]);
    if (pair_sz == 1 && !main_chain.empty() && main_chain.size() > 1) {
        int sub_pairs = 1;  
        parse_data(main_chain, &sub_pairs);
    }
    data = main_chain;
    if (pend.size()>1) {
        data.insert(data.begin(), pend[0]);
        T  insertion_order = generate_jacobsthal_order<T>(static_cast<int>(pend.size()));
        for (size_t idx = 0; idx < insertion_order.size(); ++idx) {
            int pend_index = insertion_order[idx];
            if (pend_index == 0)
                continue;
            if (pend_index >= 0 && pend_index < static_cast<int>(pend.size())) {
                typename T::iterator it = std::lower_bound(data.begin(), data.end(), pend[pend_index]);
                data.insert(it, pend[pend_index]);
            }
        }
    }
    
}

int main(int ac,char **av)
{
    if (ac<=1)
    {
         return (std::cout <<"ERROR"<<std::endl,0);
    }
    std::vector <unsigned long long> data;
    std::deque<unsigned long long> dataq;
    try
    {
        for (int i=1;i<ac;i++)
        {
            char *ptr;
            unsigned long long num = std::strtoull(av[i],&ptr,10);
            if (*ptr != '\0'|| num > UINT_MAX)
            {
                throw std::invalid_argument("error invalid args");
            }
            if (i==1)
                std::cout <<"before \n";
            std::cout <<num<<" ";
            data.push_back(num);
            dataq.push_back(num);
        }
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
        return 1;
    }
    std::clock_t start, end ,startq,endq;
    double time_taken;
    double time_takenq;
    if (is_sorted(data) || is_sorted(dataq))
        return (std::cout <<"ur data is sorted "<<std::endl,1);
    std::cout <<std::endl;
    int pairs=1,pairss=1;
    start=std::clock();
    parse_data(data,&pairs);
    end=std::clock();
    startq=std::clock();
    parse_data(dataq,&pairss);
    endq=std::clock();
    time_taken = (double)(end - start)/1000000 ;
    time_takenq = (double)(endq - startq) /1000000 ;
    std::cout<<"vector after "<<time_taken<<" us sorting "<<data.size()<<" elements:" <<std::endl;
    for(size_t i=0;i<data.size();i++)
    {
        std::cout <<data[i]<< " ";
    }
    std::cout <<std::endl;
    std::cout <<"====\nlist after "<<time_takenq<<" us sorting "<<dataq.size()<<" elements:" <<std::endl;
    for(size_t i=0;i<dataq.size();i++)
    {
        std::cout <<dataq[i]<< " ";
    }
    std::cout <<std::endl;
    if (is_sorted(data) && is_sorted(dataq))
        std::cout <<"ur data is sorted "<<std::endl;
    else
        std::cout <<"ERROR: data not sorted!"<<std::endl;
    return 0;
}