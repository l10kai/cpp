#include <bits/stdc++.h>

using namespace std;

void solve() {

  string str;
  cin >> str;

  int n = str.size();

  int t = 0;
  for (int i = 1; i < n; i++) {
    if (str[i] != '0') {
      t = i;
      break;
    }
  }

  if (t && ((n % 2 == 0 && t < n / 2) || (n % 2 != 0 && t <= n / 2))) {
    for (int i = 0; i < t; i++)
      cout << str[i];
    cout << " ";
    for (int i = t; str[i]; i++)
      cout << str[i];
    cout << endl;
    return;
  }

  if (t && n % 2 == 0 && n / 2 == t) {
    string a, b;
    for (int i = 0, j = t; i < t; i++, j++)
      a += str[i], b += str[j];
    if (b > a) {
      for (int i = 0; i < t; i++)
        cout << str[i];
      cout << " ";
      for (int i = t; str[i]; i++)
        cout << str[i];
      cout << endl;

      return;
    }
  }
  cout << "-1" << endl;
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
