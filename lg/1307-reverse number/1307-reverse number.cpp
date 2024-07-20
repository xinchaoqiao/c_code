#include <iostream>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    int temp = N, rev = 0;
    if (N == 0) {
        cout << 0 << endl;
    }
    else if (N > 0) {
        while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;
        rev = rev * 10 + digit;
        }
    }
    else{
        temp = abs(N);
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            rev = rev * 10 + digit;
        }
    }
    if (N > 0)
        cout << rev << endl;
    else if(N < 0){
        cout << -rev << endl;
    }
    return 0;
}