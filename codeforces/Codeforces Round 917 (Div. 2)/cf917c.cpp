#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n + 10), v(m + 10);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> v[i];

  int ans = 0;
  // 枚举执行操作1的次数
  for (int i = 1; i <= 2 * n && i <= d; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == j)
        cnt++;
    }
    ans = max(ans, (d - i) / 2 + cnt);

    int r = ((i % m) ? i % m : m);
    for (int j = 1; j <= v[r]; j++)
      a[j]++;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
