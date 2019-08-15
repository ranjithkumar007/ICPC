
vl adj[2002];
vector<bool> vis(2002, false);

void dfs(ll v, stack<ll> &S)
{
	vis[v] = true;
	for (auto &u : adj[v]) {
		if (not vis[u])
			dfs(u, S);
	}
	S.push(v);
}

void solve() {
	ll n;
	cin>>n;
	ll temp;

	rep(i,n) {
		rep(j,n) {
			cin>>temp;
			if (temp) {
				adj[i].pb(j);
			}
		}
	}

	// sort by finish times
	stack<ll> S;
	rep(i, n)
		if (not vis[i])
			dfs(i, S);

	// rev graph
	vl adj2[2002];	
	rep (i, n) {
		for (auto &j : adj[i])
			adj2[j].pb(i);
	}

	rep (i, n) {
		adj[i] = adj2[i];
	}


	vis = vector<bool>(2002,false);
	ll ctr = 0;
	
	// dfs on G' acc to finish times
	while (not S.empty()) {
		ll s = S.top(); S.pop();
		// pr(s);
		if (not vis[s]) {
			ctr++;
			dfs(s, S);
		}
	}
}