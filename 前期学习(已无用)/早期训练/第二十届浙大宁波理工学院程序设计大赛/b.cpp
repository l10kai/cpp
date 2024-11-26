#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  string str;

  cin >> str;

  for (int i = 0; i < n; i += 2) {
    if (str[i] <= 'z' && str[i] >= 'a')
      str[i] -= 32;
    else
      str[i] += 32;
  }
  cout << str;
}
