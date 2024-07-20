#include<iostream>
using namespace std;
int main(void) {
    int school_time[7], mom_time[7];
    for (int i = 0;i < 7;i++) {
        cin >> school_time[i] >> mom_time[i];
    }
    int max_day = 0, unhappy = 0, max_unhappy = 0;
    for (int i = 0;i < 7;i++) {
        int total_time = school_time[i] + mom_time[i];
        if (total_time > 8) {
            unhappy = total_time - 8;
            if (unhappy > max_unhappy) {
                max_unhappy = unhappy;
                max_day = i + 1;
            }
        }
    }
    if (max_unhappy == 0) {
        cout << 0 << endl;
    }
    else cout << max_day << endl;
    return 0;
}