#define sqr(x) ((x) * (x))

auto add = [&](i64 x, i64 y, vector<i64> &p) {
  for (; x <= n; x += lowbit(x))
    p[x] += y;
};

auto query = [&](i64 x, vector<i64> &p) {
  int ans = 0;
  for (; x; x -= lowbit(x))
    ans += p[x];
  return ans;
};
