#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define int long long
#define pii pair<int, int>

const int N = 1e4 + 9;

int tot, ans, last;  // last上条底的长度
int X[N << 1];       // 所有横坐标  需离散化

struct node1  // 扫描线
{
    int x1, x2, y;
    int flag;
} line[N << 1];

struct node2  // 线段树
{
    int l, r;
    int lz, len;  // len当先扫描到的矩形的长
    int sum;      // 竖边个数
    bool lco, rco;
} t[N << 3];

bool cmp(node1 q, node1 w) {
    if (q.y == w.y)
        return q.flag > w.flag;
    return q.y < w.y;
}

void build(int u, int l, int r) {
    t[u] = {l, r};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
}

void pushup(int u) {
    int l = t[u].l, r = t[u].r;
    if (t[u].lz) {
        t[u].len = X[r + 1] - X[l];
        t[u].lco = t[u].rco = 1;
        t[u].sum = 2;
    } else {
        t[u].len = t[u << 1].len + t[u << 1 | 1].len;
        t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
        t[u].lco = t[u << 1].lco, t[u].rco = t[u << 1 | 1].rco;
        if (t[u << 1].rco && t[u << 1 | 1].lco)
            t[u].sum -= 2;
    }
}

void modify(int u, int l, int r, int flag) {
    if (l <= t[u].l && t[u].r <= r) {
        t[u].lz += flag;
        pushup(u);
        return;
    }
    int mid = (t[u].l + t[u].r) >> 1;
    if (l <= mid)
        modify(u << 1, l, r, flag);
    if (r > mid)
        modify(u << 1 | 1, l, r, flag);
    pushup(u);
}

void solve() {
    memset(t, 0, sizeof(t));
    memset(X, 0, sizeof(X));
    memset(line, 0, sizeof(line));
    map<int, int> p, p1;  // 用来离散横坐标 建树空间不会炸
    last = tot = ans = 0;

    int n, x = 0, y = 0, xx, yy;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> xx >> yy;
        line[i] = {x, xx, y, 1};
        line[i + n] = {x, xx, yy, -1};
        X[i] = x, X[i + n] = xx;
        p1[x]++;
        p1[xx]++;
    }
    sort(line + 1, line + n * 2 + 1, cmp);  // 排序完就是从下往上扫
    // 去重 离散
    sort(X + 1, X + 2 * n + 1);
    unique(X + 1, X + 2 * n + 1);
    for (auto [i, j] : p1) {
        if (!p[i])
            p[i] = ++tot;
    }

    build(1, 1, tot - 1);

    for (int i = 1; i < 2 * n; i++) {
        int l = p[line[i].x1],
            r = p[line[i].x2];  // 用离散值查到当前扫描到的边的左右横坐标
        modify(1, l, r - 1, line[i].flag);
        ans = ans + abs(last - t[1].len);  // 横边
        last = t[1].len;
        ans =
            ans + t[1].sum * (line[i + 1].y - line[i].y);  // 竖边条数*竖边长度
    }
    ans = ans + line[n * 2].x2 - line[n * 2].x1;
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // init();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
