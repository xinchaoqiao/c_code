#include <iostream>
using namespace std;
#include <list>
class car {
public:
    int car_number;
    string car_cl;
    string car_type;
};

class Porting_Management {
public:
    Porting_Management() {
        ls = {};
    }
    void showmenu(void) {
    cout << "车辆管理系统" << endl;
    cout << "1.进入车辆" << endl;
    cout << "2.退出车辆" << endl;
    cout << "3.显示车辆" << endl;
    cout << "4.修改车辆信息" << endl;
    cout << "5.查找车辆" << endl;
    cout << "6.退出系统" << endl;
    }
    //1.车辆进入
    void enter(car& c) {
        ls.push_back(c);
    }
    //2.车辆退出
    void quit(int number) {
        if (ls.empty()) {
            cout << "为空" << endl;
            return;
        }
        for (auto ll = ls.begin();ll != ls.end();ll++) {
            if (ll->car_number == number) {
                cout << "车辆已经退出" << endl;
                ls.erase(ll);
                break;
            }
        }
    }
    //3.显示车辆
    void display() {
        if (ls.empty()) {
            cout << "为空" << endl;
            return;
        }
        for (auto ll = ls.begin();ll != ls.end();ll++) {
            cout << "车牌号：" << ll->car_number << " 车辆颜色：" << ll->car_cl << " 车辆类型: " << ll->car_type << endl;
        }
    }
    //4.修改车辆信息
    void modify() {
        if (ls.empty()) {
            cout << "为空" << endl;
            return;
        }
        int number;
        cout << "请输入想要修改的车牌号信息" << endl;
        cin >> number;
        bool sta = false;
        for (auto ll = ls.begin(); ll != ls.end();ll++) {
            if (ll->car_number == number) {
                sta = true;
            }
        }
        if (!sta) {
            cout << "没有找到车辆" << endl;
            return;
        }
        int select;
        cout << "请输入要修改的选项:" << endl;
        cout << "1.修改车辆车牌号" << endl;
        cout << "2.修改车辆颜色" << endl;
        cout << "3.修改车辆类型" << endl;
        cout << "4.全部修改" << endl;
        cin >> select;
        
        for (auto ll = ls.begin(); ll != ls.end();ll++) {
            if (ll->car_number == number && select == 1) {
                cout << "请输入修改后的车牌号" << endl;
                cin >> ll->car_number;
                cout << "修改成功" << endl;
                break;
            }
            else if (ll->car_number == number && select == 2) {
                cout << "请输入修改后的颜色" << endl;
                cin >> ll->car_cl;
                cout << "修改成功" << endl;
                break;
            }
            else if (ll->car_number == number && select == 3) {
                cout << "请输入修改后的车型" << endl;
                cin >> ll->car_type;
                cout << "修改成功" << endl;
                break;
            }
            else {
                cout << "请输入修改后的车牌号、颜色、车型" << endl;
                cin >> ll->car_number >> ll->car_cl >> ll->car_type;
                cout << "修改成功" << endl;
                break;
            }
        }
    }
    //5.查找车辆
    void search() {
        if (ls.empty()) {
            cout << "为空" << endl;
            return;
        }
        int number;
        cout << "请输入想要查找的车辆" << endl;
        cin >> number;
        for (auto ll = ls.begin();ll != ls.end();ll++) {
            if (ll->car_number == number) {
                cout << "找到了" << endl;
                cout << "车牌号：" << ll->car_number << " 车辆颜色： " << ll->car_cl << " 车辆类型: " << ll->car_type << endl;
                return;
            }
        }
        cout << "没有此车" << endl;
    }
public:
    
    list<car> ls;
};
// 主函数
int main(void)
{
    Porting_Management pm;
    int select;
    car c;
    while (true)
    {
        pm.showmenu();
        cout << "请输入你的选项" << endl;
        cin >> select;
        switch (select)
        {
        case 1: {//进入车辆
            cout << "请输入车辆的车牌号和颜色，车型" << endl;
            cin >> c.car_number >> c.car_cl >> c.car_type;
            pm.enter(c);
            break;
        }
        case 2://退出车辆
        {
            int number;
            cout << "请输入想要退出的车辆的车牌号" << endl;
            cin >> number;
            pm.quit(number);
            break;
        }
        case 3://显示所有车辆
            pm.display();
            break;
        case 4://修改车辆信息
        {
            pm.modify();
            break;
        }
        case 5://查找车辆
        {
            pm.search();
            break;
        }
        case 6://退出系统
            cout << "退出车辆管理系统成功" << endl;
            exit(-1);
            break;
        default://增强程序健壮性
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
    return 0;
}