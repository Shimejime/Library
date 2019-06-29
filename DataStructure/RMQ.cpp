template<typename T> class RMQ
{
    private:
        vector<T> node;
        int N = 1;
    public:
        RMQ() = default;
        RMQ(int sz)
        {
            while(N < sz) N *= 2;
            node.assign(2 * N - 1, INF);
        }
        void update(int k, T x)
        {
            k += N - 1;
            node[k] = x;
            while(k > 0)
            {
                k = (k - 1) / 2;
                node[k] = min(node[2 * k + 1], node[2 * k + 2]);
            }
        }
        T query(int s, int t, int k, int l, int r)
        {
            if(r <= s or t <= l) return INF;
            if(s <= l and r <= t) return node[k];
            int mid  = (l + r) / 2;
            T a = query(s, t, 2 * k + 1, l, mid);
            T b = query(s, t, 2 * k + 2, mid, r);
            return min(a, b);
        }
        T query(int s, int t) { return query(s, t, 0, 0, N); }
};

