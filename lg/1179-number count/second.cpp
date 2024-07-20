#include <iostream>
using namespace std;
//分离位
int main(void) {
    int left, right, count = 0;
    cin >> left >> right;
    for (int i = left; i <= right;i++) {
        int x = i;
        while (x > 0) {
            if (x % 10 == 2)count++;
            x /= 10;
        }
    }
    cout << count << endl;
    return 0;
}

/*
    %用处
1.%100 等于取后两位  有几个零等于取多少位；
2.%可以用于防止数组越界 最好%数组的长度（size)
*/