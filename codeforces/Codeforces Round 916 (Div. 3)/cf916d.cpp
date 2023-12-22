#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

void solve() {
  int n;
  cin >> n;
  vector<PII> a, b, c;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a.push_back({t, i});
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    b.push_back({t, i});
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    c.push_back({t, i});
  }

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  int res = 0;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        if (a[i].second != b[j].second && b[j].second != c[k].second &&
            a[i].second != c[k].second) {
          res = max(res, a[i].first + b[j].first + c[k].first);
        }
      }
  cout << res << endl;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
