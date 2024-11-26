// /*
//  __       __  .__   __.  __  ___
// |  |     |  | |  \ |  | |  |/  /
// |  |     |  | |   \|  | |  '  /z
// |  |     |  | |  . `  | |    <
// |  `----.|  | |  |\   | |  .  \
// |_______||__| |__| \__| |__|\__\
// */
// #include <bits/stdc++.h>
// #define mem(x, y) memset(x, y, sizeof(x))
// #define all(x)    x.begin(), x.end()
// #define rall(v)   v.rbegin(), v.rend()
// #define sqr(x)    ((x) * (x))
// #define as        static_cast
// #define fi        first
// #define se        second
// #define pb        push_back
// #define ppb       pop_back
// #define pii       pair<int, int>
// #define pll       pair<i64, i64>

// // #define cin fin
// // #define cout fout
// // std::ifstream fin("E:/Cpp/duipai/in.txt");
// // std::ofstream fout("E:/Cpp/duipai/out.txt");

// using namespace std;
// using f64 = double;
// using i64 = long long;
// using f128 = long double;

// const char &ln = '\n';

// const int dx[] = {-1, 1, 0, 0};
// const int dy[] = {0, 0, -1, 1};

// void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,
// int y) {
//     int n = grid.size();
//     int m = grid[0].size();
//     visited[x][y] = true;

//     for (int i = 0; i < 4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' &&
//         !visited[nx][ny]) {
//             dfs(grid, visited, nx, ny);
//         }
//     }
// }

// int count(vector<vector<char>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     int count = 0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (grid[i][j] == '.' && !visited[i][j]) {
//                 dfs(grid, visited, i, j);
//                 ++count;
//             }
//         }
//     }

//     return count;
// }

// void solve() {
//     i64 n;
//     cin >>n;
//     vector<vector<char>> a(2, vector<char>(n + 10));

//     for(int i = 0; i < 2; i ++)
//         for(int j = 0; j < n; j ++)
//             cin >> a[i][j];

//     if(count(a) >= 3) cout << 0 << ln;
// /*
// .......x
// .x.xx...

// */
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // cout.tie(nullptr);
//     int t = 1;
//     cin >> t;

//     while (t--) {
//         solve();
//     }
//     // fin.close();
//     // fout.close();
//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(2, vector<char>(n + 10));

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        long long ans = 0;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (j < n - 2 && i < 1)
                    if (a[i][j] == 'x' && a[i][j + 2] == 'x' &&
                        a[i][j + 1] == '.' && a[i + 1][j + 1] == '.')
                        if (a[i + 1][j] == '.' && a[i + 1][j + 2] == '.') {
                            ans++;
                        }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (i >= 1 && j < n - 2)
                    if (a[i][j] == 'x' && a[i][j + 2] == 'x' &&
                        a[i][j + 1] == '.')
                        if (a[i - 1][j] == '.' && a[i - 1][j + 1] == '.' &&
                            a[i - 1][j + 2] == '.') {
                            ans++;
                        }

        cout << ans << '\n';
    }

    return 0;
}