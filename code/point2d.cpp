// 点 / 二维向量
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point operator+(Point p) { return {x + p.x, y + p.y}; }
  Point operator-(Point p) { return {x - p.x, y - p.y}; }
  Point operator*(double d) { return {x * d, y * d}; }
  Point operator/(double d) { return {x / d, y / d}; }

  bool operator<(Point p) const {
    int c = cmp(x, p.x);
    if (c) return c == -1;
    return cmp(y, p.y) == -1;
  }

  bool operator==(Point o) const { return cmp(x, o.x) == 0 && cmp(y, o.y) == 0; }

  // 点乘
  double dot(Point p) { return x * p.x + y * p.y; }
  // 叉乘
  double det(Point p) { return x * p.y - y * p.x; }

  // 两点之间的 Euclid 距离
  double distTo(Point p) { return (*this - p).abs(); }

  // 极角 (取值参见 atan2 的文档)
  double alpha() { return atan2(y, x); }

  // 模长 (与原点的 Euclid 距离)
  double abs() { return sqrt(abs2()); }

  // 模长的平方
  double abs2() { return x * x + y * y; }

  // 逆时针旋转 pi/2
  Point rot90() { return Point(-y, x); }

  // 单位化
  Point unit() { return *this / abs(); }

  // 计算当前点处于哪个象限, 用于极角排序
  int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }

  // 逆时针旋转
  Point rot(double an) { return {x * cos(an) - y * sin(an), x * sin(an) + y * cos(an)}; }
};