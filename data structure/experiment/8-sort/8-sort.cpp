#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
class Student {
public:
    Student() {
        s_name = " ";
        s_sorces = 0;
    }
    string s_name;
    double s_sorces;
};
bool _sort(const Student& s1, const Student& s2) {
    return s1.s_sorces > s2.s_sorces;
}
int main(void) {
    int n;
    cin >> n;
    vector<Student> sarr;
    Student s1; 
    
    for (int i = 0; i < n;i++) {
        cin >> s1.s_name >> s1.s_sorces;
        sarr.push_back(s1);
    }
    sort(sarr.begin(), sarr.end(), _sort);
    for (int i = 0;i < n;i++) {
        cout << i + 1 << sarr[i].s_name << " " << sarr[i].s_sorces << endl;
    }
    return 0;
}