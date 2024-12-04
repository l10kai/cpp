#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = N * 2; // N表示最大结点数，M表示最大边数

int n, m;
int h[N], e[M], ne[M], idx; // h表示邻接表头指针数组，e表示邻接表存储边的数组，ne表示邻接表存储边的下一个位置，idx表示邻接表当前可用位置的索引
bool st[N]; // st数组用于标记结点是否被访问过

int ans = N; // 初始化答案为一个较大的值N

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++; // 将边(b, a)加入以a为头结点的邻接表，idx自增，表示下一个可用位置
}

int dfs(int u) {
    st[u] = true; // 标记结点u为已访问

    int sum = 1, res = 0; // sum表示以结点u为根的子树的结点数，res表示子树中点数的最大值

    for (int i = h[u]; i != -1; i = ne[i]) { // 遍历以u为头结点的邻接表
        int j = e[i]; // j是与u相邻的结点
        if (!st[j]) { // 如果结点j未被访问
            int s = dfs(j); // 递归遍历子树并返回子树的结点数
            res = max(res, s); // 更新子树中点数的最大值
            sum += s; // 更新以u为根的子树的结点数
        }
    }

    res = max(res, n - sum); // 计算以u为根的子树被删除后，各个连通块中点数的最大值

    ans = min(ans, res); // 更新答案为所有子树被删除后的情况中的最小值

    return sum; // 返回以u为根的子树的结点数
}

int main() {
    cin >> n; // 读取结点数
    memset(h, -1, sizeof h); // 初始化邻接表头指针数组


    // 树中是不存在环的，对于有n个节点的树，必定是n-1条边
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); // 添加无向边(a, b)和(b, a)到邻接表中
    }

    dfs(1); // 从结点1开始深度优先搜索树的重心
    cout << ans << endl; // 输出答案，即将重心删除后，剩余各个连通块中点数的最大值
    return 0;
}
