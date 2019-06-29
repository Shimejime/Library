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


