#include <iostream>
using namespace std;
const int maxn = 1005;

int arr[maxn][maxn];
int main()
{
    // cout << 222 << endl;
    int n, m;
    int a, b, c, d;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--;b--;c--;d--;
        for (int x = a; x <= c; x++)
            for (int y = b; y <= d; y++)
                arr[x][y]++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", arr[i][j], i!=n-1 && j==n-1?'\n':' ');
    return 0;
}