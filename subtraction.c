
/*
小兰有一个减法式子，形如a-b，其中a和b都是非负数（不保证结果非负）
请编程处理这个式子，输出运算结果 
*/
#include <stdio.h>

int main() {
    char expression[100];  //会把expression数组中从第一个元素把数据逐个填入 
    scanf("%s", expression);//输出 
    int num1 = 0, num2 = 0;  // 初始化被减数和减数
    sscanf(expression, "%d-%d", &num1, &num2);  //提取被减数，减数 

    int result = num1 - num2;  
    printf("%d\n", result);  // 输出结果

    return 0;
}
