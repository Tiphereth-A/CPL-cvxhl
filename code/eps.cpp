#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1, p2, p3) sign(cross(p1, p2, p3))

const double EPS = 1e-9;
inline int sign(double a) { return a < -EPS ? -1 : a > EPS; }
inline int cmp(double a, double b) { return sign(a - b); }
