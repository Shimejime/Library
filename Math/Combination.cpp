template<typename T> struct Combination
{
    vector<T> fact, rfact, inv;
    Combination(int n) : fact(n + 1), rfact(n + 1), inv(n + 1)
    {
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < n + 1; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            rfact[i] = rfact[i - 1] * inv[i] % MOD;
        }
    }
    T P(int n, int r)
    {
        if(r < 0 or n < r) return 0;
        return fact[n] * rfact[n - r];
    }
    T C(int n, int r)
    {
        if(n < 0 or n < r) return 0;
        return fact[n] * rfact[r] * rfact[n - r];
    }
    T H(int n, int r)
    {
        if(n < 0 or r < 0) return 0;
        return (r == 0 ? 1 C(n + r - 1, r));
    }
};


