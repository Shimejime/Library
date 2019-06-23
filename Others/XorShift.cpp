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
// cf. https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361
unsigned int randInt()
{
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

int randInt(int minv, int maxv)
{
    return randInt() % (maxv - minv + 1) + minv;
}
template<class T> void shuffle(vector<T>& vec)
{
    int n = vec.size();
    for (int i = n - 1; i > 0; --i)
    {
        int k = randInt() % (i + 1);
        swap(vec[i], vec[k]);
    }
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> cnt(6, 0);
    for(int i = 0; i < 100; i++)
    {
        int r = randInt() % 6;
        cnt[r]++;
    }
    for(int i = 0; i < 6; i++)
    {
        cout << i + 1 << ": " << cnt[i] << endl;
    }
    return 0;
}


