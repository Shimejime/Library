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
typedef long long ll;
const int INF = 1<<30;
const int MOD = 1e9 + 7;

template<typename T> struct edge
{
    int to; T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};
template<typename T>
using Gragh = vector<vector<edge<T>>>;
template<typename T>
vector<T> dijkstra(Gragh<T> &G, int s)
{
    vector<T> dist(G.size(), INF);
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(make_pair(dist[s], s));
    while(que.size())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto &e : G[v])
        {
            if(dist[e.to] > p.first + e.cost)
            {
                dist[e.to] = p.first + e.cost;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E, r; cin >> V >> E >> r;
    Gragh<int> G(V);
    for(int i = 0; i < E; i++)
    {
        int s, t, d; cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }
    vector<int> res = dijkstra(G, r);
    for(auto &ans : res)
    {
        if(ans == INF) cout << "INF" << endl;
        else cout << ans << endl;
    }
    return 0;
}
