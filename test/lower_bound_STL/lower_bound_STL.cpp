#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int x) {
    cout << x << " ";
}
int main(void) {
    vector<int> arr = { 11,5 ,2 ,99, 55, 66,46 };
    sort(arr.begin(), arr.end());
    for_each(arr.begin(), arr.end(), print);
    vector<int>::iterator pos = lower_bound(arr.begin(), arr.end(), 45);//这里显示比45大的第一个数字 55 // 需要排序
    cout << endl;
    cout << *pos << endl;
    return 0;
}