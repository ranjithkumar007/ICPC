#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define NFOR(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define rep(i, a) for (ll i = 0; i < a; i++)
#define endl "\n"
#define fi first
#define se second
#define MOD 1000000007
#define inf 1e12
#define pb push_back
#define Case cout<<"Case #"<<++cas<<": ";
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

typedef long double ld;

const ll MAXN = 11;

ll dp[MAXN][1<<MAXN];
// dp[i][mask] -> shortest hamiltonian path ending at i covering vertices from mask.
// O(n^2 * 2^n)

void solve() {
	// memset
	ll n,m,x,y,z,u,w;
	cin>>n>>m;

	vector<pll> adj[n];

	rep(i,m) {
		cin >> x >> y >> z;
		x--,y--;
		adj[x].pb({y,z});
		adj[y].pb({x,z});
	}

	ll all = 1<<n;
	rep(i, n) {
		rep(j, all) {
			if (j==(1<<i))
				dp[i][j] = 0;
			else
				dp[i][j] = inf;
		}
	}

	rep(mask, all){
		rep(i, n) {
			if ((mask>>i) & 1) {
				for(auto &j : adj[i]) {
					tie(u, w) = j;
					if ((mask>>u)&1 and dp[u][mask ^ (1<<i)] != inf) {
						dp[i][mask] = min(dp[i][mask], dp[u][mask ^ (1<<i)]+w);
					}
				}
			}
		}
	}

	ll ans = inf;
	rep(i, n) {
		ans = min(ans, dp[i][all-1]);
	}
	cout << ans << endl;
}

int main()
{
    fastio;
    ll t  = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
