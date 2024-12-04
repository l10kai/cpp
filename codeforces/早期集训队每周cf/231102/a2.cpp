#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
const LL N = 1e9 + 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<PLL> a;
        LL ws, we;
        
        for (int i = 0; i < n; i++) {
            LL s, e;
            cin >> s >> e;
            a.push_back({s, e});
            
            if (i == 0) {
                ws = s;
                we = e;
            }
        }
        
        LL max_weight = -1;
        
        for (auto athlete : a) {
            LL max_possible_weight = athlete.first - ws + 1;
            
            if (max_possible_weight > we) {
                max_weight = max(max_weight, max_possible_weight);
            }
        }
        
        cout << max_weight << endl;
    }
    return 0;
}
