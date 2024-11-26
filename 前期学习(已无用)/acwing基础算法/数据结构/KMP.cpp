//暴力做法

#include <bits/stdc++.h>

using namespace std;

string s,p;

//暴力
int violentmactch(string &s,string &p){
    int slen=s.size();
    int plen=p.size();

    int i=0;
    int j=0;

    while (i<slen &&j<plen){

        if(s[i]==p[j]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==plen) return i-j;
    else return -1;
}


//kmp
int kmpsearch(char *s,char *p){
    int i=0;
    int j=0;
    int slen=strlen(s);
    int plen=strlen(p);
    while(i<slen &&j<plen){
        if(j==-1||s[i]==p[j]){
            i++;
            p++;
        }
        //else j=ne[j];
    }
    if(j==plen) return i-j;
    else return -1;
}
int main(){
    cin>>s>>p;
    int t=violentmactch(s,p);
    cout<<t<<endl;
}
