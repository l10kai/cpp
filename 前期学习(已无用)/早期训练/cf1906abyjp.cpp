#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h = 3, w = 3;
char g[3][3];
bool used[3][3];
string ans = "CCC";

void dfs(int x, int y, string S) {
  if ((int)S.size() == 3) {
    ans = min(ans, S);
    return;
  }

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int rx = x + i;
      int ry = y + j;
      if (clamp(rx, 0, 2) == rx && clamp(ry, 0, 2) == ry && !used[rx][ry]) {
        used[rx][ry] = true;
        dfs(rx, ry, S + g[rx][ry]);
        used[rx][ry] = false;
      }
    }
  }
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      dfs(i, j, "");
    }
  }

  cout << ans << '\n';
}
