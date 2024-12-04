#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        getchar();
        string str;
        getline(cin,str);
        if(str == "\n"){
            puts("");
            continue;
        }
        string ans;

        for(int i=0; str[i]; i++){
            if(str[i]!='b'&&str[i]!='B') ans += str[i];
            else if( ans.empty() ) continue;
            else if(str[i]=='b'){
                for(int j = ans.size()-1; i>=0; i--){
                    if(ans[j]>='a'&&ans[j]<='z') ans.erase(ans.begin()+j);
                }
            }
            else if(str[i]=='B'){
                for(int j = ans.size()-1; i>=0; i--){
                    if(ans[j]>='A'&&ans[j]<='Z') ans.erase(ans.begin()+j);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
