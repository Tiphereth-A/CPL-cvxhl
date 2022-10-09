// 判断 m 是否在区间 (a,b) 中
bool isMiddle(double a, double m, double b) {
  return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}

bool isMiddle(Point a, Point m, Point b) {
  return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}

// 判断点是否在线段上
bool onSeg(Point p1, Point p2, Point q) {
  return crossOp(p1, p2, q) == 0 && isMiddle(p1, q, p2);
}

// 判断点是否在线段上 (不包括端点)
bool onSeg_strict(Point p1, Point p2, Point q) {
  return crossOp(p1, p2, q) == 0 &&
         sign((q - p1).dot(p1 - p2)) * sign((q - p2).dot(p1 - p2)) < 0;
}
