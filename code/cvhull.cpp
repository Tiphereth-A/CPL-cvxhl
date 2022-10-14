vector<Point> convexHull(vector<Point> ps) {
  int n = ps.size();
  if (n <= 1) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> qs(n * 2);
  int k = 0;
  for (int i = 0; i < n; qs[k++] = ps[i++])
    while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
    while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
  qs.resize(k - 1);
  return qs;
}
