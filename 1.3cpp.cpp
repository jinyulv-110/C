#include <iostream>
using namespace std;
int main()
{
	int i, j, n, k = 1, a[20][20];
	while (1)
	{
		cout << "���������ı߳� : ";
		cin >> n;
		for (i = 0; i < n / 2; i++)//�������������
		{
			for (j = i; j < n - i - 1; j++)
				a[i][j] = k++;//�����һ���֣��Ϸ�
			for (j = i; j < n - i - 1; j++)
				a[j][n - i - 1] = k++;//����ڶ����֣��ұ�
			for (j = n - i - 1; j > i; j--)
				a[n - i - 1][j] = k++;//����������֣��·�
			for (j = n - i - 1; j > i; j--)
				a[j][i] = k++;//������Ĳ��֣����
		}
		if (n % 2 != 0)//���߳�Ϊ����ʱ�������м䵥����һ������ֵ
			a[(n - 1) / 2][(n - 1) / 2] = n * n;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << a[i][j] << "\t";//������
			}
			cout << endl << endl << endl << endl;
		}
	}
}

