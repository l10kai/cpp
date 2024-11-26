#include <bits/stdc++.h>

using namespace std;

// const int N = 1010;

// int mp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int sum = 0, sa = 0, sb = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int t;
      cin >> t;
      sum += t;

      if (i + j <= n / 2 - 1)
        sa += t;
      if (i + j >= 2 * n - n / 2 - 1)
        sb += t;
    }
  cout << sa << " " << sum - sa - sb << " " << sb;
}
