// ���ָ�˹��Ԫ������ģ���û�д�����Ԫ
// ���ƣ�ֻ�ܴ������������ֻ��Ψһ���

#include <bits/stdc++.h>
using namespace std;

#define maxn 510
double a[maxn][maxn];

int n; // n �����̣�n ��δ֪��

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

    // ��ö����ȥ������һ��
    for (int i = 1; i <= n; ++i)
    {
        int maxx = i; // ����һ��ϵ�����ֵ����һ��֮ǰ����Щ�е�λ���Ѿ��̶������Ҫ�γ�һ���Խ��ߣ�ֻ�ܴ���һ������ɨ���ҵ�һ������
        for (int j = i + 1; j <= n; ++j)
        {
            if (fabs(a[maxx][i]) < fabs(a[j][i]))
                maxx = j;
        }

        // �ҵ���Ӧ��һ�е�����У�Ȼ��ʼ����
        for (int j = i; j <= n + 1; ++j)
        {
            swap(a[i][j], a[maxx][j]);
        }
        // �������� i �� �� i ��Ԫ�� a[i][i] ��Ϊ��һ����Ԫ

        // �ж���һ�����ϵ���ǲ���Ϊ 0
        // ��ʱ��Ӧ���������1.�޽� 2.��������
        if (a[i][i] == 0)
            continue; // ��һ����ԪΪ 0��Ҳ�Ͳ��ý��к������Ԫ

        // ��Ԫ���������е���һ����Ϊ 0������������Ҳ���м���仯
        double div = a[i][i];
        for (int j = 1; j <= n; ++j)
        {
            if (j != i)
            {
                for (int k = i; k <= n + 1; ++k)
                {
                    a[j][k] -= a[i][k] * a[j][i] / div; // ����ȳ��ٳ˾�����ʧ����
                }
            }
        }
    }

    // ������֮��Ϳ������
    for (int i = 1; i <= n; ++i)
    {
        cout << fixed << setprecision(2) << a[i][n + 1] / a[i][i] << '\n';
    }

    return 0;
}