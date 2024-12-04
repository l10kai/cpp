#include <bits/stdc++.h>

using namespace std;

signed main() {


	int a, b;
	cin >> a >> b;

	int ans = 0;

	for(int i = -1000; i < 1000; i ++) {
		if(b - i == a - b) ans ++;
		else if(a - i == b - a) ans ++;

		else if(i -a == b - i ) ans ++;
		else if(i - b == a - i) ans ++;
		else if(a - b == i - a) ans ++;
		else if(b - a  ==i - b ) ans ++;
	}

	cout << ans << '\n';

	return 0;
}
