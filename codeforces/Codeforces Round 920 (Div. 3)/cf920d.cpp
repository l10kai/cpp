/*
.______   ____    ____
|   _  \  \   \  /   /
|  |_)  |  \   \/   /
|   _  <    \_    _/
|  |_)  |     |  |
|______/      |__|
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(v) v.rbegin(), v.rend()
#define sqr(x) ((x) * (x))
#define mod 998244353
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pii pair<i64, i64>
#define pll pair<i64, i64>

namespace MATH {
template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <typename T> bool isprime(T n) {
  if (n <= 1)
    return false;
  for (T i = 2; i <= std::sqrt(n); i++)
    if (n % i == 0)
      return false;
  return true;
}
} // namespace MATH

using namespace MATH;
using namespace std;
using i64 = long long;

void solve() {
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n), b(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  sort(all(a));
  sort(all(b));
  i64 flag = 0, sum = 0;
  for (i64 i = 0; i < n; i++) {
    if (abs(a[i] - b[n - i - 1]) <= abs(a[i] - b[m - i - 1]) && flag == 0)
      sum += abs(b[m - i - 1] - a[i]);
    else {
      flag = 1;
      sum += abs(b[n - i - 1] - a[i]);
    }
  }
  cout << sum << endl;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  i64 t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
