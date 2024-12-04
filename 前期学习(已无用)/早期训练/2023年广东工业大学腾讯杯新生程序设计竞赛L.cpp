#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 998244353;
const int N = 1010;
LL c[N][N];
void init() {
  for (int i = 0; i <= 1001; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
}
int main() {
  init();
  LL s3 = 1, s1 = 0, s2 = 0;
  int T;
  cin >> T;
  int pp = 0;
  while (T--) {
    int n;
    cin >> n;
    LL s[3];
    s[2] = 1;
    s[0] = 0;
    s[1] = 0;
    int op = 1;
    for (int i = n; i >= 2; i -= 2) {
      s[1 ^ op] += (c[i - 2][i / 2 - 1] + c[i - 2][i / 2]) % mod;
      s[op] += (c[i - 2][i / 2]) % mod;
      op = 1 ^ op;
    }
    cout << s[0] % mod << ' ' << s[1] % mod << ' ' << s[2] << endl;
  }
  return 0;
}
