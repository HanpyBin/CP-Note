#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1e5+3;
long long  info[maxn][3];
int  route[maxn];
int  vis[maxn]; //
long long  f[maxn];
int main()
{
    int n, m; //n总城市，m为访问个数
    long long res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &route[i]);
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d%d%d", &info[i][0], &info[i][1], &info[i][2]);
        f[i] = ceil(info[i][2] * 1.0 / (info[i][0] - info[i][1]));
    }
    for (int i = 0; i < m-1; i++)
    {
        // 这里是要加一个循环将vis每一个都加1吗？可以用差分
        int a = min(route[i], route[i+1]);
        int b = max(route[i], route[i+1]);
        vis[a]++;
        vis[b]--;
    }
    for (int i = 1; i < n; i++)
    {
        vis[i] += vis[i-1];
        if (vis[i] >= f[i-1]) //要买IC卡
        {
            res += info[i-1][1]*vis[i] + info[i-1][2];
            // cout << "b" << i << endl;
        }
        else
        {
            res += info[i-1][0]*vis[i];
            // cout << "a" << i << endl;
        }
    }
    printf("%lld", res);
    return 0;
}