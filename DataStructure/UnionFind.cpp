template<class Type> class UnionFind
{
    private:
        vector<Type> data;
        int groups;
    public:
        UnionFind(int sz)
        {
            data.assign(sz, -1);
            this->groups = sz;
        }
        bool unite(Type x, Type y)
        {
            x = find(x), y = find(y);
            if (x == y) return (false);
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
            groups--;
            return (true);
        }
        Type find(Type k) {
            if (data[k] < 0) return (k);
            return (data[k] = find(data[k]));
        }
        Type size(Type k) { return (-data[find(k)]); }
        int getGroups() { return this->groups; }
};
