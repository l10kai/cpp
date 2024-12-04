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

//  艘飞船出发探索海洋深处。这些飞船的编号从 1
//  到 n
//  ，依次递增；第 i
//  艘飞船的耐久度为 ai
//  。

// 克拉肯按照特定的顺序攻击了船只 k
//  次。首先，它攻击第一艘飞船，然后是最后一艘，接着又是第一艘，以此类推。

// 克拉肯的每次攻击都会使飞船的耐久度降低 1
//  。当船只的耐久度下降到 0
//  时，它就会沉没，不再受到攻击(因此船只不再是第一艘或最后一艘，卡拉基只攻击尚未沉没的船只)。如果所有的船只都沉没了，克拉肯也就没有什么可攻击的了，于是它就游走了。

// 例如，如果出现 n=4
//  、 k=5
//  和 a=[1,2,4,3]
//  ，就会出现以下情况：

// 卡拉基攻击第一艘飞船，它的耐久度变为零，现在为 a=[2,4,3]
//  ；
// 卡拉基攻击最后一艘飞船，现在为 a=[2,4,2]
//  ；
// 克拉肯攻击第一艘飞船，现在为 a=[1,4,2]
//  ；
// 克拉肯号攻击最后一艘飞船，现在是 a=[1,4,1]
//  ；
// 克拉肯攻击第一艘飞船，其耐久度变为零，现在为 a=[4,1]
//  。
// 克拉肯攻击后有多少艘船被击沉？

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n + 10);

    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 i = 1, j = n, sum = 0;
    while (i < j && k > 0) {
        if (i >= j || k <= 0)
            break;


        if (a[i] < a[j] && k > 0) {
            if (k >= 2 * a[i]) {
                k -= 2 * a[i], a[j] -= a[i], i++, sum++;
                continue;
            } else
                break;
        }


        if (a[i] > a[j] && k > 0) {
            if (k >= 2 * a[j]) {
                k -= 2 * a[j], a[i] -= a[j], j--, sum++;
                continue;
            } else
                break;
        }


        if (a[i] == a[j] && k > 0) {
            if (k >= 2 * a[i]) {
                i++, j--, k -= 2 * a[i], sum += 2;
        
            } else
                break;
        }
    }
    if(i == j && k >= a[i])
        sum++;

    if(i < j && k >=2 * a[i] -1 )
    //cout <
    cout << sum << ln;
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
