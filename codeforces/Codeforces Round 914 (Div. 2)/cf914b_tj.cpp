#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 998244353;
#define int long long
typedef long long LL;
typedef pair<int, int> PII;
const long long inf = 1e17;
using node = tuple<int, int, int, int>;
int n, m, k;
PII a[N];
int res[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  int now = 0;
  vector<int> s(n + 10);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i].first;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    while (idx <= i) {
      now += a[idx].first;
      idx++;
    }
    while (idx <= n && now >= a[idx].first) {
      now += a[idx].first;
      idx++;
    }
    res[a[i].second] = max(0ll, idx - 2);
  }
  for (int i = 1; i <= n; i++)
    cout << res[i] << " \n"[i == n];
}

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t = 1;

  cin >> t;
  while (t--)
    solve();
}
