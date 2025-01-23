//ѡ������Selection sort����һ�ּ�ֱ�۵������㷨�����Ĺ���ԭ�����¡�
//������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�
//Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�
#include <stdio.h>

// ��������
void selection_sort(int a[], int len);
 
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);  // �������鳤��
 
    selection_sort(arr, len);  // ����ѡ��������
 
    // ��ӡ����������
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
 
// ѡ��������
void selection_sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;  // ��¼��Сֵ��λ�ã���һ��Ԫ��Ĭ����С
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[min]) {  // �ҵ�Ŀǰ��Сֵ
                min = j;  // ��¼��Сֵ��λ��
            }
        }
        // ������������
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}
 
/*
// �Զ��彻������
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
