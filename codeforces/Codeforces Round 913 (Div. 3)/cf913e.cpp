#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int num;
    LL res = 1;
    cin >> num;
    while (num) {
      int x = num % 10;
      num /= 10;
      int t = 0;
      for (int i = 0; i <= x; i++) {
        if (i == 0)
          t += x + 1;
        else
          t += i;
      }
      res *= t;
    }
    cout << res << endl;
  }

  return 0;
}
