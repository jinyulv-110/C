/*

С����һ���ַ��� s�� 
s��ֻ������Сд��ĸ������֪������ַ����ܷ�������ÿ��ġ�
ֻ�е� s ���������������ʱ��С���ŻῪ�ģ�
s �Ŀ�ʼ�����ַ�Ϊ LAN��
s ������ĸ��ַ�Ϊ QIAO��
ǰ�����ַ��ͺ��ĸ��ַ�֮����ַ�����ȫ��ΪСд��ĸ���߲����������ַ��� 
����ַ��� s ������С����ÿ��ģ������ AC��������� WA��
�����ʽ
*/


#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string a;
    cin>>a;
    if(a.substr(0, 3) == "LAN" && a.substr(a.size()-4, 4) == "QIAO"){
        for(int i=3;i<a.size()-4;i++){
            if(a[i]<97||a[i]>122){
                cout<<"WA";
                return 0;
            }
        }
        cout<<"AC";
    }
    else cout<<"WA";
    return 0;
}
