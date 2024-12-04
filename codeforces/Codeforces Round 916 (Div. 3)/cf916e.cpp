#include <bits/stdc++.h>
#include <vector>

using namespace std;

using i64 = long long;

struct node {
  i64 c, a, b;
};

bool cmp(node a, node b) { return a.c > b.c; }

void solve() {
  int n;
  cin >> n;

  vector<node> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i].a;
  for (int i = 0; i < n; i++)
    cin >> v[i].b;

  for (int i = 0; i < n; i++)
    v[i].c = v[i].a + v[i].b;

  sort(v.begin(), v.end(), cmp);

  i64 res = 0;

  for (int i = 0; i < n; i++) {
    (i + 1) & 1 ? res += --v[i].a : res -= --v[i].b;
  }
  cout << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
