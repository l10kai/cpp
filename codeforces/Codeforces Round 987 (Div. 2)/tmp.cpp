/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

struct DSU {
    std::vector<int> f, siz, maxVal;

    DSU() {}
    DSU(int n, const std::vector<int> &a) {
        init(n, a);
    }

    void init(int n, const std::vector<int> &a) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        maxVal = a;  // 初始化 maxVal 为节点的值
    }

    int find(int x) {
        if (x != f[x]) {
            int root = find(f[x]);
            f[x] = root;
            // 更新 maxVal[x]
            maxVal[x] = maxVal[root];
        }
        return f[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        // 按秩合并，并维护最大值
        if (siz[x] < siz[y]) {
            f[x] = y;
            siz[y] += siz[x];
            maxVal[y] = std::max(maxVal[y], maxVal[x]);
        } else {
            f[y] = x;
            siz[x] += siz[y];
            maxVal[x] = std::max(maxVal[x], maxVal[y]);
        }
    }

    int getMax(int x) {
        return maxVal[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &i : a) {
        cin >> i;
    }
    DSU dsu(n, a);
    int x = -1, id = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                dsu.merge(i, j);
            }
        }
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                dsu.merge(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dsu.getMax(i) << " ";
    }

    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
