#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    int res = 0;
    int dx[8] = {a, a, -a, -a, b, b, -b, -b},
        dy[8] = {b, -b, b, -b, a, -a, a, -a};
    for (int i = 0; i < 8; i++) {
      int tx = xk + dx[i], ty = yk + dy[i];
      for (int j = 0; j < 8; j++) {
        int ttx = xq + dx[j], tty = yq + dy[j];
        if (tx == ttx && ty == tty)
          res++;
      }
    }

    cout << res << endl;
  }
  return 0;
}
