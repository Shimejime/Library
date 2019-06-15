#include <iostream>
#include <string>
#define MAX_N 110
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
int cost[MAX_N][MAX_N], mincost[MAX_N];
bool used[MAX_N];
int prim(int n)
{
    int res = 0;
    mincost[0] = 0;
    while(true)
    {
        int v = -1;
        for(int u = 0; u < n; u++)
        {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        res += mincost[v];
        for(int u = 0; u < n; u++) mincost[u] = min(mincost[u], cost[v][u]);
    }
    return res;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < MAX_N; i++) used[i] = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] == -1) cost[i][j] = INF;
        }
        mincost[i] = INF;
    }
    int ans = prim(n);
    cout << ans << endl;
    return 0;
}
