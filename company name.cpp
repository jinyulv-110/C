/*��һ������Lanqiao �Ĺ�˾����˾���ܲ÷ǳ�ϲ���Լ���˾�����֡�
����ΪֻҪ����ĸ����������ܹ���ɹ�˾�����֣���ô�����Ͼ��ǹ�˾���ֵ���ȷƴд��
����˵��Lanqioa��anqiaoL��qiaoLan �� Lnqiaao ���ǹ�˾���ֵ���ȷƴд��
����������һ��Ҫ�󣬹�˾���ֿ�ͷ����ĸ L �����Ǵ�д��ĸ��������ĸ���붼��Сд��ĸ��
���죬�ܲ�д��һ������Ϊn���ַ���s���ɴ�д��Сд��ĸ��ɡ����������ж�����ַ����Ƿ�������˾�����ֵ���ȷƴд��
������˵���ַ����Ĵ���C/C++����Ҫ����STL String��



#include<bits/stdc++.h>
using namespace std;
int main() {
    string A = "Lanqiao";
    sort(A.begin(), A.end());
    int t;
    cin >> t; // �����������������
    for (int i = 0; i < t; ++i) {
        int n;       cin >> n;  
        string s;    cin >> s;  
        sort(s.begin(), s.end()); // �������ַ�������
        if (s == A)  
		cout << "YES"<< endl;
        else      
		cout << "NO" << endl;
    }
    return 0;
*/



#include<bits/stdc++.h>
using namespace std;

int main() {
    // ���岢��ʼ���ַ���AΪ"Lanqiao"
    string A = "Lanqiao";
    // ���ַ���A��������ʹ���ַ����ֵ�������
    sort(A.begin(), A.end());

    int t;
    cin >> t; 
    for (int i = 0; i < t; ++i) {
        // ����ԭ���ж�ȡ����n�Ĵ��룬��δʹ����ɾ��

        string s;
        cin >> s;  
        // ��������ַ���s���������Ա������A�Ƚ�
        sort(s.begin(), s.end()); 

        if (s == A)  
            cout << "YES"<< endl;
        else      
            cout << "NO" << endl;
    }

    return 0;
}
