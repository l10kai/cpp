//快速存储字符串集合

#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
//二维数组模拟trie
int son[N][26],cnt[N],idx;

void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }

    cnt[p]++;
}
