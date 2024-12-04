//每日哲理：一个人能走多远不在于他顺境时能走多快，而在于他逆境时多久能找到曾经的自己


//求kmp过程与匹配过程类似

#include <bits/stdc++.h>

using namespace std;

const int N=100010,M=1000010;
int n,m;
int ne[N];
char s[M],p[N];

int main(){

    cin>>n>>p+1>>m>>s+1;
//找next
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
//kmp实现
    for(int i=1,j=0;i<=m;i++){
        while (j&&s[i]!=p[j+1]) j=ne[j];
        if (s[i]==p[j+1]) j++;
        if(j==n){
            printf("%d",i-n);
            j=ne[j];
        }
    }

    return 0;
}