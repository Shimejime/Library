#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
template<class T>
ostream &operator <<(ostream& out,const vector<T>& debug)
{
    out << '[';
    for(int i = 0; i < debug.size(); i++)
    {
        out << debug[i];
        if(i != debug.size() - 1) out << ", ";
    }
    out << ']';
    return out;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i);
    cout << v << endl;
    return 0;
}


