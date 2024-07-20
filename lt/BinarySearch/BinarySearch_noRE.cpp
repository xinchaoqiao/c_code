#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//非递归
void BinarySearch(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int target;
    bool sta = false;
    cout << "请输入你想要查找的数" << endl;
    cin >> target;
    while (left <= right) {//这里一定要是 <= 号
        int mid = (left + right) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else if (arr[mid] == target) {
            cout << "找到了,index = " << mid << endl;
            cout << arr[mid];
            sta = true;
            return;
        }
    }
    if (!sta) {
        cout << "没有此数" << endl;
        return;
    }
}
int main(void) {
    vector<int> arr = { 22,23,44,11,29 };
    sort(arr.begin(), arr.end());
    BinarySearch(arr);
    return 0;
}