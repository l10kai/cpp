/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <deque>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

const int N = 3e5 + 10;

int a[N], b[N], tmp[N];

i64 merge_sort(int q[], int l, int r) {
    if (l >= r)
        return 0;

    int mid = l + r >> 1;

    i64 res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];

    return res;
}

void solve() {
    i64 n, m;
    cin >> n >> m;

    deque<i64> dq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dq.push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
        b[i] = a[n - i - 1];
    string str;
    cin >> str;

    i64 now_value = merge_sort(a, 0, n - 1);
    const i64 max_value = merge_sort(b, 0, n - 1) + now_value;
    i64 bl = 1;
    cout << now_value << ln;

    for (auto ch : str) {
        if (ch == 'S') {
            i64 ax;
            if (bl & 1)
                ax = dq.front();
            else {
                ax = dq.back();
            }

            now_value += (n - 2 * ax + 1);

            if (now_value < 0)
                now_value = 0;

            cout << now_value % 10;
            // cout << now_value << " " << ax << ln;
            if (bl & 1) {
                dq.pop_front();
                dq.push_back(ax);
            } else {
                dq.pop_back();
                dq.push_front(ax);
            }
        } else {
            // cout<< "...." << now_value << ln;
            // cout << max(max_value - now_value, 0ll) % 10 << ln;
            cout << max(max_value - now_value, 0ll) % 10;
            now_value = max(max_value - now_value, 0ll);
            bl++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
