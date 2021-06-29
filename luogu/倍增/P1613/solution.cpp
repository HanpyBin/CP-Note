#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// 倍增+最短路，若两点间距离是2^k，则认为两点之间的距离为
const int maxn = 50 + 3;
const int maxm = 20 + 2;
bool flag[maxn][maxn][maxm];
int dis[maxn][maxn];
int main()
{
	int n, m;
	int x, y;
	scanf("%d%d", &n, &m);
	memset(dis, 0x3f3f3f3f, sizeof dis);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		flag[x][y][0] = true;
		dis[x][y] = 1;
	}
	for (int k = 0; k < 20; k++)
		for (int t = 1; t <= n; t++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
				{
					if (flag[i][t][k] && flag[t][j][k])
					{
						flag[i][j][k+1] = true;
						dis[i][j] = 1;
					}
				}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <=n; j++)
				if (dis[i][k]+dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	cout << dis[1][n];
	return 0;
}