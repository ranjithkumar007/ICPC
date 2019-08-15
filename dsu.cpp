// dsu, union find

struct dsu {
	vl parent, sz;	/* use an unordered_map, if n > 1e6 */
	dsu(ll n) {
		parent.resize(n);
		sz.resize(n, 1);
		rep(i, n)
			parent[i] = i;
	}

	ll root(ll a) {
		if (parent[a] != a)
			parent[a] = root(parent[a]);
		return parent[a];
	}

	ll size(ll a) { return sz[root(a)];}

	bool _union(ll a, ll b) {		/* O(α(n)) */
		a = root(a), b = root(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		parent[b] = a;
		return true;
	}
};
