#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& data,int n)
{
    typename T::iterator it;
    for (it=data.begin() ;it !=data.end();++it)
    {
        if (*it==n)
            return(it);
    }
    return(data.end());
}

// template <typename T>
// typename T::const_iterator easyfind( const T& data,int n)
// {
//     typename T::const_iterator  it;
//     for (it=data.begin() ;it !=data.end();++it)
//     {
//         if (*it==n)
//             return(it);
//     }
//     return(data.end());
// }
