#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int maxn = 120 + 3;
/*
求出二位前缀和
针对每个方形求一次权值和即可

*/
int main()
{
	int mat[maxn][maxn] = {0};
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &mat[i][j]);
			mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
		}
	int res = INT_MIN;
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			for (int c = 1; c < a; c++)
				for (int d = 1; d < b; d++)
				{
					int t = mat[a][b] - mat[c-1][b] - mat[a][d-1] + mat[c-1][d-1];
					if (t > res)
						res = t;
				}
	printf("%d", res);
	return 0;
}
// (a,b)(c,d) = mat[c][d]-mat[a-1][d]-mat[c][b-1]+mat[a-1][b-1]