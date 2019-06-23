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
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
//文字列Sの中から文字列Tと一致する位置を返す
vector<int> RollingHash(const string &s, const string &t)
{
    using ull = unsigned long long;
    int s_len = s.size(), t_len = t.size();
    if(s_len < t_len) return vector<int>();
    ull ss = 1;
    for(int i = 0; i < t_len; i++) ss *= MOD;
    ull s_hash = 0, t_hash = 0;
    for(int i = 0; i < t_len; i++) s_hash = s_hash * MOD + s[i];
    for(int i = 0; i < t_len; i++) t_hash = t_hash * MOD + t[i];
    vector<int> res;
    for(int i = 0; i + t_len <= s_len; i++)
    {
        if(s_hash == t_hash) res.push_back(i);
        if(i + t_len < s_len) s_hash = s_hash * MOD + s[i + t_len] - s[i] * ss;
    }
    return res;
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    vector<int> ans = RollingHash(s, t);
    for(int &x : ans) cout << x << endl;
    return 0;
}


