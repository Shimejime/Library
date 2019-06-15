struct Circle
{
    Point p; double r;
    Circle(Point p, double r) : p(p), r(r) {}
};
inline bool is(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < EPS; }
inline bool is(const Circle &c, const Line &l) { return getDistance(l, c.p) <= c.r + EPS; }
inline int is(const Circle &c, const Segment &l)
{
    if(norm(getProjection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
    const Point h = getProjection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}
inline int (Circle c1, Circle c2) {
    if(c1.r < c2.r) swap(c1, c2);
    double d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4;
    if(equals(c1.r + c2.r, d)) return 3;
    if(c1.r - c2.r < d) return 2;
    if(equals(c1.r - c2.r, d)) return 1;
    return 0;
}
pair<Point, Point> getCrossPoint(const Circle &c, const Line &l)
{
    Point pr = getProjection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    if(eq(distance(l, c.p), c.r)) return {pr, pr};
    double base = sqrt(c.r * c.r - norm(pr - c.p));
    return {pr - e * base, pr + e * base};
}
pair<Point, Point> getCrossPoint(const Circle &c, const Segment &l)
{
    Line aa = Line(l.a, l.b);
    if((c, l) == 2) return getCrossPoint(c, aa);
    auto ret = getCrossPoint(c, aa);
    if(dot(l.a - ret.first, l.b - ret.first) < 0) ret.second = ret.first;
    else ret.first = ret.second;
    return ret;
}
pair<Point, Point> getCrossPoint(const Circle &c1, const Circle &c2)
{
    double d = abs(c1.p - c2.p);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return {p1, p2};
}
pair<Point, Point> tangent(const Circle &c1, const Point &p2) { return getCrossPoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r))); }
Lines tangent(Circle c1, Circle c2)
{
    Lines ret;
    if(c1.r < c2.r) swap(c1, c2);
    double g = norm(c1.p - c2.p);
    if(eq(g, 0)) return ret;
    Point u = (c2.p - c1.p) / sqrt(g);
    Point v = rotate(PI * 0.5, u);
    for(int s : {-1, 1})
    {
        double h = (c1.r + s * c2.r) / sqrt(g);
        if(eq(1 - h * h, 0)) ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
        else if(1 - h * h > 0)
        {
            Point uu = u * h, vv = v * sqrt(1 - h * h);
            ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
            ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
        }
    }
    return ret;
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    return 0;
}


