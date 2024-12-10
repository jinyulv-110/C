/*却说天下大乱，曹操挟天子以令诸侯，招募了 
n 员猛将，想要兴兵南下。为了联络方便，每位武将都会驻扎在一个城池中，用 ai表示第 i 个武将驻扎的城池编号。

这一日，曹操看着账下的武将名单，不禁陷入了沉思。他摸着胡子，对身边的谋士郭嘉说道：
“奉孝啊，你看这名单上的武将，个个都是能征善战之辈，但你也知道，这军中之事，最忌讳的就是结党营私。你看这名单上，有些人住在一个城池里，这要是都带上了，难免会…”

郭嘉听罢，立刻明白了曹操的担忧。他微微一笑，说道：“主公英明！这挑选武将，确实要慎重啊！不如这样，我给主公精挑细选 
k 员猛将，让他们尽量避免来自同一城池，以免生出不必要的麻烦。主公意下如何？”

曹操听后龙颜大悦，说道：“妙啊！那你快帮我算算，挑选的 
k 员猛将，最多能有几个是单独来自一个城池的？”*/
#include <stdio.h>
#include <stdlib.h>
#define N 100005
void mergeSort(int arr[], int left, int right);//归并排序函数声明
int main() {
    int n, k ,ans= 0;
    scanf("%d %d", &n, &k); //输入n和k，分别表示武将总数和要挑选的武将数
    int arr[N] = { 0 }; //创建一个数组记录每座城池猛将数，下标表示城池编号
    int citynumber = 0,max = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        arr[temp]++;//记录每座城池猛将数
        if (arr[temp] == 1)
            citynumber++;//记录城池有多少座
        max = (max > temp ? max : temp);//找出城池编号最大值，后续使用
    }
  //如果城池的数量超过k，则k全都能是单独猛将
    if (citynumber >= k)
        ans = k;
  //否则，先每个城池选一个，再优先选人多城池的武将
    else { 
        mergeSort(arr,0,max+1); //按猛将数量将城池排序从多到少(归并）
        //进行计算,每在citynumber的基础上再选一个城池，对应citynumber数量减一
        for (int i = 0, remain = k - citynumber; remain > 0; i++, citynumber--)
            remain -= (arr[i] - 1);//已经默认选了一个，需要减1
        ans = citynumber;
    }
    printf("%d", ans);
    return 0;
}
//归并排序(左闭右开,降序）
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
