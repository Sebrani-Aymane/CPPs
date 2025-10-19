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
    jac.push_back(1);
    while (true) {
        size_t next = jac.back() + 2 * jac[jac.size() - 2];
        if (next >= static_cast<size_t>(n))
            break;
        jac.push_back(next);
    }
    
    for (size_t i = 2; i < jac.size(); ++i) {
        size_t current = jac[i];
        size_t prev = jac[i - 1];
        for (int k = static_cast<int>(current); k > static_cast<int>(prev); --k) {
            if (k < n) {
                order.push_back(k);
            }
        }
    }
    if (!jac.empty()) {
        size_t last_jac = jac.back();
        for (int k = n - 1; k > static_cast<int>(last_jac); --k) {
            order.push_back(k);
        }
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
    for (int b = 0; b < complete_blocks; b++) {
        int base = b * block_sz;
        int j;
        for (j = 0; j < pair_sz; j++)
            main_chain.push_back(data[base + pair_sz + j]);
        for (j = 0; j < pair_sz; j++)
            pend.push_back(data[base + j]);
    }
    int remaining_start = complete_blocks * block_sz;
    for (size_t i = remaining_start; i < data.size(); i++)
        pend.push_back(data[i]);
    if (pair_sz == 1 && !main_chain.empty() && main_chain.size() > 1) {
        int sub_pairs = 1;  
        parse_data(main_chain, &sub_pairs);
    }
    data = main_chain;
    if (pend.size() > 0) {
        typename T::iterator it = std::lower_bound(data.begin(), data.end(), pend[0]);
        data.insert(it, pend[0]);
        
        if (pend.size() > 1) {
            T insertion_order = generate_jacobsthal_order<T>(static_cast<int>(pend.size()));
            for (size_t idx = 0; idx < insertion_order.size(); ++idx) {
                int pend_index = insertion_order[idx];
                if (pend_index > 0 && pend_index < static_cast<int>(pend.size())) {
                    typename T::iterator pos = std::lower_bound(data.begin(), data.end(), pend[pend_index]);
                    data.insert(pos, pend[pend_index]);
                }
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
    std::vector <unsigned long> data;
    std::deque<unsigned long> dataq;
    try
    {
        for (int i=1;i<ac;i++)
        {
            char *ptr;
            unsigned long num = std::strtoul(av[i],&ptr,10);
            if (*ptr != '\0'|| num > UINT_MAX)
            {
                throw std::invalid_argument("error invalid args");
            }
            data.push_back(num);
            dataq.push_back(num);
        }
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
        return 1;
    }
    std::cout<<"before:"<<std::endl;
    std::vector <unsigned long> temp = data;

    for (size_t i=0;i<temp.size();i++)
    {
        std::cout << temp[i];
        if(i + 1 < temp.size())
            std::cout << ", ";
    }
    std::cout << std::endl;
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
    time_taken = (double)(end - start)/10000 ;
    time_takenq = (double)(endq - startq) /10000 ;
    std::cout<<"vector after "<<time_taken<<" us sorting "<<temp.size()<<" elements:" <<std::endl;
    for(size_t i=0;i<data.size();i++)
    {
        std::cout <<data[i]<< " ";
    }
    std::cout <<std::endl;
    std::cout <<"====\nlist after "<<time_takenq<<" us sorting "<<temp.size()<<" elements:" <<std::endl;
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