// 线段 / 直线
struct Line {
  // 始点为 ps[0], 终点为 ps[1]
  Point ps[2];
  Line(Point a, Point b) {
    ps[0] = a;
    ps[1] = b;
  }
  Point &operator[](int i) { return ps[i]; }

  // 方向向量
  Point dir() { return ps[1] - ps[0]; }

  // 两条直线是否平行
  friend bool parallel(Line l0, Line l1) {
    return sign(l0.dir().det(l1.dir())) == 0;
  }

  // 两条直线是否同向
  friend bool sameDir(Line l0, Line l1) {
    return parallel(l0, l1) && sign(l0.dir().dot(l1.dir())) == 1;
  }

  // 极角排序
  friend bool operator<(Line l0, Line l1) {
    auto cmp = [](Point a, Point b) -> bool {
      if (a.quad() != b.quad()) return a.quad() < b.quad();
      else return sign(a.det(b)) > 0;
    };

    if (sameDir(l0, l1)) return l1.include(l0[0]);
    else return cmp(l0.dir(), l1.dir());
  }

  // 点是否严格包含在半平面中
  bool include(Point p) { return sign((ps[1] - ps[0]).det(p - ps[0])) > 0; }
};
