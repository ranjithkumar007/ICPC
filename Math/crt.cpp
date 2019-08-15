int get_inv(int a, int m)
{
	int x, y;
	extended_euclid(a, m, x, y);
	if (x < 0) x += m;
	return x;
}

int crt(vector<int> &num, vector<int>& rem, int mod)
{
	int prod = 1;
	for (auto &n : num) prod *= n;

	int res = 0;
	for (int i = 0; i < num.size(); i++) {
		int pp = prod / num[i];
		res = (res + (pp * (rem[i] * get_inv(pp, num[i])) % prod)% prod) % prod;
	}
	return res;
}
