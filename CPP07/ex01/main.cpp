#include "iter.hpp"


template< typename T >
void print( T& x)
{
  std::cout << x << std::endl;
  return;
}
int main() {
  std::cout << "**********INT TEST*********" <<std::endl;
  int tab[] = { 0, 1, 2, 3, 4 ,5,10,100,200};
  iter( tab,sizeof(tab)/sizeof(int) , print<int>);
  std::cout << "*****************************" <<std::endl;

  std::cout << "**********STRING TEST*********" <<std::endl;
  std::string str[] = { "hello","heeey","1337"};
  iter( &str[0],3, print<std::string>);
  std::cout << "*****************************" <<std::endl;
  return 0;
}