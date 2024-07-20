#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int x) {
    cout << x << " ";
}
int main(void) {
    vector<int> arr = { 11 ,22 ,33, 44, 55 ,66 };
    sort(arr.begin(), arr.end());
    auto pos = upper_bound(arr.begin(), arr.end(), 21); // 返回比这个数大的前一个位置
    arr.insert(pos, 43);
    for_each(arr.begin(), arr.end(), print);
    cout << endl;
    cout << *pos << endl;
    return 0;
}