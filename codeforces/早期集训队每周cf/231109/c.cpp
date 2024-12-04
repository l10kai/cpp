#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
 int sum=0;
    int i=0,j=a.size()-1;
    while(i<j){
        // if(a[i]==')'||a[j]=='('){
        //     if(a[i]==')') i++;
        //     if(a[j]=='(') j--;
        // }
        while(a[i]==')') i++;
        while(a[j]=='(') j--;

        if(a[i+1]==')') i+=2,sum++;
        if(a[j]==')') i++,j--,sum++;
        else j--;
            
    }
   
    cout<<sum*2;
    return 0;
}