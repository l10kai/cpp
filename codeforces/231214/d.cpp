#include <bits/stdc++.h>

using namespace std;

bool check(int x,int y){
    if(x==0&&y==0) return 1;
    if(x<10&&y<10) return 0;
    if(x<10||y<10){
        int tx=min(x,y),ty=max(x,y);
        if(tx==ty/10&&ty%10==0) return 1;
        else return 0;
    }
    else{
        if(x%10==y/10 && x/10==y%10) return 1;
        else return 0;
    }
}

int lcm(int n1,int n2)
{
    int max;


    max = (n1 > n2) ? n1 : n2;

    do
    {
        if (max % n1 == 0 && max % n2 == 0) return max;
        else ++max;
    } while (true);

    return -1;
}

void solve(){
    int a,b,wait;
    scanf("%d:%d%d",&a,&b,&wait);

    int times = lcm(wait,1440)/wait;
    int ans=0;
    while(times--){
        if(check(a,b)) ans ++;

        b+=wait;
        if(b>=60) a+=b/60,b-=60*(b/60);
        if(a>=24) a -=24;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
