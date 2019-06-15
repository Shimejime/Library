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
vector<int> A;
int sz = 1;
void init(int n)
{
    while(sz < n) sz *= 2;
    A.resize(2 * sz - 1, 0);
}
void add(int pos, int v)
{
    pos += (sz - 1);
    A[pos] += v;
    while(pos > 0)
    {
        pos = (pos - 1) / 2;
        A[pos] = A[2 * pos + 1] + A[2 * pos + 2];
    }
}
int getSum(int s, int t, int k, int l, int r)
{
    if(l >= t or r <= s) return 0;
    if(l >= s and r <= t) return A[k];
    int mid = (l + r) / 2;
    int a = getSum(s, t, 2 * k + 1, l, mid);
    int b = getSum(s, t, 2 * k + 2, mid, r);
    return a + b;
}
int getSum(int s, int t)
{
    return getSum(s, t, 0, 0, sz);
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    init(n);
    for(int i = 0; i < q; i++)
    {
        int com, x, y; cin >> com >> x >> y;
        if(com == 0) add(x - 1, y);
        else cout << getSum(x - 1, y) << endl;
    }
    return 0;
}


