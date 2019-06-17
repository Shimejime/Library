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
#include <complex>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;

const double EPS = 1e-8;
const double PI = acos(-1);
inline bool equals(double a, double b) { return abs(b - a) < EPS; }
using Point = complex<double>;

inline Point rotate(double theta, const Point &p) { return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag()); }
inline double to_degree(double rad) { return (rad * 180.0 / PI); }
inline double to_radian(double deg) { return (deg * PI / 180.0); }
ostream &operator<<(ostream &os, Point &p) { os << p.real() << " " << p.imag(); }
namespace std { bool operator < (const Point &a, const Point &b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } }
inline double dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }
inline double cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }

struct Line
{
    Point a, b;
    Line(Point a, Point b) : a(a), b(b) {}
};
struct Segment : Line { Segment(Point a, Point b) : Line(a, b) {} };
struct Circle
{
    Point p; double r;
    Circle(Point p, double r) : p(p), r(r) {}
};

inline bool isParallel(const Line &a, const Line &b) { return equals(cross(a.b - a.a, b.b - b.a), 0.0); }
inline bool isOrthogonal(const Line &a, const Line &b) { return equals(dot(a.a - a.b, b.a - b.b), 0.0); }
template<typename T = Line>
inline Point getProjection(const T &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
inline Point getReflection(const Line &l, const Point &p) { return p + (getProjection(l, p) - p) * 2.0; }
//位置関係
inline int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return 1;
    if(cross(b, c) < -EPS) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
//点、直線、線分の交差
inline bool isIntersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }
inline bool isIntersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }
inline bool isIntersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
inline bool isIntersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }
inline bool isIntersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }
//距離
inline double getDistance(const Point &a, const Point &b) { return abs(a - b); }
inline double getDistance(const Line &l, const Point &p) { return abs(p - getProjection(l, p)); }
inline double getDistance(const Segment &s, const Point &p)
{
    Point r = getProjection(s, p);
    if(isIntersect(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
inline double getDistance(const Line &l, const Line &m) { return isIntersect(l, m) ? 0 : getDistance(l, m.a); }
inline double getDistance(const Segment &s1, const Segment &s2)
{
    if(isIntersect(s1, s2)) return 0;
    return min({getDistance(s1, s2.a), getDistance(s1, s2.b), getDistance(s2, s1.a), getDistance(s2, s1.b)});
}
inline double getDistance(const Line &l, const Segment &s)
{
    if(isIntersect(l, s)) return 0;
    return min(getDistance(l, s.a), getDistance(l, s.b));
}
inline bool isIntersect(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < EPS; }
inline bool isIntersect(const Circle &c, const Line &l) { return getDistance(l, c.p) <= c.r + EPS; }
inline int isIntersect(const Circle &c, const Segment &l)
{
    if(norm(getProjection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    const Point h = getProjection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}
//２つの円の共通接線の数
inline int isIntersect(Circle c1, Circle c2)
{
    if(c1.r < c2.r) swap(c1, c2);
    double d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4; //離れている
    if(equals(c1.r + c2.r, d)) return 3; //外接する
    if(c1.r - c2.r < d) return 2;//交わる
    if(equals(c1.r - c2.r, d)) return 1;//内接する
    return 0;//どちらかが内包する
}
//交差する点
inline Point getCrossPoint(const Line &l, const Line &m)
{
    double a = cross(l.b - l.a, m.b - m.a), b = cross(l.b - l.a, l.b - m.a);
    if(equals(abs(a), 0.0) and equals(abs(b), 0.0)) return m.a;
    return m.a + (m.b - m.a) * b / a;
}
inline Point getCrossPoint(const Segment &l, const Segment &m) { return getCrossPoint(Line(l), Line(m)); }
// 円と直線の交点
inline pair<Point, Point> getCrossPoint(const Circle &c, const Line l)
{
    assert(isIntersect(c, l));
    Point pr = getProjection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    if(equals(getDistance(l, c.p), c.r)) return make_pair(pr, pr);
    double base = sqrt(c.r * c.r - norm(pr - c.p));
    return make_pair(pr - e * base, pr + e * base);
}
//円と線分の交点
inline pair<Point, Point> getCrossPoint(const Circle &c, const Segment &l)
{
    Line aa = Line(l.a, l.b);
    if(isIntersect(c, l) == 2) return getCrossPoint(c, aa);
    auto res = getCrossPoint(c, aa);
    if(dot(l.a - res.first, l.b - res.first) < 0) res.second = res.first;
    else res.first = res.second;
    return res;
}
inline pair<Point, Point > getCrossPoint(const Circle &c1, const Circle &c2)
{
    double d = abs(c1.p - c2.p);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return make_pair(p1, p2);
}
//円と点の接線
inline pair<Point, Point> getTangent(const Circle &c1, const Point &p2) { return getCrossPoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r))); }
//多角形の面積
inline double getArea(const vector<Point> &pol)
{
    double res = 0.0; int sz = pol.size();
    for(int i = 0; i < sz; i++) res += cross(pol[i], pol[(i + 1) % sz]);
    return res / 2.0;
}
//凸多角形か
inline bool isConvex(const vector<Point> &pol)
{
    int sz = (int)pol.size();
    for(int i = 0; i < sz; i++) { if(ccw(pol[(i + sz - 1) % sz], pol[i], pol[(i + 1) % sz]) == -1) return false; }
    return true;
}
// 点と多角形の包含関係
inline int isContain(const vector<Point> &pol, const Point &p)
{
    int sz = (int)pol.size();
    int isIn = 0;
    for(int i = 0; i <sz; ++i)
    {
        Point a = pol[i] - p, b = pol[(i + 1) % sz] - p;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 && b.imag() > 0) if (cross(a, b) < 0) isIn = 1 - isIn;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return 1; //on
    }
    return (isIn ? 2 : 0);
}
inline vector<Point> convex_hull(vector<Point> &pol)
{
    int sz = (int)pol.size(), k = 0;
    if(sz <= 2) return pol;
    sort(pol.begin(), pol.end());
    vector<Point> res(2 * sz);
    for(int i = 0; i < sz; res[k++] = pol[i++]) { while(k >= 2 && cross(res[k - 1] - res[k - 2], pol[i] - res[k - 1]) < 0) k--; }
    for(int i = sz - 2, t = k + 1; i >= 0; res[k++] = pol[i--]) { while(k >= t && cross(res[k - 1] - res[k - 2], pol[i] - res[k - 1]) < 0) k--; }
    res.resize(k - 1);
    return res;
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}


