// #include <bits/stdc++.h>

// using namespace std;

// int h1,m1,h2,m2,h3,m3;

// void solve(){
//     cin >> h1 >> m1 >> h2 >>m2;

//     int t1 = h1*60 +m1,t2= h2*60+m2;

//     t2 > t1 ? t2-=t1:t2= t2 +24*60 -t1;

//     h3 = t2 /60,m3 =t2%60;

//     cout <<h3 <<" "<<m3<<endl;
// }

// int main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;

//     while(t--){
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;
  int t1 = h1 * 60 + m1,
      t2 = h2 * 60 + m2 t2 > t1 ? t2 -= t1 : t2 = t2 + 24 * 60 - t1;
  cout << t2 / 60 << " " << t2 % 60 << endl;
}
// void solve2() {
//     int h1, m1, h2, m2;
//     cin >> h1 >> m1 >> h2 >> m2;
//     int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
//     int mod = 24 * 60;
//     int t = (t2 - t1 + mod) % mod;
//     if (t == 0) t += mod;
//     cout << t / 60 << ' ' << t % 60 << '\n';
// }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
