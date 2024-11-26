//前缀和近似理解为数列的前n项和
//功能为更方便的求片段和
//数组起始为是s1,且定义s0=0

#include <iostream>

using namespace std;

const int N=100010;

int n,m;
int a[N],s[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
}