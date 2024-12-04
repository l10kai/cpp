auto dijkstra = [&](int s) {
  vector<i64> dis(n, 1e18);
  dis[s] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.push({0, s});

  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();

    if (d != dis[u])
      continue;

    for (auto [v, w] : v[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  return dis;
};
