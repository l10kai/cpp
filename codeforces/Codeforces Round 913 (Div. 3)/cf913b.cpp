#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        string str;
        cin >> str;

        int b=0,B=0;
        string res="";

        for(int i = str.size()-1; i>=0; i-- ){
            if(str[i]=='b') b++;
            if(str[i]=='B') B++;

            if(str[i]>='a'&&str[i]<='z'&&str[i]!='b'){
                if(b) b--;
                else res+=str[i];
            }

            if(str[i]>='A'&&str[i]<='Z'&&str[i]!='B'){
                if(B) B--;
                else res+=str[i];
            }


        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
}
