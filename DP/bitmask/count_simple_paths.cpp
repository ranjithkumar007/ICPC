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

const ll MAXN = 20;

// dp[i][mask] -> #ham walks starting at first(mask) and ending at i.
ll dp[MAXN][1<<MAXN];
bool adj_mat[MAXN][MAXN];

void solve() {
	ll n,m,x,y;
	cin>>n>>m;

	memset(adj_mat, false, sizeof(adj_mat));
	vl adj[n];
	rep(i, m) {
		cin >> x >> y;
		x--,y--;
		adj_mat[x][y] = adj_mat[y][x] = true;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	memset(dp, 0, sizeof(dp));
	rep(i, n)
		dp[i][1<<i] = 1;

	ll ans = 0;
	ll all = 1<<n;
	
	rep(mask, all) {
		ll rb = (mask & (-mask));
		ll cnt = 0, x = 1;
		while (x != rb) {
			x <<= 1;
			cnt++;
		}
		ll pop = __builtin_popcount(mask);

		rep(i, n) {
			if ((mask>>i)&1 and cnt != i) {
				for (auto &j : adj[i]) {
					if ((mask>>j)&1)
						dp[i][mask] += dp[j][mask ^ (1<<i)];
				}
				if (adj_mat[i][cnt] and pop >= 3) // cycle
					ans += dp[i][mask];		
			}
		}
	}

	cout << ans / 2 << endl;
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
