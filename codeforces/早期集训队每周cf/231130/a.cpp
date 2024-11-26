#include <bits/stdc++.h>

using namespace std;

bool check(int x){
    int sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }

    return sum==10;
}

int main(){

    int k;
    cin>>k;

    int cot=0,num=1;

    while(cot<k){
        if(check(num)) cot++;
        num++;
    }

    cout<<num-1;

    return 0;
}