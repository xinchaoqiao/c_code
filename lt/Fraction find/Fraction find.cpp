#include <iostream>
#include <vector>
using namespace std;
//分治法查找
pair<int, int> findMaxMin(vector<int> v, int left, int right) {
    if (left == right) return make_pair(v[left], v[right]);

    int mid = (left + right) / 2;
    pair<int, int> lpair = findMaxMin(v, left, mid);
    pair<int, int> rpair = findMaxMin(v, mid + 1, right);
    return make_pair(max(lpair.first, rpair.first), min(lpair.second, rpair.second));
}
int main(void) {
    vector<int> v;
    for (int i = 0; i < 5;i++) {
        v.push_back(i);
    }
    pair<int, int> rel = findMaxMin(v, 0, v.size() - 1);
    cout << "最大值:" << rel.first << " 最小值:" << rel.second << endl;
        return 0;
}