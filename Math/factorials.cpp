long long int bin_expo(long long int a, long long int expo)
{
	long long int res = 1LL;

	while (expo) {
		if (expo & 1LL)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		expo >>= 1;
	}
	return res;
}

const ll MAXN = 200005;
// inv is only true if MOD is prime. else use extended_euclid
ll inv[MAXN], fac[MAXN];

void pre() {
	fac[0] = fac[1] = 1;
	FOR (i, 2, MAXN - 1)
		fac[i] = (fac[i-1] * i) % MOD;

	inv[MAXN - 1] = bin_expo(fac[MAXN - 1], MOD - 2);
	NFOR (i, MAXN - 2, 0)
		inv[i] = (inv[i+1] * (i+1LL)) % MOD;
}

// inv using extended_euclid
// int get_inv(int a, int m)
// {
// 	int x, y;
// 	extended_euclid(a, m, x, y);
// 	if (x < 0) x += m;
// 	return x;
// }
