#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��ṹ��
struct Activity {
    int start, end;
};

// �ȽϺ�����������ʱ������
bool compare(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

// ̰���㷨ѡ��
void selectActivities(vector<Activity>& activities) {
    // ������ʱ������
    sort(activities.begin(), activities.end(), compare);

    // ѡ���һ���
    cout << "Selected Activities: " << endl;
    cout << "(" << activities[0].start << ", " << activities[0].end << ")" << endl;

    // �ӵڶ������ʼѡ��
    int lastEnd = activities[0].end;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            cout << "(" << activities[i].start << ", " << activities[i].end << ")" << endl;
            lastEnd = activities[i].end;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

    selectActivities(activities);

    return 0;
}
