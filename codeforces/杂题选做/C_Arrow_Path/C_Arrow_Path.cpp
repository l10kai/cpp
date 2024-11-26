/*
.______   ____    ____
|   _  \  \   \  /   /
|  |_)  |  \   \/   /
|   _  <    \_    _/
|  |_)  |     |  |
|______/      |__|
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
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

namespace MATH {
    template <typename T> T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    template <typename T> T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }
    template <typename T> bool isprime(T n) {
        if (n <= 1)
            return false;
        for (T i = 2; i <= std::sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

using namespace MATH;
using namespace std;
using i64 = long long;
const char &ln = '\n';

const int N = 200010;
int n;
char a[2][N]{};
bool vis[2][N]{};
bool bl;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x == 2 && y == n) {
        bl = true;
    }
    if(vis[x][y] || x == 2 && y == n) return ;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && !vis[nx][ny]) {
            if (a[nx][ny] == '>')
                dfs(nx, ny + 1);
            // if (a[nx][ny] == '<')
            //     dfs(nx, ny - 1);
        }
    
    }
}

void solve() {
    memset(vis, 0, sizeof(vis));
    bl = false;

    cin >> n;

    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    dfs(1, 1);

    cout << ((bl == true) ? "YES" : "NO") << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
