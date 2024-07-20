#include <iostream>
using namespace std;
    int n, t, temp;
    double a;
    int light[1000005];
int main(void) {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a >> t;
        for (int j = 1;j <= t;j++) {
            double k = a * j;
            temp = k;
            light[temp]++;
        }
    }
    for (int i = 1;;i++) {
        if (light[i] % 2 == 1) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}