/*
С����һ��ũ�����ո��յ���һ����СΪ 
Si(1��Si ��100���ĸɲ�����һ����N��1��N��20����������Ҫ����Щ����ƽ�ط�������������Ȳ֡�
����һ��˼����С��������ɲ���������ùȲ�������һ�ݾ�����С��Ҳ����˵����� 
B1��B2�� B3�ֱ��ʾ���ڹȲ� 1��2 �� 3�����иɲ������ܴ�С������B1��B2��B3 ������ôС��ϣ��ʹ B1��С��
�����С��ȷ���ڹ�ƽ����ɲ���������£�B1��ֵ�Ƕ��١�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int minMaxLoad(int N, vector<int>& haystacks);
bool canDivide(vector<int>& haystacks, int maxLoad);
bool backtrack(vector<int>& haystacks, vector<int>& bins, int index, int maxLoad);


int minMaxLoad(int N, vector<int>& haystacks) {
    int left = *max_element(haystacks.begin(), haystacks.end()); 
    int right = accumulate(haystacks.begin(), haystacks.end(), 0); 

    while (left < right) {
        int mid = (left + right) / 2;
        if (canDivide(haystacks, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool canDivide(vector<int>& haystacks, int maxLoad) {
    vector<int> bins(3, 0);
    sort(haystacks.begin(), haystacks.end(), greater<int>()); 
    return backtrack(haystacks, bins, 0, maxLoad);
}

bool backtrack(vector<int>& haystacks, vector<int>& bins, int index, int maxLoad) {
    if (index == haystacks.size()) {
        return true;
    }
    for (int i = 0; i < 3; ++i) {
        if (bins[i] + haystacks[index] <= maxLoad) {
            bins[i] += haystacks[index];
            if (backtrack(haystacks, bins, index + 1, maxLoad)) {
                return true;
            }
            bins[i] -= haystacks[index];
        }
        if (bins[i] == 0) {
            break;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> haystacks(N);
    for (int i = 0; i < N; ++i) {
        cin >> haystacks[i];
    }
    cout << minMaxLoad(N, haystacks) << endl;
    return 0;
}
