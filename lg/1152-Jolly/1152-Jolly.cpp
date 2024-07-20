#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n,a[1001];
    bool b[1000];
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 2;i <= n;i++) {
        b[abs(a[i] - a[i - 1]) % n] = true;//防止数组越界 1000一个循环（差值会大于1000）
    }
    for (int i = 1; i < n;i++) {
        if (!b[i]) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}