#include <bits/stdc++.h>
using namespace std;
int main(void) {
int left, right;
    cin >> left >> right;
    int i = left, count = 0;
    for (int i = left;i <= right;i++) {
        if (i % 10 == 2)count++;
        if (i / 10 % 10 == 2) count++;
        if (i / 100 % 10 == 2) count++;
        if (i / 1000 % 10 == 2) count++;
        if (i / 10000 % 10 == 2) count++;
        if (i / 100000 % 10 == 2) count++;
    }
    cout << count << endl;
    return 0;
}