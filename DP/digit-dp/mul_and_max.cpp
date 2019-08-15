// https://codeforces.com/gym/100886/problem/G

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

ll dp[2][2][2][20], pow_9[20], pow_10[20], nines[20];

ll solver(vl &a, vl &b, ll N, ll Na, ll ind = 0, bool low_t = true, bool high_t = true)
{
	if (ind == N) return 1LL;
	if (dp[0][low_t][high_t][ind] != -1)
		return dp[0][low_t][high_t][ind];
	ll ans = -1;
	if (ind < (N - Na)) {
		ans = pow_9[N-ind-1];
		dp[1][low_t][high_t][ind] = nines[N-ind-1];
	}
	for (ll i = 0; i <= 9; i++) {
		if (low_t and i < a[ind]) continue;
		if (high_t and i > b[ind]) break;
		ll temp = solver(a, b, N, Na, ind + 1, low_t and i == a[ind], high_t and i == b[ind]);
		if (ans < i * temp) {
			ans = i * temp;
			dp[1][low_t][high_t][ind] = i * pow_10[N-ind-1] + dp[1][low_t and i == a[ind]][high_t and i == b[ind]][ind+1];
		}
	}
	dp[0][low_t][high_t][ind] = ans;
	return ans;
}

vl digits(ll n) {
	vl d;
	while(n) {
		d.pb(n%10);
		n/=10LL;
	}
	return d;
}

void solve() {
	nines[0] = 0;
	FOR(i,1,19) nines[i] = nines[i-1]*10LL+9LL;
	pow_10[0] = 1LL;
	FOR(i,1,19) pow_10[i] = pow_10[i-1]*10LL;
	pow_9[0] = 1LL;
	FOR(i,1,19) pow_9[i] = pow_9[i-1]*9LL;

	ll a, b;
	cin>>a>>b;
	memset(dp[0], -1, sizeof(dp[0]));
	memset(dp[1], 0, sizeof(dp[1]));
	
	vl aa = digits(a), bb = digits(b);
	a = aa.size(), b = bb.size();
	b -= a;
	while (b--) {
		aa.pb(0);
	}
	reverse(all(aa));
	reverse(all(bb));
	solver(aa, bb, bb.size(), a);
	// pr(dp[0][1][1][0]);
	cout << dp[1][1][1][0] << endl;
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
