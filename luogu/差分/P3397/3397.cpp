/*
使用差分，对于某一个方形，(1,1), (3, 3)，则可以有
1 0 0 -1
1 0 0 -1
1 0 0 -1
其中，元素arr[i][j]的值表示matrix[i][j]-matrix[i][j-1]
*/
#include <iostream>
using namespace std;
const int maxn = 1e3 + 5;
int arr[maxn][maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ax, ay, bx, by;
    while (m--)
    {
        scanf("%d%d%d%d", &ax, &ay, &bx, &by);
        for (int i = ax; i <= bx; i++)
        {
            arr[i][ay]++;
            arr[i][by+1]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            arr[i][j] += arr[i][j-1];
            printf("%d%c", arr[i][j], i != n && j == n ? '\n' : ' ');
        }
    }
    return 0;
}