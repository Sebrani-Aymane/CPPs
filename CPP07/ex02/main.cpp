
#include "Array.tpp"

int main()
{
    try{
        Array<char> a(3);
        Array <int> b(3);

        std::cout <<a.size()<< std::endl;
        std::cout <<b.size()<< std::endl;

        for(int i =0;a.size() - i;i++)
            a[i] = 48 + i;
        for(int i =0;a.size() - i;i++)
            std::cout << a[i] <<std::endl;
        std::cout << a[50]<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
    return 0;
}
