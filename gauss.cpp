// 这种高斯消元是最常见的，即没有带入消元
// 劣势：只能处理给定方程组只有唯一解的

#include <bits/stdc++.h>
using namespace std;

#define maxn 510
double a[maxn][maxn];

int n; // n 个方程，n 个未知数

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
        {
            cin >> a[i][j];
        }
    }

    // 先枚举消去的是哪一列
    for (int i = 1; i <= n; ++i)
    {
        int maxx = i; // 找这一列系数最大值，这一列之前的那些行的位置已经固定，最后要形成一个对角线，只能从这一行往后扫，找到一个最大的
        for (int j = i + 1; j <= n; ++j)
        {
            if (fabs(a[maxx][i]) < fabs(a[j][i]))
                maxx = j;
        }

        // 找到对应这一列的最大行，然后开始交换
        for (int j = i; j <= n + 1; ++j)
        {
            swap(a[i][j], a[maxx][j]);
        }
        // 交换完后第 i 行 第 i 列元素 a[i][i] 即为这一列主元

        // 判断这一列最大系数是不是为 0
        // 此时对应两种情况：1.无解 2.有无数解
        if (a[i][i] == 0)
            continue; // 这一列主元为 0，也就不用进行后面的消元

        // 消元，将其他行的这一列消为 0，行内其他数也进行计算变化
        double div = a[i][i];
        for (int j = 1; j <= n; ++j)
        {
            if (j != i)
            {
                for (int k = i; k <= n + 1; ++k)
                {
                    a[j][k] -= a[i][k] * a[j][i] / div; // 如果先除再乘精度损失更大
                }
            }
        }
    }

    // 处理完之后就可以输出
    for (int i = 1; i <= n; ++i)
    {
        cout << fixed << setprecision(2) << a[i][n + 1] / a[i][i] << '\n';
    }

    return 0;
}