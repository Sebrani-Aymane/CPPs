#include "iter.hpp"

int main() {
 int tab[] = { 0, 1, 2, 3, 4 ,5,10,100,200};
  iter( tab,sizeof(tab)/sizeof(int) , print<const int> );
  return 0;
}