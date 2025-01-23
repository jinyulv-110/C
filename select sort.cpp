//选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。
//首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
//然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。
#include <stdio.h>

// 函数声明
void selection_sort(int a[], int len);
 
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度
 
    selection_sort(arr, len);  // 调用选择排序函数
 
    // 打印排序后的数组
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
 
// 选择排序函数
void selection_sort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;  // 记录最小值的位置，第一个元素默认最小
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[min]) {  // 找到目前最小值
                min = j;  // 记录最小值的位置
            }
        }
        // 交换两个变量
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}
 
/*
// 自定义交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
