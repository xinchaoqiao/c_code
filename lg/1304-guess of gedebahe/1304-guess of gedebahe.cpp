#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool isprime(int N) {
    for (int i = 2;i <= sqrt(N);i++) {
        if (N % i == 0) return false;
    }
    return true;
}
void print(int& x) {
    cout << x << endl;
}
int main(void) {
    int N;
    cin >> N;
    for (int i = 4;i <= N;i++) {//哥德巴赫数 -- i
        for (int j = 2;j <= i / 2;j++) {
            if (i % 2 != 0) break;
            if (isprime(j) && isprime(i - j)) {
                cout << i << "=" << j << "+" << i - j << endl;
                break;
            }
        }
    }
    return 0;
}