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
template<typename Iterator>
//O(n ^ k)ぐらい
inline bool next_combination(const Iterator s, Iterator k, const Iterator t)
{
    if((s == t) or (s == k) or (k == t)) return false;
    Iterator itr1 = s, itr2 = t; itr1++;
    if(itr1 == t) return false;
    itr1 = t; itr1--; itr1 = k;
    itr2--;
    while(s != itr1)
    {
        if(*(--itr1) < *itr2)
        {
            Iterator j = k;
            while(not (*itr1 < *j)) j++;
            iter_swap(itr1, j);
            itr1++; j++;
            itr2 = k;
            rotate(itr1, j, t);
            while(t != j) j++, itr2++;
            rotate(k, itr2, t);
            return true;
        }
    }
    rotate(s, k, t);
    return false;
}
inline int next_combination(int sub)
{
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n = 5;
    int k = 3;
    for (int bit = (1<<k) - 1 ;bit < (1<<n); bit = next_combination(bit))
    {
        vector<int> S;
        for (int i = 0; i < n; ++i) if (bit & (1<<i)) S.push_back(i);
        for (int i = 0; i < (int)S.size(); ++i) cout << S[i] << " "; cout << endl;
    }
    cout << endl;
    vector<int> num(5);
    iota(num.begin(), num.end(), 0);
    do
    {
        for(int i = 0; i < k; i++) cout << num[i] << " "; cout << endl;
    }
    while(next_combination(num.begin(), num.begin() + k, num.end()));
    return 0;
}


