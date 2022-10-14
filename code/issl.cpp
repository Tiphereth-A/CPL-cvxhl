// 判断两直线是否有交点
bool chkLL(Point p1, Point p2, Point q1, Point q2) {
  double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
  return sign(a1 + a2) != 0;
}

// 计算不重合的两直线的交点
Point isLL(Point p1, Point p2, Point q1, Point q2) {
  double a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
  return (p1 * a2 + p2 * a1) / (a1 + a2);
}

// 计算不重合的两直线的交点
Point isLL(Line l1, Line l2) { return isLL(l1[0], l1[1], l2[0], l2[1]); }

// 判断两个区间是否相交
bool intersect(double l1, double r1, double l2, double r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);
  return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

// 判断两线段是否有交点
bool isSS(Point p1, Point p2, Point q1, Point q2) {
  return intersect(p1.x, p2.x, q1.x, q2.x) &&
         intersect(p1.y, p2.y, q1.y, q2.y) &&
         crossOp(p1, p2, q1) * crossOp(p1, p2, q2) <= 0 &&
         crossOp(q1, q2, p1) * crossOp(q1, q2, p2) <= 0;
}

// 判断两线段是否有交点 (不包括端点)
bool isSS_strict(Point p1, Point p2, Point q1, Point q2) {
  return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 &&
         crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
}
