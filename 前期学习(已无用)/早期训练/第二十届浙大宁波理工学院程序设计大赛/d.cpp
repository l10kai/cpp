#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
int a[N], b[N], c[N];

void solve() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
    cin >> b[i];

  sort(b, b + q);
  int temp = -1, cot = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == temp)
      c[cot]++;
    else
      c[++cot]++, c[cot] += c[cot - 1];
    temp = a[i];
  }
  //    for(int i = 0;i < cot ;i++) cout <<c[i]<<" ";

  for (int i = 0; i < q; i++) {
    int l = 0, r = cot;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (c[mid] <= b[i])
        l = mid;
      else
        r = mid - 1;
    }
    cout << c[r] << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
