ll dp[19][4][2];

ll solver(string &s, int ind, int tight, int nz)
{
	if (nz < 0) return 0LL;
	if (ind == s.size()) return 1LL;
	if (dp[ind][nz][tight] != -1) return dp[ind][nz][tight];
	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		if (tight and i > (s[ind] - '0')) break;
		ans += solver(s, ind + 1, tight and (i == (s[ind] - '0')), nz - ((i == 0) ? 0 : 1));
	}
	dp[ind][nz][tight] = ans;
	return ans;
}

ll get(ll n) {
	string s = to_string(n);
	memset(dp, -1, sizeof(dp));
	return solver(s, 0, 1, 3);
}

void solve() {
	ll l, r, ans = 0;
	cin >> l >> r;
	cout << get(r) - get(l - 1LL) << endl;
}