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


