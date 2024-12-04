#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010;

const LL maxx = 1e6 + 10, mod = 998244353;

LL c[N][N]; // 先算出来 1000内的组合数

void init() {
  for (int i = 0; i <= 1001; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
}

// 超时

// int jiecheng(int x)//阶乘代码
// {
//     int res = 1;//返回值变量
//     for (int i = x; i; i -- )//用for实现逐次减一
//         res *= i;//乘入返回值变量
//     return res;//返回
// }

// int C(int x,int y)//定义组合函数
// {
//     int ret;
//     ret=jiecheng(x)/jiecheng(x-y)/jiecheng(y);//公式
//     return ret;
// }

int main() {

  LL s3 = 1, s1 = 0, s2 = 0;
  int T;
  cin >> T;
  init();
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
      // s[1 ^ op] += (C(i - 2,i / 2 - 1) + C(i - 2,i / 2)) % mod;
      // s[op] += C(i - 2,i / 2) % mod;
      s[1 ^ op] += (c[i - 2][i / 2 - 1] + c[i - 2][i / 2]) % mod;
      s[op] += (c[i - 2][i / 2]) % mod;
      op = 1 ^ op;
    }
    cout << s[0] % mod << ' ' << s[1] % mod << ' ' << s[2] << endl;
  }
  return 0;
}
