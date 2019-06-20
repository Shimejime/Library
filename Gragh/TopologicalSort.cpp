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
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;

struct TopologicalSort
{
    int V;
    vector<int> res, deg, used;
    vector<vector<int>> G;
    TopologicalSort(int v) : V(v)
    {
        deg.resize(V, 0);
        used.resize(V, 0);
        G.resize(V);
    }
    void add_edge(int s, int t)
    {
        G[s].push_back(t);
        deg[t]++;
    }
    void bfs(int s)
    {
        queue<int> que;
        used[s] = 1;
        que.push(s);
        while(que.size())
        {
            int v = que.front(); que.pop();
            res.push_back(v);
            for(auto &u : G[v])
            {
                if(used[u]) continue;
                deg[u]--;
                if(deg[u] == 0)
                {
                    used[u] = 1;
                    que.push(u);
                }
            }
        }
    }
    vector<int> build()
    {
        for(int i = 0; i < V; i++)
        {
            if(used[i] or deg[i] > 0) continue;
            bfs(i);
        }
        return res;
    }
};

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E; cin >> V >> E;
    TopologicalSort topolo = TopologicalSort(V);
    for(int i = 0; i < E; i++)
    {
        int s, t; cin >> s >> t;
        topolo.add_edge(s, t);
    }
    auto ans = topolo.build();
    for(auto &x : ans) cout << x << endl;
    return 0;
}


