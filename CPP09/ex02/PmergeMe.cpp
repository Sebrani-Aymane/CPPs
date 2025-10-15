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
bool PmergeMe::is_sorted(std::vector<unsigned long long> &data)
{
    for (size_t i=0;i <data.size();i++)
    {
        if (i+1<data.size() &&data[i+1]<data[i])
           return false;
    }
    return true;
}

std::vector<int> generate_jacobsthal_order(int n) {
    std::vector<int> order;
    if (n <= 0) return order;

    std::vector<int> jac;
    jac.push_back(0);
    if (n > 1) jac.push_back(1);
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
void PmergeMe::parse_data(std::vector<unsigned long long> &data, int *pairs)
{
    if (!pairs || *pairs < 1) return;
    if (data.size() <= 1 || is_sorted(data)) return;
    
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
    if (pair_sz * 2 <= datasize / 2) {
        *pairs *= 2;
        parse_data(data, pairs);
    }
}
void PmergeMe::handle_mid(std::vector<unsigned long long> &data, int *pairs)
{
    if (data.size() <= 1 || is_sorted(data))
        return;

    int pair_sz = *pairs;
    if (pair_sz > static_cast<int>(data.size() / 2)) {
        pair_sz = static_cast<int>(data.size() / 2);
        if (pair_sz < 1) return;
    }
    std::vector<unsigned long long> main_chain;
    std::vector<unsigned long long> pend;
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
    for (int i = remaining_start; i < static_cast<int>(data.size()); ++i)
        pend.push_back(data[i]);
    data = main_chain;
    if (!pend.empty()) {
        data.insert(data.begin(), pend[0]);
        std::vector<int> insertion_order = generate_jacobsthal_order(static_cast<int>(pend.size()));
        for (std::vector<int>::size_type idx = 0; idx < insertion_order.size(); ++idx) {
            int pend_index = insertion_order[idx];
            if (pend_index == 0)
                continue;
            std::vector<unsigned long long>::iterator it =
                std::lower_bound(data.begin(), data.end(), pend[pend_index]);
            data.insert(it, pend[pend_index]);
        }
    }

    if (pair_sz > 1 && !is_sorted(data)) {
        *pairs = pair_sz / 2;
        handle_mid(data, pairs);
    }
}
