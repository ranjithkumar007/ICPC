// https://codeforces.com/problemset/problem/453/B
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

const ll MAXN = 110, MAXK = 17;
ll dp[MAXN][1<<MAXK], via[MAXN][1<<MAXK];

void solve() {
	ll n;
	cin >> n;
	vl A(n);
	rep(i, n)
		cin >> A[i];

	ll all = 1<<MAXK;
	rep(i, all)
		FOR(j, 1, n) {
			via[j][i] = 1;
			dp[j][i] = inf;
		}

	vl primes;
	FOR(i,2,61) {
		bool flg = true;
		FOR(j,2,i-1){
			if(i%j==0) {
				flg = false;
				break;
			}
		}
		if (flg)
			primes.pb(i);
	}

	ll fact[61];
	ll k = primes.size();
	fact[0] = fact[1] = 0;

	FOR(i,2,60) {
		ll tmp = 0;
		rep(j, k) {
			if (i%primes[j]==0)
				tmp |= 1<<j;
		}
		fact[i] = tmp;
	}

	rep(i, all)
		dp[0][i] = 0;

	FOR(i, 1, n) {
		FOR(j, 1, 60) {
			ll st_mask = (all-1)&(~fact[j]);
			for (ll mask = st_mask; ; mask = (mask-1)&st_mask) {
				ll nmask = mask|fact[j];
				if (dp[i-1][mask] != inf and dp[i][nmask] > dp[i-1][mask] + abs(A[i-1]-j)) {
					dp[i][nmask] = dp[i-1][mask] + abs(A[i-1]-j);
					via[i][nmask] = j;
				}
				if (mask==0) break;
			}
		}
	}

	ll i = n, mask = all-1;
	vl ans(n);
	while (i > 0) {
		ans[i-1] = via[i][mask];
		mask = mask&~fact[ans[i-1]];
		i--;
	}
	for(auto&j:ans)
		cout<<j<<" ";
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
