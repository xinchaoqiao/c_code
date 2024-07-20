#include <iostream>
using namespace std;
int main(void) {
    int n, k;
    cin >> n >> k;
    //总数除以换的条件 = 可以换的烟蒂
    //可以换的 + 原来的烟蒂 = 总共的烟蒂

    // int rel = n + (n + n / k) / k;
    int rel = n + (n - 1) / (k - 1);
    cout << rel << endl;
    return 0;
}
//https://blog.csdn.net/qq_46105170/article/details/103760293