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
template<class T>
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair<T1, T2>& p)
{
    os << p.first << " " << p.second;
    return os;
}
template< typename T >
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i);
    cout << v << endl;
    return 0;
}


