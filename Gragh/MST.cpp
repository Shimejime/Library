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

template<typename T> struct edge
{
    int to; T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};
template<typename T>
using Gragh = vector<vector<edge<T>>>;

template<typename T> T MST(Gragh<T> &G)
{
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> used(G.size(), 0);
    T res = 0;
    que.push(make_pair(0, 0));
    while(que.size())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if(used[v]) continue;
        used[v] = 1;
        res += p.first;
        for(auto &u : G[v])
        {
            if(used[u.to]) continue;
            que.push(make_pair(u.cost, u.to));
        }
    }
    return res;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E; cin >> V >> E;
    Gragh<int> G(V);
    for(int i = 0; i < E; i++)
    {
        int s, t, w; cin >> s >> t >> w;
        G[s].emplace_back(t, w);
        G[t].emplace_back(s, w);
    }
    cout << MST(G) << endl;
    return 0;
}


