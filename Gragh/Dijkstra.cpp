#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int MAX_N = 11000;
int cost[MAX_N][MAX_N], d[MAX_N];
bool used[MAX_N];
void dijkstra(int n)
{
    for(int i = 0; i <= n; i++) { d[i] = INF; used[i] = false; }
    d[0] = 0;
    while(true)
    {
        int v = -1;
        for(int u = 0; u < n; u++)
        {
            if(not used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 0; u < n; u++) d[u] = min(d[u], d[v] + cost[v][u]);
    }
    for(int i = 0; i < n; i++) cout << i << " " << d[i] << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cost[i][j] = INF;
    }
    for(int i = 0; i < n; i++)
    {
        int u, k; cin >> u >> k;
        for(int i = 0; i < k; i++)
        {
            int v, c; cin >> v >> c;
            cost[u][v] = c;
        }
    }
    dijkstra(n);
    return 0;
}
