auto insert = [&](i64 x1, i64 y1, i64 x2, i64 y2, i64 c,
                  vector<vector<i64>> &b) {
  b[x1][y1] += c;
  b[x2 + 1][y1] -= c;
  b[x1][y2 + 1] -= c;
  b[x2 + 1][y2 + 1] += c;
};

auto TD_prefix_and = [&](vector<vector<i64>> &b) {
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
};
