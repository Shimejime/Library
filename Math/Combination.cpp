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
    T run(int n, int k)
    {
        if(n < k) return 0;
        if(n < 0 or k < 0) return 0;
        return fact[n] * (rfact[k] * rfact[n - k] % MOD) % MOD;
    }
};


