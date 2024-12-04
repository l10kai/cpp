#include<iostream>
using namespace std;
int main(){
    int t;
    int a,b,c;
    cin>>t;
    while(t--){
        int n;
        int i;
        int temp=1;
        int tp=1;
        cin>>n;
        if(n%2==0){
        for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(temp%2==1){
                    cout<<"##";
                }
                else if(temp%2==0){
                    cout<<"..";
                }
                temp++;
            }
            cout<<endl;
            for(int j=1;j<=n;j++){
                if(tp%2==1){
                    cout<<"##";
                }
                else if(tp%2==0){
                    cout<<"..";
                }
                tp++;
            }
            cout<<endl;
            temp++;
            tp++;
        }
    }
        else{
            for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(temp%2==1){
                    cout<<"##";
                }
                else if(temp%2==0){
                    cout<<"..";
                }
                temp++;
            }
            cout<<endl;
                for(int j=1;j<=n;j++){
                if(tp%2==1){
                    cout<<"##";
                }
                else if(tp%2==0){
                    cout<<"..";
                }
                tp++;
            }
            cout<<endl;
        }
        }
    }
    return 0;
}
