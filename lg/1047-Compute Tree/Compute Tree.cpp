#include <iostream>
using namespace std;
int main(void) {
    bool sure[10001] = {false};//原来数组开小了
    int l, m, start, end, rest = 0;
    
    cin >> l >> m;
    for (int i = 0;i < m;i++) {
        cin >> start >> end;
        for (int j = start;j <= end;j++) {
            sure[j] = true;
        }
    }
    
    for (int i = 0;i <= l;i++) {
        if (!sure[i]) rest++;
    }
    cout << rest << endl;
    return 0;
}