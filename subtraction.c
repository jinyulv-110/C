
/*
С����һ������ʽ�ӣ�����a-b������a��b���ǷǸ���������֤����Ǹ���
���̴������ʽ�ӣ���������� 
*/
#include <stdio.h>

int main() {
    char expression[100];  //���expression�����дӵ�һ��Ԫ�ذ������������ 
    scanf("%s", expression);//��� 
    int num1 = 0, num2 = 0;  // ��ʼ���������ͼ���
    sscanf(expression, "%d-%d", &num1, &num2);  //��ȡ������������ 

    int result = num1 - num2;  
    printf("%d\n", result);  // ������

    return 0;
}
