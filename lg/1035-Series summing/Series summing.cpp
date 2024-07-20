#include <iostream>
using namespace std;
int main(void) {
    int k, n = 1;
    double sn = 0;
    cin >> k;

    while (sn < k)
    {
        sn += 1.0 / n;
        n++;
    }
    //n -1次迭代没有超过sn  第n次迭代超过了sn值
    cout << n - 1 << endl;
    return 0;
}