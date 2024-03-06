#include <bits/stdc++.h>

using namespace std;

const int N=12010,M=2010;

/// @brief 
int w[N],v[N],dp[M];

int n,m;

int main(){
    
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin>>a>>b>>s;
        
        int t=1;
        while(t<=s){
            cnt++;
            w[cnt]=a*t;
            v[cnt]=b*t;
            s-=t;
            s*=2;
        }
        if(s>0){
            cnt++;
            w[cnt]=a*s;
            v[cnt]=b*s;
        }
    }
    
    for(int i=1;i<=cnt;i++)
        for(int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            
    cout<<dp[m];
    
    return 0;
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 12010, M = 2010;

// int n, m;
// int v[N], w[N];
// int f[M];

// int main()
// {
//     cin >> n >> m;

//     int cnt = 0;
//     for (int i = 1; i <= n; i ++ )
//     {
//         int a, b, s;
//         cin >> a >> b >> s;
//         int k = 1;
//         while (k <= s)
//         {
//             cnt ++ ;
//             v[cnt] = a * k;
//             w[cnt] = b * k;
//             s -= k;
//             k *= 2;
//         }
//         if (s > 0)
//         {
//             cnt ++ ;
//             v[cnt] = a * s;
//             w[cnt] = b * s;
//         }
//     }

//     n = cnt;

//     for (int i = 1; i <= n; i ++ )
//         for (int j = m; j >= v[i]; j -- )
//             f[j] = max(f[j], f[j - v[i]] + w[i]);

//     cout << f[m] << endl;

//     return 0;
// }



#include <bits/stdc++.h>

using namespace std;

const int N = 12010, M = 2010;

int w[N], v[N], dp[M];

int n, m;

int main() {

    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;

        int t = 1;
        while (t <= s) {
            cnt++;
            w[cnt] = a * t;
            v[cnt] = b * t;
            s -= t;
            t *= 2;
        }
        if (s > 0) {
            cnt++;
            w[cnt] = a * s;
            v[cnt] = b * s;
        }
    }

    for (int i = 1; i <= cnt; i++) // 修复这里的循环条件
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    cout << dp[m];

    return 0;
}
