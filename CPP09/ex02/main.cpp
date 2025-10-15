#include "PmergeMe.hpp"
#include <stdexcept>


int main(int ac,char **av)
{
    if (ac<=2)
    {
        std::cout <<"ERROR"<<std::endl;
    }
    std::vector <unsigned long long> data;
    try
    {

        for (int i=1;i<ac;i++)
        {
            char *ptr;
            long long numm = std::strtoull(av[i],NULL,10);
            if (numm <0)
            {
                    std::cout<<"Eroor"<<std::endl;
                    return 1 ;
            }
            unsigned long long num=std::strtoull(av[i],&ptr,10);
            if (*ptr != '\0')
            {
                std::cout<<"Eroor"<<std::endl;
                return 1;
            }
            data.push_back(num);
        }
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    PmergeMe pm;
    if (pm.is_sorted(data))
        return (std::cout <<"ur data is sorted "<<std::endl,1);
    int pairs=1;
    pm.parse_data(data,&pairs);
    pairs = data.size() / 2;
    pm.handle_mid(data,&pairs);
    for(size_t i=0;i<data.size();i++)
    {
        std::cout <<data[i]<< " ";
    }
    std::cout <<std::endl;
        return 0;
}

