template<typename T> struct edge
{
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
template<typename T> using Edges = vector<edge<T>>;
template<typename T> using Gragh = vector<Edges<T>>;
template<typename T> vector<T> BellmanFord(Edges<T> &edges, const int &s, int V, int E)
{
    vector<T> dist(V, INF);
    dist[s] = 0;
    for(int i = 0; i < V; i++)
    {
        for(auto &&edge : edges)
        {
            if(dist[edge.from] == INF) continue;
            dist[edge.to] = min(dist[edge.to], dist[edge.from] + edge.cost);
        }
    }
    for(auto &&edge : edges)
    {
        if(dist[edge.from] == INF) continue;
        if(dist[edge.from] + edge.cost < dist[edge.to]) return vector<T>(); //閉路
    }
    return dist;
}


