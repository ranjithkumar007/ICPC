// http://codeforces.com/contest/1062/problem/E : Segtree + LCA

const ll LOGN = 18, MAXN = 100005;

ll par[LOGN][MAXN], H[MAXN], val[MAXN];
ll timer = 1;

void dfs(vl adj[], ll u, ll pv = -1)
{
	if (pv == -1) {
		H[u] = 0;
		par[0][u] = u;
	} else {
		H[u] = H[pv] + 1;
		par[0][u] = pv;
	}
	val[u] = timer++;
	for (auto &v : adj[u]) {
		if (v != pv)
			dfs(adj, v, u);
	}
}

void init_st(ll n)
{
	for (ll j = 1; (1 << j) < n; j++) {
		for (ll i = 0; i < n; i++) 
			par[j][i] = par[j-1][par[j-1][i]];
	}
}

ll lca(vl adj[], ll u, ll v, ll n)
{
	ll diff = H[u] - H[v];
	if (diff < 0) {
		swap(u, v);
		diff *= -1;
	}
	ll max_depth = log(n)/log(2);
	for (ll j = max_depth; j >= 0; j--) {
		if ((diff >> j) & 1)
			u = par[j][u];
	}

	if (u == v) return u;
	for (ll j = max_depth; j >= 0; j--) {
		if (par[j][u] != par[j][v]) {
			u = par[j][u];
			v = par[j][v];
		}
	}
	return par[0][u];
}
