#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//自带

void print(int x) {
    cout << x << " ";
}
int main(void)
{
    vector<int> arr = { 22,55,33,66,44,11 };
    sort(arr.begin(), arr.end());
    if (binary_search(arr.begin(), arr.end(), 22)) {
        cout << "找到了" << endl;
    }
    else cout << "没有找到该数" << endl;
    return 0;
}