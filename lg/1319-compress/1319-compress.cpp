#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    bool flag = false;
    vector<int> ans;
    int fill, count = 0;
    while (count != n * n) {
        cin >> fill;
        if (flag == false) {
            for (int i = 0;i < fill;i++) {
                ans.push_back(0);
                count++;
            }
        }
        else {
            for (int i = 0;i < fill;i++) {
                ans.push_back(1);
                count++;
            }
        }
        flag = !flag;
    }
    for (auto it = ans.begin(); it != ans.end();it++) {
        cout << *it;
        count--;
        if (count % 7 == 0)cout << endl;
    }
    return 0;
}