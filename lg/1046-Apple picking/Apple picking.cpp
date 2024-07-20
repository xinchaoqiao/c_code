#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    vector<int> hight;
    int temp;
    for (int i = 0; i < 10;i++) {
        cin >> temp;
        hight.push_back(temp);
    }
    int touch, number = 0;
    cin >> touch;
    for (int i = 0; i < hight.size();i++) {
        if (hight[i] <= touch + 30) number++;
    }
    cout << number << endl;
    return 0;
}