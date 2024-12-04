#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;

    int ans = 0;

    int l = -1, r = -1;

    while (n--) {
    	int a;
    	char s;
    	cin >> a >> s;

    	if(s == 'L') {
    		if(l == -1) l = a;
    		 {
    			ans += abs(l - a);
    			l = a;
    		}
    	}
    	else {
    		if(r == -1) r = a;
    		else {
    			ans += abs(r - a);
    			r = a;
    		}
    	}
    }


    cout << ans << '\n';

    return 0;
}
