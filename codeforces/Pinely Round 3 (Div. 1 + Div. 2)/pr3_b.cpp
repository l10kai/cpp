#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
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
