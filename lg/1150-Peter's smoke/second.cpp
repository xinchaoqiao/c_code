#include <iostream>
using namespace std;
int main(void)
{
    int n, k;//初始烟数和换烟蒂条件
    int sum = 0,m = 0;//总烟数、总烟蒂数
    cin >> n >> k;
    while (n > 0) {
        sum += n;//加上烟数
        m += n;//加烟蒂数量
        n = m / k;//换烟
        m %= k;//得到剩余烟蒂数量
    }
    cout << sum << endl;
    return 0;
}