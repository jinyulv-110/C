 #include <stdio.h>
//��Сֵ��ǰ��
void SelectSort(int arr[], int len)
{
	if (len < 1 || arr == nullptr) return;
 
	for (int i = 0; i < len; i++)
	{
		int minindex = i;//����������Сֵ������
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index]
		arr[index] = temp;
	}
}
//���ֵ�����
void SelectSort1(int arr[], int len)
{
	if (len < 1 || arr == nullptr) return;
 
	for (int i = len-1; i > 0; --i)
	{
		int index = i;//�����������ֵ������
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[index])
			{
				index = j;
			}
		}
		int temp = arr[index];
         arr[index] = arr[i];
         arr[i] = temp;
        }
	}
}

void PrintAddr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 9,1,2,5,7,4,8,6,3,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, len);
	PrintAddr(arr, len);
}
