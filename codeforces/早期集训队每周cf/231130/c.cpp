#include <bits/stdc++.h>

using namespace std;

const int N=2020;

char mp[N][N];
//int d[N][N];

int n,m,k;

int bfs(){
    
    int sum=0;

    if(k==1) for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.') sum++;
        }

    else{

        for(int i=0;i<n;i++){
             int j=0;
            while(j<m){
                while(j<m&&mp[i][j]!='.') j++;

                int t=0;
                while(j<m&&mp[i][j]=='.'){
                    t++;
                    j++;
                }
                if(t-k+1>0) sum+=t-k+1;
            }
        }

         for(int j=0;j<m;j++){
            int i=0;
            while(i<n){
                while(i<n&&mp[i][j]!='.') i++;

                int t=0;
                while(i<n&&mp[i][j]=='.'){
                    t++;
                    i++;
                }
               if(t-k+1>0) sum+=t-k+1;
            }
        }

    }

    return sum;
}

int main(){

    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>mp[i][j];

    cout<<bfs();

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<mp[i][j];
    //     }
    //     puts("");
    // }

    return 0;

}