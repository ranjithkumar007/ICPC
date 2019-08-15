/*  O(E Log V) */
ll prim(vector<pll> adj[], ll n)	/* adj[i][j] = {v, w} */
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll>> > pq; // min heap
	vl key(n, inf), par(n, -1);	// 0 based indexing
	vector<bool> in_mst(n, false);
	pq.push({0, 0});
	key[0] = 0;

	while (not pq.empty()) {
		ll u = pq.top().se; pq.pop();
		in_mst[u] = true;
		for (auto &p : adj[u]) {
			ll v, w;
			tie(v, w) = p;	/* check order of v, w */
			if (not in_mst[v] and key[v] > w) {
				key[v] = w;
				pq.push({w, v});
				par[v] = u;
			}
		}
	}

	ll mst = 0;
	rep(i, n)
		mst += key[i];
	return mst;
}

// Kruskal
struct dsu {
	vl parent, sz;		/* use an unordered_map, if n > 1e6 */
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

	bool _union(ll a, ll b) {			/* O(α(n)) */
		a = root(a), b = root(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		parent[b] = a;
		return true;
	}
};

/* O(ElogE) or O(ElogV) */
ll kruskal(vector<pair<ll, pll>> &edges, ll n, ll m)
{
	sort(all(edges));	/* edges[i] = {w, {u, v}}*/
	dsu d(n);
	ll mst = 0;

	for(auto &ed : edges) {
		if (d._union(ed.se.fi, ed.se.se))
			mst += ed.fi;
	}
	return mst;
}
