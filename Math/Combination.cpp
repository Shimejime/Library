#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;

// cf. https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

template<typename T>
struct Combination
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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<long long> c(10);
    cout << c.run(5, 2) << endl;
    cout << c.run(5, 3) << endl;
    cout << c.run(6, 3) << endl;
    return 0;
}


