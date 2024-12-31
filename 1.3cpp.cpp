#include <iostream>
using namespace std;
int main()
{
	int i, j, n, k = 1, a[20][20];
	while (1)
	{
		cout << "请输入矩阵的边长 : ";
		cin >> n;
		for (i = 0; i < n / 2; i++)//计算出环的总数
		{
			for (j = i; j < n - i - 1; j++)
				a[i][j] = k++;//矩阵第一部分：上方
			for (j = i; j < n - i - 1; j++)
				a[j][n - i - 1] = k++;//矩阵第二部分：右边
			for (j = n - i - 1; j > i; j--)
				a[n - i - 1][j] = k++;//矩阵第三部分：下方
			for (j = n - i - 1; j > i; j--)
				a[j][i] = k++;//矩阵第四部分：左边
		}
		if (n % 2 != 0)//当边长为奇数时，给正中间单独的一个数赋值
			a[(n - 1) / 2][(n - 1) / 2] = n * n;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << a[i][j] << "\t";//输出结果
			}
			cout << endl << endl << endl << endl;
		}
	}
}

