#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template <typename Monoid>
class SegmentTree 
{
    using F = function<Monoid(Monoid, Monoid)>;
private:
    vector<Monoid> node;
    int N = 1;
    const F func;
    const Monoid init_value;

public:
    SegmentTree() = default;
    SegmentTree(const int& sz, const F func, const Monoid &init_value) : func(func), init_value(init_value)
    {
        while (N < sz)
            N *= 2;
        node.assign(2 * N - 1, init_value);
    }
    void update(int k, const Monoid& x)
    {
        k += N - 1;
        node[k] = x;
        while (k > 0)
        {
            k = (k - 1) / 2;
            node[k] = func(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    Monoid query(int s, int t, int k, int l, int r)
    {
        if (r <= s or t <= l)
            return init_value;
        if (s <= l and r <= t)
            return node[k];
        int mid = (l + r) / 2;
        Monoid a = query(s, t, 2 * k + 1, l, mid);
        Monoid b = query(s, t, 2 * k + 2, mid, r);
        return func(a, b);
    }
    Monoid query(int s, int t) { return query(s, t, 0, 0, N); }
};


int main()
{
    int64_t n, q; cin >> n >> q;
    SegmentTree<int64_t> seg(n, [](int64_t a, int64_t b) { return min(a, b); }, 2147483647);
    while(q--)
    {
        int64_t com, x, y; cin >> com >> x >> y;
        if(com == 0) seg.update(x, y);
        else cout << seg.query(x, y + 1) << endl;
    }
}
