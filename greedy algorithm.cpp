#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 活动结构体
struct Activity {
    int start, end;
};

// 比较函数，按结束时间排序
bool compare(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

// 贪心算法选择活动
void selectActivities(vector<Activity>& activities) {
    // 按结束时间排序
    sort(activities.begin(), activities.end(), compare);

    // 选择第一个活动
    cout << "Selected Activities: " << endl;
    cout << "(" << activities[0].start << ", " << activities[0].end << ")" << endl;

    // 从第二个活动开始选择
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
