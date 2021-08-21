#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20 + 2;


int main()
{
	int arrive[maxn][maxn] = {0};
	int nums[maxn];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nums[i]);
	for (int i = 1; i < n; i++)
		for (int j = i+1; j <= n; j++)
		{
			scanf("%d", &arrive[i][j]);
			arrive[j][i] = arrive[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", arrive[i][j], j==n ? '\n' : ' ');
	return 0;
}