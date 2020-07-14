#include <iostream>
#include <vector>
using namespace std;

template <class T>
class UnionFind
{
private:
    vector<T> data;
    int groups;

public:
    UnionFind(int sz)
    {
        data.assign(sz, -1);
        this->groups = sz;
    }
    bool unite(T x, T y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        groups--;
        return (true);
    }
    T find(T k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    T size(T k) { return (-data[find(k)]); }
    int getGroups() { return this->groups; }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    UnionFind<int> uf(N);
    while (Q--)
    {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0)
            uf.unite(x, y);
        else
            cout << (uf.find(x) == uf.find(y)) << endl;
    }
}
