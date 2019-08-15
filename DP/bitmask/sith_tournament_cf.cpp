// https://codeforces.com/contest/678/problem/E
// similar to hamiltonian path.
// here starting vertex as state.
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

const ll MAXN = 19;
ld dp[MAXN][1<<MAXN];

void solve() {
	ll n;
	cin >> n;
	
	ld p[n][n];
	rep(i, n)
		rep(j, n)
			cin >> p[i][j];

	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;

	ll all = 1<<n;
	rep(mask, all) {
		rep(i, n) {
			if ((mask>>i)&1) {
				rep(j, n) {
					if ((mask>>j)&1 and j != i) {
						dp[i][mask] = max(dp[i][mask], dp[j][mask^(1<<i)] * p[j][i] + dp[i][mask^(1<<j)] * p[i][j]);
					}
				}
			}
		}
	}

	ld ans = 0;
	rep(i, n) {
		ans = max(ans, dp[i][all-1]);
	}

	cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
    fastio;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
