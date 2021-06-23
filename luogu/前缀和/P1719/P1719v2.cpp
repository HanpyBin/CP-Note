#include <iostream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;
/*

使用一维前缀和和一维dp进行矩阵压缩
即确定矩形的宽度之后进行一维dp
*/
const int maxn = 120 + 3;
int main()
{
	int n;
	int mat[maxn][maxn];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &mat[i][j]);
			mat[i][j] += mat[i-1][j];
		}
	int res = INT_MIN;
	int m[maxn], dp[maxn];
	for (int i = 1; i <= n; i++)
	{
		memset(dp, 0, sizeof(dp));
		for (int k = 1; k < i; k++)
			for (int j = 1; j <= n; j++)
			{
				m[j] = mat[i][j] - mat[k-1][j];
				dp[j] = max(m[j], dp[j-1]+m[j]);
				if (dp[j] > res)
					res = dp[j];
			}
	}
	cout << res;
	return 0;
}