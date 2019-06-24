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
#include <set>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;

using Gragh = vector<vector<int>>;
struct LowLink
{
    int V;
    Gragh G;
    vector<int> used, order, lowlink, articulation;
    vector<pair<int, int>> bridges;
    LowLink(int V) : V(V)
    {
        G.resize(V);
        used.resize(V, 0);
        order.resize(V, 0);
        lowlink.resize(V, 0);
    }
    void add_edge(int s, int t) { G[s].emplace_back(t); }
    void dfs(int v, int p)
    {
        static int k = 0;
        used[v] = 1;
        order[v] = lowlink[v] = k++;
        int cnt = 0;
        bool flag = false;
        for(auto &u : G[v])
        {
            if(not used[u])
            {
                cnt++;
                dfs(u, v);
                lowlink[v] = min(lowlink[v], lowlink[u]);
                if(order[v] <= lowlink[u] and p != -1) flag = true;
                if(order[v] < lowlink[u]) bridges.emplace_back(min(v, u), max(v, u));
            }
            else if(u != p) lowlink[v] = min(lowlink[v], order[u]);
        }
        if(p == -1 and cnt > 1) flag = true;
        if(flag) articulation.push_back(v);
    }
    void build() { dfs(0, -1); }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E; cin >> V >> E;
    LowLink L(V);
    for(int i = 0; i < E; i++)
    {
        int s, t; cin >> s >> t;
        L.add_edge(s, t);
        L.add_edge(t, s);
    }
    L.build();
    sort(L.bridges.begin(), L.bridges.end());
    for(auto ans : L.bridges) cout << ans.first << " " << ans.second << endl;
    return 0;
}
