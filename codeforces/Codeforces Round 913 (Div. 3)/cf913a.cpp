#include <bits/stdc++.h>

using namespace std;
const int N = 10;

int main() {

  int t;

  cin >> t;

  while (t--) {

    string str;
    cin >> str;
    int l = str[0] - 'a';
    int r = str[1] - '0';

    for (int i = 1; i <= 8; i++) {
      char ll = i + 'a' - 1;
      if (ll != str[0])
        cout << ll << str[1] << endl;
    }

    for (int i = 1; i <= 8; i++) {

      if (i != str[1] - '0')
        cout << str[0] << i << endl;
    }
  }

  return 0;
}
