#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

using i64 = long long;

const char &ln = '\n';

signed main() {
  i64 n;
  cin >> n;

  i64 l = 0, r = 1e9;

  auto check = [&](i64 x) {
    i64 res = x;

    while (x >= 3) {
      i64 t = x / 3;
      res += t;

      x -= t * 3;
      x += t;
    }

    if (res >= n)
      return true;

    return false;
  };

  while (l < r) {
    i64 mid = l + r >> 1;

    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }

  cout << r << ln;
}
