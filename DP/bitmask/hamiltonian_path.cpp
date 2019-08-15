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

// O(n * 2^n) 
// ** untested **
// const ll MAXN = 11;

// ll dp[1<<MAXN];

// void solve() {
// 	// memset
// 	ll n,m,x,y;
// 	cin>>n>>m;

// 	vl adj[n];

// 	rep(i,m) {
// 		cin >> x >> y;
// // 		x--,y--;
// 		adj[x].pb(y);
// 		adj[y].pb(x);
// 	}

// 	memset(dp, 0, sizeof(dp));

// 	rep(i, n) {
// 		dp[1<<i] = 1<<i;
// 	}

// 	vl M(n,0); // M[i] - mask of vertices incident on vertex i.

// 	rep(i, n) {
// 		for (auto &j : adj[i]) {
// 			M[j] |= 1 << i;
// 		}
// 	}

// 	ll all = 1<<n;
// 	rep(mask, all){
// 		rep(i, n) {
// 			if ((mask>>i) & 1) {
// 				dp[mask] |= dp[mask ^ (1 << i)] & M[i];
// 			}
// 		}
// 	}

// 	if (dp[all-1]) {
// 		cout << "YES\n";
// 		return;
// 	}
// 	cout << "NO\n";
// }



bool dp[MAXN][1<<MAXN];
// dp[i][mask] -> is there a hamiltonian path ending at i covering vertices from mask.
// O(n^2 * 2^n)

void solve() {
	// memset
	ll n,m,x,y;
	cin>>n>>m;

	vl adj[n];

	rep(i,m) {
		cin >> x >> y;
// 		x--,y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	memset(dp, false, sizeof(dp));

	rep(i, n) {
		dp[i][1<<i] = true;
	}

	ll all = 1<<n;
	rep(mask, all){
		rep(i, n) {
			if ((mask>>i) & 1) {
				for(auto &j : adj[i]) {
					if ((mask>>j)&1) {
						dp[i][mask] = dp[i][mask] or dp[j][mask ^ (1<<i)];
					}
				}
			}
		}
	}

	rep(i, n) {
		if (dp[i][all-1]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
