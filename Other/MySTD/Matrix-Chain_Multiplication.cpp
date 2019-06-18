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
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int rc[110];
    for(int i = 1; i <= n; i++) cin >> rc[i - 1] >> rc[i];
    int dp[110][110];
    for(int i = 0; i < 110; i++) for(int j = 0; j < 110; j++) dp[i][j] = INF;
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int alpha = 2; alpha <= n; alpha++)
    {
        for(int l = 1; l <= n - alpha + 1; l++)
        {
            int r = l + alpha - 1;
            for(int k = l; k <= r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + rc[l - 1] * rc[k] * rc[r]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}