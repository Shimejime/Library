//x^n mod
template<typename Type> Type power(Type x, Type n, Type mod)
{
    Type res = 1;
    while(n > 0)
    {
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}

