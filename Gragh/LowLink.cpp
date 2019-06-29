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
