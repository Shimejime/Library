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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}


