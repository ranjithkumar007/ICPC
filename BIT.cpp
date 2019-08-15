// bit vector is 1 based indexing.
// A is expected to be 0 based indexing.
// ex : http://codeforces.com/contest/1076/problem/E
struct BIT {
	vl bit;
	ll N;
	BIT(ll _N = 0) {
		N = _N;
		bit.resize(N + 1, 0);
	}

	BIT(vl &A) {
		N = A.size();
		bit.resize(N + 1, 0);
		for (int i = 1; i <= N; i++)
			update(i, A[i-1]);
	}

	void update(ll idx, ll x) {
		while (idx <= N) {
			bit[idx] += x;
			idx += idx & (-idx);
		}
	}

	ll query(ll idx) {
		ll res = 0;
		while (idx) {
			res += bit[idx];
			idx -= idx & (-idx);
		}
		return res;
	}
};
