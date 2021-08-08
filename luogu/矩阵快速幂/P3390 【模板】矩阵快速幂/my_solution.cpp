#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 105;
const ll mod = 1e9+7;
ll n, k;
struct matrix
{
	ll mat[maxn][maxn];
};

matrix Mul(matrix& a, matrix& b)
{
	matrix t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			t.mat[i][j] = 0;
			for (int k = 0; k < n; k++)
				t.mat[i][j] = (t.mat[i][j] + (a.mat[i][k] * b.mat[k][j])%mod)%mod;
		}
	return t;
}
matrix QuickPower(matrix& a, matrix& b)
{
	while (k)
	{
		if (k & 1)
			a = Mul(a, b);
		b = Mul(b, b);
		k >>= 1;
	}
	return a;
}

void Print(matrix& x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%lld%c", x.mat[i][j], j==n-1?'\n':' ');
}
int main()
{

	scanf("%lld%lld", &n, &k);
	matrix res, temp;
	memset(temp.mat, 0, sizeof(temp.mat));
	for (int i = 0; i < n; i++)
	{
		temp.mat[i][i] = 1;
		for (int j = 0; j < n; j++)
			scanf("%lld", &res.mat[i][j]);
	}
	res = QuickPower(temp, res);
	Print(res);
	return 0;
}
