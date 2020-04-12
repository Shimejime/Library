// int MOD = (int)1e9 + 7;
template <typename T>
T mod_pow(T x, T n, const T mod=MOD)
{
    T res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            (ret *= x) %= p;
        }
        (x *= x) %= p;
        n >>= 1;
    }
    return res;
}
