// 点在直线上的投影
Point proj(Point p1, Point p2, Point q) {
  Point dir = p2 - p1;
  return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}

// 点关于直线的对称点
Point reflect(Point p1, Point p2, Point q) { return proj(p1, p2, q) * 2 - q; }

double nearest(Point p1, Point p2, Point q) {
  if (p1 == p2) return p1.distTo(q);
  Point h = proj(p1, p2, q);
  if (isMiddle(p1, h, p2)) return q.distTo(h);
  return min(p1.distTo(q), p2.distTo(q));
}

// 两线段间距离
double disSS(Point p1, Point p2, Point q1, Point q2) {
  if (isSS(p1, p2, q1, q2)) return 0;
  return min({nearest(p1, p2, q1), nearest(p1, p2, q2),
              nearest(q1, q2, p1), nearest(q1, q2, p2)});
}

// 两向量间的夹角
double rad(Point p1, Point p2) { return atan2l(p1.det(p2), p1.dot(p2)); }
