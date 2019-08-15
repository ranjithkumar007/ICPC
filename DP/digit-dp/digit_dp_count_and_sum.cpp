// http://codeforces.com/contest/1073/problem/E
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define NFOR(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define rep(i, a) for (ll i = 0; i < a; i++)
#define endl "\n"
#define fi first
#define se second
#define MOD 998244353
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

ll dp[2][20][1<<10], sumdp[2][20][1<<10];
ll pows[20];

void init() {
	pows[0] = 1LL;
	FOR(i,1,19) pows[i] = (pows[i-1]*10LL)%MOD;
}

ll solver(ll ind, string &s, ll n, ll k, ll mask = 0, bool tight = true)
{
	if (ind == n) return __builtin_popcount(mask) <= k;
	if (dp[tight][ind][mask] != -1)
		return dp[tight][ind][mask];
	ll ans = 0, ans2 = 0;
	for (ll i = 0; i <= 9; i++) {
		bool ti = tight and (i == (s[ind]-'0'));
		bool zn = (mask == 0) and (i == 0);
		ll new_mask = mask;
		if (!zn) new_mask |= (1 <<i);
		ll temp = solver(ind + 1, s, n, k, new_mask, ti);
		ans = (ans + temp) % MOD;
		ans2 = (ans2 + sumdp[ti][ind + 1][new_mask]) % MOD;
		temp = (temp * i) % MOD;
		ans2 = (ans2 + (temp * pows[n-ind-1]) % MOD) % MOD;
		if (ti) break;
	}
	dp[tight][ind][mask] = ans;
	sumdp[tight][ind][mask] = ans2;
	return ans;
}

ll f(ll n, ll k)
{
	string s = to_string(n);
	memset(dp, -1, sizeof(dp));
	memset(sumdp, 0, sizeof(sumdp));
	solver(0, s, s.size(), k);
	return sumdp[1][0][0];
}

void solve() {
	ll l, r, k;
	cin>>l>>r>>k;
	cout<<(f(r, k)-f(l-1,k)+MOD)%MOD<<endl;
}

int main()
{
    fastio;
	init();
    ll t = 1;
    while (t--) {
        solve();
    }
}