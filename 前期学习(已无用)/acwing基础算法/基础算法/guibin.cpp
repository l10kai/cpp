//归并排序 主要思想：分治
//类似快排 方法不一样
//找分界点 递归左右 此时左侧和右侧分别为两个有序数组，
//从而归并，合二为一   (双指针算法)
#include <iostream>

using namespace std;
const int N=1e6+10;
int n;
int q[N],tmp[N];

void merge_sort(int a[],int l,int r){
    if(l>=r) return;
    int mid =l+r>>1;

    merge_sort(a,l,mid),merge_sort(a,mid+1,r); //递归
    //以下为关键函数
    int k=0,i=l,j=mid +1;
    while(i<=mid &&j<=r)
      if (q[i]<=q[j]) tmp[k++]=q[i++];
      else tmp[k++] = q[j++];
      
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];

    for(i =l,j=0;i<=r;i++,j++) q[i]=tmp[j];

}

signed main() {

  sort();


  return 0;
}
