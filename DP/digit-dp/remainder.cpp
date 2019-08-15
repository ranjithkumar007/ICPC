// https://www.codechef.com/problems/DIGIMU
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

ll dp[2][20][3][5][7][9][1<<4];

ll solver(vl &a, ll ind = 0, bool tight = true, ll m3 = 0, ll m5 = 0, ll m7 = 0, ll m9 = 0, ll mask = 0)
{
	if (ind == a.size())
		return mask and (!(mask&1) or m3) and (!((mask>>1)&1) or m5) and (!((mask>>2)&1) or m7) and (!((mask>>3)&1) or m9);
	if (dp[tight][ind][m3][m5][m7][m9][mask] != -1) 
		return dp[tight][ind][m3][m5][m7][m9][mask];
	ll ans = 0;
	if (!mask) 
		ans += solver(a, ind + 1, false, (m3*10)%3, (m5*10)%5, (m7*10)%7, (m9*10)%9, mask);
	for (ll i = 3; i <= 9; i+=2) {
		if (tight and i > a[ind]) break;
		ans += solver(a, ind + 1, tight and i == a[ind], (m3*10+i)%3, (m5*10+i)%5, (m7*10+i)%7, (m9*10+i)%9, mask | (1<<((i-3)/2)));
	}
	dp[tight][ind][m3][m5][m7][m9][mask] = ans;
	return ans;
}

vl digits(ll n) {
	vl d;
	while(n) {
		d.pb(n%10);
		n/=10LL;
	}
	reverse(all(d));
	return d;
}

ll get(ll n)
{
	vl d = digits(n);
	memset(dp, -1, sizeof(dp));
	return solver(d);
}

void solve() {
	ll l, r, k;
	cin >> l >> r>>k;
	ll x = get(l-1), y = get(r);
	if ((y-x)<k){
		cout<<-1<<endl; return;
	}
	ll low = l, high = r;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		ll t2 = get(mid);
		if ((t2-x)<k) low = mid + 1;
		else high = mid - 1;
	}
	cout << low << endl;
}

int main()
{
    fastio;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
