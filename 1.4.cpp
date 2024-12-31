#include <iostream>
using namespace std;
int main()
{
	int i, n, a[20][20], k, temp2 = 0, x, y;
	while (1)
	{
		for (x = 0; x <= 19; x++)
			for (y = 0; y <= 19; y++)
				a[x][y] = 0;//数组所有值初始化为0
		k = 1;//k值重置，用于再次输出三角形
		cout << "请输入上三角形上方的边长 : ";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			a[i][0] = k++;//环的第一个数据
			for (int temp1 = i; temp1 > 0;)//temp1的操作在for循环中会导致temp1的值过早或过晚的改变
			{
				a[--temp1][++temp2] = k++;//所以把temp1的递减操作放到了循环里面
			}
			temp2 = 0;//每次使用完temp2后重置temp2的值用于下个环使用
		}
		for (x = 0; x < n; x++)
		{
			for (y = 0; y < n; y++)
			{
				if (a[x][y] != 0)//初始化所有值默认为0，而正常运行时不会出现0，所以排除0的数据
					cout << a[x][y] << "\t";
			}
			cout << endl << endl << endl;
		}
	}
}

