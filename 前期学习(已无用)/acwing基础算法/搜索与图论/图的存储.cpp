#include <bits/stdc++.h>

using namespace std;

const int N=100010,M=N*2;

int h[N],e[M],ne[M],idx;

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int main(){
    memset(h,-1,sizeof h);

    
}
