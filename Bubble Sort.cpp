//ð������
//ð������Ӣ�Bubble Sort����һ�ּ򵥵������㷨�����ظ����߷ù�Ҫ��������У�
//һ�αȽ�����Ԫ�أ�������ǵ�˳����Ӵ�С������ĸ��A��Z������Ͱ����ǽ���������

#include <stdio.h>
 
// ��������
void bubble_sort(int arr[], int len);
 
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);  // �������鳤��
 
    bubble_sort(arr, len);  // ����ð��������
 
    // ��ӡ����������
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
 
// ð��������
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            // ����Ԫ��λ��
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
