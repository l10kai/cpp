#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=35;

// int C[N][N];

// void cal() {
//     for (int i = 0; i < N; i++) {
//         C[i][0] = C[i][i] = 1;
//         for (int j = 1; j < i; j++) {
//             C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//         }
//     }
// }

LL C(int n,int m){
    if(n==m||m==0) return 1;
    return C(n,m-1)*(n-m+1)/m;
}



int main(){
    int n,m,t;
    cin>>n>>m>>t;

    LL sum=0;

    //cal();
    // LL sum=C[n+m-5][t-5]*C[n][4]*C[m][1];
    
    for(int i=4;i<t;i++) sum+= C(n,i)*C(m,t-i);  //sum+=C[n][i]*C[m][t-i];
    
    cout<<sum;
    return 0;
}
