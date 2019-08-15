vi findlps(string s)	/* O(s.length()) */
{
	int n = s.size(), i = 1, j = 0;
	vi lps(n); lps[0] = 0;
	while (i < n) {
		if (s[i] == s[j]) lps[i++] = ++j;
		else if (j) j = lps[j - 1];
		else lps[i++] = 0, j = 0;
	}
	return lps;
}

vi kmp(string t, string p)		/* O(t.length()) */
{
	vi lps = findlps(p), ind;
	int n = t.size(), m = p.size(), i = 0, j = 0;
	while (i < n) {
		if (t[i] == p[j]) i++, j++;
		else if (j) j = lps[j - 1];
		else i++;
		if (j == m) {
			ind.pb(i);
			j = lps[j - 1];
		}
	}
	return ind;
}
