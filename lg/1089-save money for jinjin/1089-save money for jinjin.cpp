#include <iostream>
using namespace std;
int main(void) {
    int cost[12];
    int mom_save = 0, money = 0, flag = 1;
    for (int i = 0; i < 12;i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < 12;i++) {
        money += 300;
        money -= cost[i];//剩余的钱
        if (money < 0) {
            flag = 0;
            cout << -(i + 1) << endl;
            return 0;
        }
        mom_save += money / 100;//存在妈妈手里的钱数
        money %= 100;//拿月底幸存的钱
    }
    money += mom_save * 120;
    cout << money << endl;
    return 0;
}