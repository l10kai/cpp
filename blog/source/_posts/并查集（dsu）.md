---
title: 并查集（dsu）
date: 2024-12-04 13:09:35
tags: 并查集（dsu）
categories:
- 算法竞赛
- 模板类
---

```cpp
struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) { init(n); }

  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) { return find(x) == find(y); }

  // 按秩合并
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (x > y)
      f[y] = x;
    else
      f[x] = y;
  }

  /*
  bool merge(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
          return false;
      }
      siz[x] += siz[y];
      f[y] = x;
      return true;
  }
  */

  int size(int x) { return siz[find(x)]; }
};

```
