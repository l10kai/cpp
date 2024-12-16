# [Codeforces Round 940 (Div. 2) and CodeCraft-23](https://codeforces.com/contest/1957)





## A.[Stickogon](https://codeforces.com/contest/1957/problem/A)

**题意：**给定一堆木棒，问能同时拼成的正多边形(边长相等)的最大数量，多边形中使用的小棒不超过 1根（任意两个多边形没有公共木棒）



**ac代码：**

```cpp
void solve() {
    int n;
    cin >> n;
 
    map<int, int> mp;
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int res = 0;
    for (int i = 0; i <= 100; i++) {
        res += mp[i] /3; //三根相同木棒围成一个正三角形
    }
 
    cout << res << ln;
}
```

## B.[A BIT of a Construction](https://codeforces.com/contest/1957/problem/B)

 **题意：**$给定整数n,k,构造一个长度为n，和为k的数组使得数组的或运算值的二进制表示中1的数量最大。$

**思路：**

考虑或运算的性质：*有1就是1*。于是我们可以考虑k二进制表示的位数，设位数为x，那么可以计算出二进制位数为x的最大数，此时当然x位全是1，设其十进制下为$ k2$。

如果 $k = k2$, 那么只需输出$k,补n-1个0即可。$

否则，$k的二进制表示至少有一位不是1，我们可以算出二进制下k-1位全是1的数$k3$，输出 k3, k - k3,补n-2个0$

$注意特殊情况：n =  1时输出 k。$

**ac代码：**

```cpp
int counts(int num) {
    int count = 0;
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}
 
 
int cbits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num >>= 1;
    }
    return count;
}
int maxx(int bits) {
    int x = (1 << bits) - 1;
    return x;
}
void solve() {
    int n, k;
    cin >> k >> n;
 
    if(k == 1) {
        cout << n << ln;
        return ;
    }
    k --;
    int num = cbits(n);
 
    if(n != maxx(num)) {
        cout << maxx(num - 1) << " ";
        cout << n - maxx(num - 1) << " ";
        k--;
        while(k --) cout << 0 << " ";
    } else {
        cout << n << " ";
        
        while(k --) cout << 0 << " ";
    }
 
 
    cout << ln;
}
```

## C. How Does the Rook Move?

**题意：**

给定一个$n\times n$的棋盘，玩家和电脑每轮各往棋盘放一个车，电脑会在与玩家对称的位置放车(如玩家选择$(r,c)$位置放车，则电脑会选择在$(c,r)$放车，如果$r = c$,则电脑不放）。放置一个车后，双方均不能在该车所在行和列放置车。有效的一步棋是将一只车放在一个位置$(r,c)$上，使它不会攻击任何其他车。当无法继续添加棋子时，游戏结束，现在给定玩家已经进行的一些步数，问从此时开始到结束一共会有多少种不同方案。
 如果有一个坐标$(r,c)$在一种方案中有一个车，而在另一种方案中没有，或坐标上的车来源不同，那么这两种方案就被认为是不同的。

**思路：**

基本上有两种类型的移动：

1. 将车置于某个 (i,i)(𝑖,𝑖) 位置：这将减少 11 的空闲行列数。
2. 在 i≠j𝑖≠𝑗 处的 (i,j)(𝑖,𝑗) 放置车：计算机现在也照此办理，在 (j,i)(𝑗,𝑖) 放置车，挡住 i𝑖 和 j𝑗 行以及 i𝑖 和 j𝑗 列。因此空闲行列数减少了 22 。

首先，我们算出之前下过的 k𝑘 步，并计算剩余可放置车的空闲列/行的数量，称之为 m𝑚 。

注意移行/列的顺序并不影响车的最终配置，因此只有行数才是决定最终配置数的关键。

我们可以使用动态编程的方法，其中 dp[i]𝑑𝑝[𝑖] 表示当剩下 i𝑖 行和列时的最终配置数。

由于移除行/列的顺序并不重要，我们从移除最后一行或最后一列开始。

在移除 i×i𝑖×𝑖 网格中的最后一行或最后一列时，我们有两种选择：

- 我们放置车 (i,i)(𝑖,𝑖) ，结果是只删除最后一行和一列，留下一个 (i−1)×(i−1)(𝑖−1)×(𝑖−1) 格。这种情况下的最终配置数为 dp[i−1]𝑑𝑝[𝑖−1] 。
- 或者，我们也可以在{883833027}或 (j,i)(𝑗,𝑖) 中的任意 j∈{1,2,…,i−1}𝑗∈{1,2,…,𝑖−1} 放置车。这步棋走完之后， j𝑗 th和 i𝑖 th行列都被删除，剩下一个 (i−2)×(i−2)(𝑖−2)×(𝑖−2) 格。这就为 dp[i]𝑑𝑝[𝑖] 贡献了 2(i−1)⋅dp[i−2]2(𝑖−1)⋅𝑑𝑝[𝑖−2] 。

总的来说，我们计算了所有 i∈{2,3,…,n}𝑖∈{2,3,…,𝑛} 的 dp[i]=dp[i−1]+2(i−1)⋅dp[i−2]𝑑𝑝[𝑖]=𝑑𝑝[𝑖−1]+2(𝑖−1)⋅𝑑𝑝[𝑖−2] ，基本情况为 dp[0]=dp[1]=1𝑑𝑝[0]=𝑑𝑝[1]=1 。

我们的最终答案是 dp[m]𝑑𝑝[𝑚] 。

（以上粘贴codeforces官解）

画张图就很好理解dp方程：



## D. A BIT of an Inequality

**题意:** 存在多少个区间和区间中间的点，使得区间异或和异或上这个中间点以后变大了

**思路:** 据说是一道经典的模板题











