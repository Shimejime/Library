#include <iostream>
template<typename T>
T power(const T& a, const T& x) //a^x
{
    if(x == 0) return 1;
    T res = power(a, x>>1);
    res *= res;
    if(x & 1) res *= a;
    return res;
}

int main(void)
{
    std::cout << power(2, 10) << std::endl; // 1024
    return 0;
}
