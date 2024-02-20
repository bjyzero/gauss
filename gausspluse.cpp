// 这种为进阶版高斯消元
// 内涵带入消元，因此可以处理无数无穷解情况的线性方程组

#include <bits/stdc++.h>
using namespace std;

#define maxn 510
double a[maxn][maxn], ans[maxn];
int n;

int solve(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        int maxx = i;
        for (int j = i + 1; i <= n; ++j)
        {
            if (fabs(a[maxx][i]) < fabs(a[j][i]))
                maxx = i;
        }

        if (!fabs(a[maxx][i]))
            continue;

        for (int j = i; j <= n + 1; ++j)
        {
            swap(a[i][j], a[maxx][j]);
        }

        double div = a[i][i]; // 区别：把系数化成 1
        for (int j = 1; j <= n + 1; ++j)
            a[i][j] /= div;
        for (int j = i + 1; j <= n; ++j)
        {
            div = a[j][i];
            for (int k = i; k <= n + 1; ++k)
            {
                a[j][k] -= a[i][k] * div;
            }
        }
    }
    ans[n] = a[n][n + 1];
    for (int i = n - 1; i >= 1; --i)
    {
        ans[i] = a[i][n + 1];
        for (int j = n; j >= i + 1; --j)
        {
            ans[i] -= a[i][j] * ans[j];
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << fixed << setprecision(2) << ans[i] << ' ';
    cout << '\n';
    return 0;
}

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

    int guass = solve(n, n);
    return 0;
}