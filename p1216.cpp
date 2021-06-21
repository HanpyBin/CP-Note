#include <iostream>
using namespace std;

/*
const int maxn = 1003;
int a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    
    int r;

    cin >> r;
    for (int i = 0; i < r; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < r; i++)
        dp[r-1][i] = a[r-1][i];
    for (int i = r-2; i >= 0; i--)
    {
        for (int j = 0; j < i+1; j++)
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
    }
    printf("%d", dp[0][0]);
    return 0;
}
*/
const int maxn = 1003;
int main()
{
    int r;
    cin >> r;
    int dp[maxn], a[maxn];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i+1; j++)
            cin >> a[j];
    }
}