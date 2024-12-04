#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int l = 0, r = 0, ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      l++;
    if (s[i] == ')' && l - r > 0)
      r++;
  }

  cout << r * 2;
  return 0;
}
