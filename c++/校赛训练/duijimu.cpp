#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// int main() {
//     int T;
//     cin >> T;
//     cin.ignore();
//     while (T--) {
//         string line;
//         getline(cin, line);
//         stringstream ss(line);
//         string word;
//         while (ss >> word) {
//             cout << (char)toupper(word[0]);
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main(){

    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        a[0]-=32;
        cout<<a[0];
        for(int i=0;a[i];i++){
            if(a[i]==' ') a[i+1]-=32,cout<<a[i+1];
        }
    }
    return 0;
}