/*�� N ��ƻ����Ҫ�ָ� M ���ˣ�
Ҫ��ÿ���˵õ���ƻ���� ��� �����Ҿ��������������֡�

������ÿ���˵õ����ٸ�ƻ������ʣ���ٸ�ƻ����*/
#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t > 0) {
    int m, n;
    cin >> m >> n;
    cout << (m-m%n)/n << ' ' << m%n << endl;
    t--;
  }
  return 0;
}
