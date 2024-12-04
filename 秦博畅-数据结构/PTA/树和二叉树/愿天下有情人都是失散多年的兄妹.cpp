#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

struct node {
    char sex;
    int father, mather;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<node> v(N, {'\0', -1, -1});
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int self, father, mather;
        char sex;
        cin >> self >> sex >> father >> mather;

        v[self] = {sex, father, mather};
        if (father != -1)
            v[father].sex = 'M';
        if (mather != -1)
            v[mather].sex = 'F';
    }

    int k;
    cin >> k;

    function<bool(int, int, int)> dfs = [&](int a, int b, int cnt) {
        if (a == -1 || b == -1 || cnt > 5)
            return true;
        if (a == b)
            return false;

        return dfs(v[a].father, v[b].mather, cnt + 1) &&
               dfs(v[a].mather, v[b].father, cnt + 1) &&
               dfs(v[a].father, v[b].father, cnt + 1) &&
               dfs(v[a].mather, v[b].mather, cnt + 1);
    };

    while (k--) {
        int a, b;
        cin >> a >> b;
        if (v[a].sex == v[b].sex && v[a].sex != '\0') {
            cout << "Never Mind" << '\n';
            continue;
        }
        cout << (dfs(a, b, 1) ? "Yes" : "No") << '\n';
    }

    return 0;
}
