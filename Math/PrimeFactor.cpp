template<typename Type> map<Type, int > prime_factor(Type n)
{
    map<Type, int > res;
    for(Type i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

