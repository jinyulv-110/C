/*ȴ˵���´��ң��ܲ�Ю������������ļ�� 
n Ա�ͽ�����Ҫ�˱����¡�Ϊ�����緽�㣬ÿλ�佫����פ����һ���ǳ��У��� ai��ʾ�� i ���佫פ���ĳǳر�š�

��һ�գ��ܲٿ������µ��佫���������������˳�˼�������ź��ӣ�����ߵ�ıʿ����˵����
����Т�����㿴�������ϵ��佫����������������ս֮��������Ҳ֪���������֮�£���ɻ�ľ��ǽᵳӪ˽���㿴�������ϣ���Щ��ס��һ���ǳ����Ҫ�Ƕ������ˣ�����ᡭ��

�������գ����������˲ܲٵĵ��ǡ���΢΢һЦ��˵����������Ӣ��������ѡ�佫��ȷʵҪ���ذ��������������Ҹ���������ϸѡ 
k Ա�ͽ��������Ǿ�����������ͬһ�ǳأ�������������Ҫ���鷳������������Σ���

�ܲ��������մ��ã�˵��������������������㣬��ѡ�� 
k Ա�ͽ���������м����ǵ�������һ���ǳصģ���*/
#include <stdio.h>
#include <stdlib.h>
#define N 100005
void mergeSort(int arr[], int left, int right);//�鲢����������
int main() {
    int n, k ,ans= 0;
    scanf("%d %d", &n, &k); //����n��k���ֱ��ʾ�佫������Ҫ��ѡ���佫��
    int arr[N] = { 0 }; //����һ�������¼ÿ���ǳ��ͽ������±��ʾ�ǳر��
    int citynumber = 0,max = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        arr[temp]++;//��¼ÿ���ǳ��ͽ���
        if (arr[temp] == 1)
            citynumber++;//��¼�ǳ��ж�����
        max = (max > temp ? max : temp);//�ҳ��ǳر�����ֵ������ʹ��
    }
  //����ǳص���������k����kȫ�����ǵ����ͽ�
    if (citynumber >= k)
        ans = k;
  //������ÿ���ǳ�ѡһ����������ѡ�˶�ǳص��佫
    else { 
        mergeSort(arr,0,max+1); //���ͽ��������ǳ�����Ӷൽ��(�鲢��
        //���м���,ÿ��citynumber�Ļ�������ѡһ���ǳأ���Ӧcitynumber������һ
        for (int i = 0, remain = k - citynumber; remain > 0; i++, citynumber--)
            remain -= (arr[i] - 1);//�Ѿ�Ĭ��ѡ��һ������Ҫ��1
        ans = citynumber;
    }
    printf("%d", ans);
    return 0;
}
//�鲢����(����ҿ�,����
void merge(int *arr, int left, int mid, int right) {
    int i = left, j = mid;
    int* temp = (int*)malloc((right - left) * 4);
    int index = 0;
    while (i < mid && j < right)  temp[index++] = (arr[i] > arr[j] ? arr[i++] : arr[j++]);
    while (i < mid) temp[index++] = arr[i++];
    while (j < right) temp[index++] = arr[j++];
    for (i = 0; i < index; i++) arr[left + i] = temp[i];
    free(temp);
}
void mergeSort(int *arr, int left, int right) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}
