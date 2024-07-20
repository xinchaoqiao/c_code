#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int a, b, n, ans = 0;
    cin >> n;
    cin >> a;
    bool flag = false;
    for (int i = 1; i < n;i++) {
        cin >> b;
        if (b < a) flag = true;
        if (b > a && flag == true) {
            ans++;
            flag = false;
        }
        a = b;
    }
    cout << ans << endl;
    return 0;
}