#include <iostream>
using namespace std;
int main()
{
	int i, n, a[20][20], k, temp2 = 0, x, y;
	while (1)
	{
		for (x = 0; x <= 19; x++)
			for (y = 0; y <= 19; y++)
				a[x][y] = 0;//��������ֵ��ʼ��Ϊ0
		k = 1;//kֵ���ã������ٴ����������
		cout << "���������������Ϸ��ı߳� : ";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			a[i][0] = k++;//���ĵ�һ������
			for (int temp1 = i; temp1 > 0;)//temp1�Ĳ�����forѭ���лᵼ��temp1��ֵ��������ĸı�
			{
				a[--temp1][++temp2] = k++;//���԰�temp1�ĵݼ������ŵ���ѭ������
			}
			temp2 = 0;//ÿ��ʹ����temp2������temp2��ֵ�����¸���ʹ��
		}
		for (x = 0; x < n; x++)
		{
			for (y = 0; y < n; y++)
			{
				if (a[x][y] != 0)//��ʼ������ֵĬ��Ϊ0������������ʱ�������0�������ų�0������
					cout << a[x][y] << "\t";
			}
			cout << endl << endl << endl;
		}
	}
}

