#define MAXN 100000
long long spf[MAXN + 1];

void sieve()
{
	spf[1] = 1LL;
	for (long long i = 2; i <= MAXN; i++) spf[i] = i;
	for (long long i = 2; i * i <= MAXN; i++) {
		if (spf[i] == i) {
			for (long long j = i * i; j <= MAXN; j += i)
				spf[j] = i;
		}
	}
}

// returns list of prime factors(not distinct)
vector<long long> factorise(long long a)
{
	vector<long long> fac;
	while (a != 1) {
		fac.push_back(spf[a]);
		a /= spf[a];
	}
	return fac;
}
