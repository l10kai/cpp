struct LazySum {
	vector<int> ps;
	LazySum(int n) : ps(n, 0) {}

	//[l, r]
	void add(int l, int r, int val) {
		if (l > r) return;
		ps[l] += val;
		ps[r + 1] -= val;
	}
	void pushToAndClear(vector<int> &d) {
		int sum = 0;
		fore (i, 0, sz(ps)) {
			sum += ps[i];
			ps[i] = 0;
			if (i < sz(d))
				d[i] += sum;
		}
	}
};
