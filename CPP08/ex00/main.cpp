
#include "easyfind.hpp"

template <typename T>
void getIndex(T&data,int n)
{
    int count = 0;
    for( typename T::iterator it= data.begin() ; it != data.end();it++)
    {
        count++;
        if(*it == n)
        {
            std::cout << " was found at index " << count << std::endl;
            return;
        }
    }
    std::cout << n <<" wasn t found..." << std::endl;
}
int main()
{
    std::cout << "-Testing on vectors-"<<std::endl;
    std::vector<int>data;
    data.push_back(5);
    data.push_back(60);
    std::vector<int>::iterator it = easyfind(data, 60);
    if ( it != data.end())
        std::cout << *it;
    getIndex(data,60);
    
    std::cout << "-Testing on lists-"<<std::endl;
    std::list< int> f;
    f.push_back(0);
    f.push_back(100);
    std::list<int>::iterator itt = easyfind(f,0);
    if ( itt != f.end())
        std::cout << "the value "<< *itt;
    getIndex(f,0);

}
