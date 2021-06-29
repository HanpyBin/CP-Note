#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 5e4 + 3;
int maxx[maxn][32], mini[maxn][32];
int RMQ(int l, int r)
{
	int k = floor(log2(r-l+1));
	return max(maxx[l][k], maxx[r-(1<<k)+1][k]) - min(mini[l][k], mini[r-(1<<k)+1][k]);
}
int main()
{
	int n, m;
	int t;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		maxx[i][0] = t;
		mini[i][0] = t;
	}
	for (int k = 1; 1<<k <= n; k++)
		for (int i = 1; i+(1<<k)-1 <= n; i++)
		{
			maxx[i][k] = max(maxx[i][k-1], maxx[i+(1<<k-1)][k-1]);
			mini[i][k] = min(mini[i][k-1], mini[i+(1<<k-1)][k-1]);
		}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", RMQ(l, r));
	}
	return 0;
}