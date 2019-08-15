#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mat_mul(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
	if (a[0].size() != b.size()) {return {{-1}};}
	int n = a.size(), m = b[0].size(), p = b.size();
	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < p; k++)
				ans[i][j] += a[i][k] * b[k][j];
	return ans;
}

vector<vector<int>> mat_expo(vector<vector<int>> &a, int expo)
{
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	while(expo) {
		if (expo & 1)
			ans = mat_mul(ans, a);
		a = mat_mul(a, a);
		expo >>= 1;
	}
	return ans;
}

int main() {
	// F(x) = a*F(x-1) + b*F(x-2) + c*F(x-3)
	vector<vector<int>> mat_vec(3, vector<int>(3, 0));
	int n, a,aa,bb,b,cc,c;
	cin >> a >> b >> c;
	cin >> aa >> bb >> cc;
	cin >> n;
	mat_vec[0][0] = a, mat_vec[0][1] = b, mat_vec[0][2] = c;
	mat_vec[1][0] = 1, mat_vec[2][1] = 1;
	auto mexp = mat_expo(mat_vec, n - 2);
	cout << mexp[0][0] * aa + mexp[0][1] * bb + mexp[0][2] * cc << endl;
}
