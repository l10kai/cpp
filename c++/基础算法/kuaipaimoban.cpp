// 所有小于x的放左边，大于x的放右边
//任何时候，i左侧小于key,j右侧大于key


#include <iostream>

using namespace std;

const int N=1e6 +10;

int n;
int q[N];

//模板重点
void quick_sort(int q[],int l,int r){
    if(l>=r) return;   //边界

    int x=q[l+r>>1],i=l-1,j=r+1; //偏移量 
    while (i<j){
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++) printf("%d",q[i]);
    return 0;
}