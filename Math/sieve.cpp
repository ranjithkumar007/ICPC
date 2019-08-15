#define MAXN 100000
bool isP[MAXN + 1];

vector<long long> primes;
/* O(nlog(logn)) */
void sieve()
{
	memset(isP, true, sizeof(isP));
	isP[0] = isP[1] = false;
	for (long long i = 2; i * i <= MAXN; i++) {
		if (isP[i]) {
			for (long long j = i * i; j <= MAXN; j += i)
				isP[j] = false;
		}
	}
	for (long long i = 2; i <= MAXN; i++)
		if (isP[i])
			primes.push_back(i);
}


// segmented sieve
vector<int> sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	vector<int> primes;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = 0; i <= n; i++)
		if (isPrime[i]) {
			cout << i << " ";
			primes.push_back(i);
		}

	return primes;
}

void segmented_sieve(int n)
{
	int lim = floor(sqrt(n)) + 1;
	auto primes = sieve(lim);

	int low = lim, high = lim << 1;

	while (low < n) {
		high = min(high, n);

		vector<bool> isPrime(lim + 1, true);

		for (auto &p : primes) {
			int low_fac = floor(low / p) * p;
			if (low_fac < low) low_fac += p;

			for (int j = low_fac; j < high; j += p)
				isPrime[j - low] = false;
		}

		for (int i = low; i < high; i++)
			if (isPrime[i - low])
				cout << i << " ";
		low += lim;
		high += lim;
	}
}
