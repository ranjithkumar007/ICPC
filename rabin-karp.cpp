inline bool compare(string &a, string &b, int starta)
{
    
	int n = b.length();
	if (starta + n > a.length()) return false;
	for (int i = 0; i < n; i++) {
		if (a[starta + i] != b[i]) return false;
	}
	return true;
}

void rabin_karp(string p, string t, int q)
{
	int n = t.length(), m = p.length();
	long long int MOD = 10000007;
	long long int hashp = 0, hasht = 0;
	int base = 256;
	int num_occur = 0;
	long long  pwr = 1;

	for (int i = 0; i < m - 1; i++)
		pwr = (pwr * base) % MOD;

	for (int i = 0; i < m; i++) {
		hashp = ((hashp * base) % MOD + (int)p[i]) % MOD;
		hasht = ((hasht * base) % MOD + (int)t[i]) % MOD;
	}

	if (hashp == hasht and compare(t, p, 0)) num_occur++;

	for (int i = m; i < n; i++) {
		hasht = (((hasht - ((int)t[i-m] * pwr) % MOD) * base) % MOD + (int)t[i] + MOD) % MOD;
		if (hashp == hasht and compare(t, p, i - m + 1)) num_occur++;
	}
	
	cout<< num_occur<<endl;
}
