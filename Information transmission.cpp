#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    // ���ڴ��������Ĵ���
    int a = 0;
    int b = 0;
    int c = 0;
    int t = 0;//����
    scanf("%d", &t);
    printf("\n");
    int sum = 0;
    int i = 0;
    for (i = 0; i < t; i++)
    {
        int j = 0;
        sum = 0;
        scanf("%d %d %d", &a, &b, &c);//��������
        while (a != b)
        {

            if ((a + 1) % c == 0)
            {
                a = a + 2;
                sum++;
            }
            if ((a + 2) % c == 0)
            {
                a = a + 1;
                sum++;
            }
            if (a + 1 == b)
            {
                a++;
                sum++;
            }
            else
            {
                a = a + 2;
                sum++;
            }
        }
        printf("%d ", sum);
    }
    return 0;
}