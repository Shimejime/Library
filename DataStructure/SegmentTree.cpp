#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
struct SegmentTree
{
    private :
        int n = 1;
        vector<int> node;
    public:
        SegmentTree(int sz)
        {
            while(n < sz) n *= 2;
            node.resize(2 * n - 1, INF);
        }
        void update(int pos, int val)
        {
            pos += (n - 1);
            node[pos] = val;
            while(pos > 0)
            {
                pos = (pos - 1) / 2;
                node[pos] = min(node[2 * pos + 1], node[2 * pos + 2]);
            }
        }
        int query(int a, int b, int pos = 0, int left = 0, int right = -1)
        {
            if(right < 0) right = n;
            if(right <= a || b <= left) return INF;
            if(a <= left && right <= b) return node[pos];
            else
            {
                int mid = (left + right) / 2;
                int vl = query(a, b, 2 * pos + 1, left, mid);
                int vr = query(a, b, 2 * pos + 2, mid, right);
                return min(vl, vr);
            }
        }
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    SegmentTree st(n);
    for(int i = 0; i < q; i++)
    {
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0) st.update(x, y);
        else cout << st.query(x, y + 1) << endl;
    }
    return 0;
}
