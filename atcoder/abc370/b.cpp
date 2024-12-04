#include <bits/stdc++.h>
#include <queue>

using namespace std;

signed main() {

	int n;
	cin >> n;

	priority_queue<int> pq;

	for(int i = 0; i < n; i ++) {
		int t;
		cin >> t;
		pq.push(t);
	}
	int ans = 0;
	while(pq.size() > 1) {
		int a1 = pq.top();
		pq.pop();
		int a2 = pq.top();
		pq.pop();

		if(a1 - 1!= 0) {
			pq.push(a1 - 1);
		}
		if(a2 - 1 != 0) {
			pq.push(a2 - 1);
		}
		ans ++;
	}

	cout << ans << '\n';



	return 0;
}
