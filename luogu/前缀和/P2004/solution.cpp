#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int maxn = 1e3 + 5;

int arr[maxn][maxn];
int main()
{
	int n, m, c;
	int resx, resy;
	int res = INT_MIN;
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i-1][j];
		}
	// int dp[maxn];
	for (int i = c; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= c; j++)
			temp += arr[i][j] - arr[i-c][j];
		if (temp > res)
		{
			res = temp;
			resx = i-c+1;
			resy = 1;
		}
		for (int j = c+1; j <= m; j++)
		{
			temp += arr[i][j] - arr[i-c][j] - (arr[i][j-c] - arr[i-c][j-c]);
			if (temp > res)
			{
				res = temp;
				resx = i-c+1;
				resy = j-c+1;
			}
		}
	}
	printf("%d %d", resx, resy);
	return 0;
}