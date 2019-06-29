template<typename T> struct edge
{
    int to; T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};
template<typename T>
using Gragh = vector<vector<edge<T>>>;
template<typename T> vector<T> dijkstra(Gragh<T> &G, int s)
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
