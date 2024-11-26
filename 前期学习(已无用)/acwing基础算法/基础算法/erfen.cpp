// 整数二分

// 二分的本质：边界
// 有单调性一定可以二分 但可二分不一定有单调性
// 给定区间定义某种性质 某半边满足，另外半边不满足，通过二分来寻找边界
// 可以找左边界也可以找右边界，于是有两个不同的模板
// 近似理解为一个模板是从小到大排，一个模板从大到小排


// 二分思想：将长度缩小一半，保证区间内一定有答案，直到区间长度为一

// 二分一定有解，在条件（定义的性质）内

//第一步，找中间值 mid =l+r>>2
#include <iostream>

using namespace std;

int bsearch_1(int l,int r){
    while(l<r){
        int mid =l+r>>1;    
        if(check(mid)) r =mid;
        else l=mid +1;
    }
    return 1;
}


int bsearch_2(int l,int r){
    while(l<r){ 
        int mid =l+r+1>>1;
        if(check(mid) l =mid);
        else r=mid -1;
    }
    return 1;
}


