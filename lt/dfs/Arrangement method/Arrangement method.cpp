#include <iostream>
using namespace std;
const int N = 10;
//1 -- n 数的组合排列 从几开始第二个循环就从几开始循环


//用一个path数组来存储每次到底层的路径 
int path[N];

//用一个布尔数组来存储每次已经遍历的点,默认是false 
bool st[N];
//n表示总层数
int n;

void dfs(int deep) {
    //当到达层底，溯回并输出路径
    if (deep == n) {
        for (int i = 0; i < n;i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    else {
        //1 -- n 第一个数是几就从几开始循环
        for (int i = 1; i <= n; i++) {
            if (!st[i]) {
                
                path[deep] = i;
                //标记第i个数已经被使用
                st[i] = true;
                //进入下一层
                dfs(deep + 1);
                /*这里dfs不断向深层次递归，当到达最后一个dfs时候会输出全部路径的值，
                最后由第一个dfs将每个路径进行复原*/
                st[i] = false;
            }
        }
    }
}
int main(void)
{
    cin >> n;
    dfs(0);
    return 0;
}