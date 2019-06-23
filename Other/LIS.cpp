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
template<typename T> int LIS(vector<T> A)
{
    int n = A.size();
    vector<T> dp(n, INF);
    for(int i = 0; i < n; i++)
    {
        *lower_bound(dp.begin(), dp.end(), A[i]) = A[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    cout << LIS(A) << endl;
    return 0;
}


