#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    int sub1, sub3, k;
    double sub2;
    cin >> k;
    int count = 0;
    for (int i = 10000;i <= 30000;i++) {
        sub1 = i / 100;
        sub2 = i / 10 % 1000;
        sub3 = i % 1000;
        if ((sub1 % k == 0) && ((int)sub2 % k == 0) && ((int)sub3 % k == 0)) {
            cout << i << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "No" << endl;
    }
    return 0;
}