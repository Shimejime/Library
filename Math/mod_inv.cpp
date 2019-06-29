template<typename T> T mod_inv(T a, T mod)
{
    T b = mod, u = 1, v = 0;
    while(b > 0)
    {
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if(u < 0) u += mod;
    return u;
}


