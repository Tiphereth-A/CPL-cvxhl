vector<Point> halfPlaneIS(vector<Line> &l) {
  auto check = [](Line u, Line v, Line w) -> bool {
    return w.include(isLL(u, v));
  };

  sort(l.begin(), l.end());
  deque<Line> q;
  for (size_t i = 0; i < l.size(); ++i) {
    if (i && sameDir(l[i], l[i - 1])) continue;
    while (q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i]))
      q.pop_back();
    while (q.size() > 1 && !check(q[1], q[0], l[i]))
      q.pop_front();
    q.push_back(l[i]);
  }
  while (q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0]))
    q.pop_back();
  while (q.size() > 2 && !check(q[1], q[0], q[q.size() - 1]))
    q.pop_front();
  vector<Point> ret;
  for (size_t i = 0; i < q.size(); ++i)
    ret.push_back(isLL(q[i], q[(i + 1) % q.size()]));
  return ret;
}