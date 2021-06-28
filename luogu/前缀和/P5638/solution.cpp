#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6+3;
int main()
{
	int n, k;
	// if (k >= n-1)
	// {
	// 	printf("%d", 0);
	// 	return 0;
	// }
	scanf("%d%d", &n, &k);
	ll sum[maxn] = {0};
	for (int i = 1; i < n; i++)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i-1];
		// cout << sum[i] << endl;
	}
	if (!k)
	{
		printf("%lld", sum[n-1]);
		return 0;
	}
	ll res = sum[k];
	for (int i = k+1; i < n; i++)
	{
		res = max(res, sum[i]-sum[i-k]);
		// cout << sum[i] - sum[i-k] << endl;
	}
	printf("%lld", sum[n-1]-res);
	return 0;
}