#include <bits/stdc++.h>

using namespace std;

char mp[3][3];
bool bl[3][3];

string str = "ZZZ";

void dfs(int x, int y, string s) {

  if ((int)s.size() == 3) {
    str = min(s, str);
    return;
  }

  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++) {
      int xx = x + i, yy = y + j;
      if (xx >= 0 && xx <= 2 && yy >= 0 && yy <= 2 && !bl[xx][yy]) {
        bl[xx][yy] = true;
        dfs(xx, yy, s + mp[xx][yy]);
        bl[xx][yy] = false;
      }
    }
}

int main() {

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> mp[i][j];

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      dfs(i, j, "");

  cout << str << endl;

  return 0;
}
