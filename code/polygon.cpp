// 多边形面积
double area(vector<Point> ps) {
  double ret = 0;
  rep(i, 0, ps.size()) ret += ps[i].det(ps[(i + 1) % ps.size()]);
  return ret / 2;
}

// 点与多边形的关系
// 2:inside,1:on_seg,0:outside
int contain(vector<Point> ps, Point p) {
  int n = ps.size(), ret = 0;
  rep(i, 0, n) {
    Point u = ps[i], v = ps[(i + 1) % n];
    if (onSeg(u, v, p)) return 1;
    if (cmp(u.y, v.y) <= 0) swap(u, v);
    if (cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
    ret ^= crossOp(p, u, v) > 0;
  }
  return ret * 2;
}