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
#include <iostream>
#include <unordered_map>
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

// Maxim 有一个由 n
//  个整数组成的数组 a
//  和一个由 m
//  个整数组成的数组 b
//  ( m≤n
//  )。

// 如果数组 c
//  中的元素可以重新排列，使得其中至少有 k
//  个元素与数组 b
//  中的元素匹配，那么马克西姆就认为长度为 m
//  的数组 c
//  是好数组。

// 例如，如果 b=[1,2,3,4]
//  和 k=3
//  ，那么数组 [4,1,2,3]
//  和 [2,3,4,5]
//  就是好数组(它们可以重新排列如下： [1,2,3,4]
//  和 [5,2,3,4]
//  )，而数组 [3,4,5,6]
//  和 [3,4,3,4]
//  则不是好数组。

// 马克西姆希望选择长度为 m
//  的数组 a
//  的每个子段作为数组 c
//  的元素。请帮助 Maxim 计算有多少个数组是好的。

// 换句话说，求有多少个位置 1≤l≤n−m+1
//  的元素 al,al+1,…,al+m−1
//  构成一个好数组。


// 输入

// 第一行包含一个整数 t
//  ( 1≤t≤104
//  ) - 测试用例的数量。

// 每个测试用例的第一行包含三个整数 n
//  、 m
//  和 k
//  ( 1≤k≤m≤n≤2⋅105
//  )--数组 a
//  和 b
//  中的元素个数，即所需的匹配元素个数。

// 每个测试用例的第二行包含 n
//  个整数 a1,a2,…,an
//  ( 1≤ai≤106
//  ) - 数组 a
//  的元素。数组 a
//  中的元素不一定是唯一的。

// 每个测试用例的第三行包含 m
//  个整数 b1,b2,…,bm
//  ( 1≤bi≤106
//  ) - 数组 b
//  的元素。数组 b
//  的元素不一定是唯一的。

// 保证所有测试用例中 n
//  的总和不超过 2⋅105
//  。同样，保证所有测试用例中 m
//  的总和不超过 2⋅105
//  。

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    //vector<bool> bl(n, false);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
        int good = 0, res = 0;
    for(int i = 0; i  < m -1; i++) {
        if(mp[a[i]] -- > 0) {
            good++;
        }
    }

    for(int i = 0; i <= n - m; i ++ ) {
        good += mp[a[i + m - 1]]-- > 0;
        res += good >= k;
        good -= ++mp[a[i]] > 0;
    }

    cout  << res << ln;
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
