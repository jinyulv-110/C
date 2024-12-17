/*
小齐是一个农夫，他刚刚收到了一批大小为 
Si(1≤Si ≤100）的干草捆，一共有N（1≤N≤20）捆。他想要将这些捆公平地分配给他的三个谷仓。
经过一番思考，小齐决定将干草捆分配得让谷仓中最大的一份尽可能小。也就是说，如果 
B1、B2和 B3分别表示放在谷仓 1、2 和 3的所有干草捆的总大小（其中B1≥B2≥B3 ），那么小齐希望使 B1量小。
请帮助小齐确定在公平分配干草捆的情况下，B1的值是多少。
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
