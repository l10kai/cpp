// 用数组模拟链表与邻接表 栈与队列
//邻接表：存储图和树

//双链表 ：优化某些问题、

// head是什么？它的具体作用又是啥？

// 答:head应该是一个特殊的指针，一开始指向-1，表示链表里没有内容，为空节点，

// 当链表里有元素的时候，它变成了一个指向第一个元素的指针。还有就是为了最后遍历链表时，知道链表什么时候结束（因为最后实现的链表，它最后一个节点的ne[i]一定等于-1）

//删除头结点就是删除链表的第一个有值的结点

#include <iostream>

using namespace std;

const int N=1e6+10;
//idx作为指针 存储目前地址（用到的点）
int head,e[N],ne[N],idx;


void init(){
    head= -1;
    idx=0;
}
//加在头
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}
//加在k后面
void add(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删掉k后面 
void remove(int k){
    ne[k]=ne[ne[k]];
}
int main(){

}
