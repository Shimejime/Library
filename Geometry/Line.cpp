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
inline int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return 1;
    if(cross(b, c) < -EPS) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}
inline bool isIntersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }
inline bool isIntersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }
inline bool isIntersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
inline bool isIntersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }
inline bool isIntersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }
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
inline int intersect(Circle c1, Circle c2) {
    if(c1.r < c2.r) swap(c1, c2);
    double d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4;
    if(equals(c1.r + c2.r, d)) return 3;
    if(c1.r - c2.r < d) return 2;
    if(equals(c1.r - c2.r, d)) return 1;
    return 0;
}
inline Point getCrossPoint(const Line &l, const Line &m)
{
    double a = cross(l.b - l.a, m.b - m.a), b = cross(l.b - l.a, l.b - m.a);
    if(equals(abs(a), 0.0) and equals(abs(b), 0.0)) return m.a;
    return m.a + (m.b - m.a) * b / a;
}
inline Point getCrossPoint(const Segment &l, const Segment &m) { return getCrossPoint(Line(l), Line(m)); }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    return 0;
}


