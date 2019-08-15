/*  O(E Log V) */
ll dijkstra(vector<pll> adj[], ll n, ll src = 0)	/* adj[i][j] = {v, w} */
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll>> > pq; // min heap
	vl dist(n, inf), par(n, -1);
	vector<bool> mark(n, false);
	pq.push({0, src});
	dist[src] = 0;

	ll maxm = 0;
	while (not pq.empty()) {
		ll u = pq.top().se; pq.pop();
		if (mark[u]) continue;
		mark[u] = true;
		for (auto &p : adj[u]) {
			ll v, w;
			tie(v, w) = p;	/* check order of v, w */
			if (dist[v] > w + dist[u]) {
				dist[v] = w + dist[u];
				par[v] = u;
				pq.push({dist[v], v});
			}
		}
	}
	rep(i, n) {
		if (dist[i] == inf) continue;
		// do something
	}
}


/* O(V**3) */
void floyd_warshall(vector<pll> adj[], ll n)	/* adj[i][j] = {v, w} */
{
	vvl dist(n, vl(n, inf));
	rep(i, n) for (auto &p : adj[i]) dist[i][p.ff] = p.ss;	/* init to orig graph */
	rep(k, n) rep(i, n) rep(j, n) 
		if (dist[i][k] != inf and dist[k][j] != inf)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}


/* O(EV) */
// note : for undirected graph, if there is a neg edge, it => there is a neg wgt cycle
ll bellmanford(vector<pll> adj[], ll n, ll src = 0)	/* adj[i][j] = {v, w} */
{
	vl dist(n, inf);
	dist[src] = 0;
	
	rep(i, n) {		// max |V| – 1 edges in any simple path
		rep(j, n) {
			if (dist[j] == inf) continue;
			for (auto &p : adj[j]) {
				if (dist[j] + p.ss < dist[p.ff]) {
					if (i == (n - 1)) return -1; 	 /* negative weight cycle detected */
					dist[p.ff] = dist[j] + p.ss;
				}
			}
		}
	}
	return 0;
}
