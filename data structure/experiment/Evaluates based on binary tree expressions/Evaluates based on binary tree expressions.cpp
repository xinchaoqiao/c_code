#include <iostream>
#include <stack>
using namespace std;
//树存储结构
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    //重载TreeNode
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

//初始化树
TreeNode* newnode(int data){
    TreeNode* root = new TreeNode;
    root->val = data;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}
//表达式转化为对应二叉树
TreeNode* transform(string exp_origin){ // exp为输入的表达式
    stack<char> OPTR;//运算符栈
    stack<TreeNode*> EXPT;//完整表达式栈

    for (int i = 0; i < exp_origin.size();i++) {
        //当exp[i] 的数值 在 0 -- 9之间时 创建结点，结点入栈
        if (exp_origin[i] >= 48 && exp_origin[i] <= 57) { // 【0，9】
            TreeNode* root = newnode(exp_origin[i]);
            EXPT.push(root);
        }
        else {
            if (OPTR.empty() || exp_origin[i] == '(') OPTR.push(exp_origin[i]);
            else {
                //运算符有+ - * / （ ）
                switch (exp_origin[i])
                {
                case '*': {
                    while (!OPTR.empty()) {
                        char top = OPTR.top();
                        if (top == '+' || top == '-' || top == '(') {
                            //这里代表优先级变大或栈顶元素为（，直接进栈退出和switch语句
                            break;
                        }
                        else {
                            //优先级变小或相等，创建二叉树，表达式前两个为root左右孩子
                            char top = OPTR.top();
                            TreeNode* root = newnode(top);
                            OPTR.pop();

                            //获得左右子树表达式
                            TreeNode* exp_first = EXPT.top();
                            EXPT.pop();
                            TreeNode* exp_second = EXPT.top();
                            EXPT.pop();

                            //链接左右子树
                            root->left = exp_second;
                            root->right = exp_first;

                            //表达式压回栈
                            EXPT.push(root);

                        }
                    }
                    OPTR.push('*');
                    break;
                }
                case '/': {
                    while (!OPTR.empty()) {
                        char top = OPTR.top();
                        if (top == '+' || top == '-' || top == '(') {
                            //这里代表优先级变大或栈顶元素为（，直接进栈退出和switch语句
                            break;
                        }
                        else {
                            //优先级变小或相等，创建二叉树，表达式前两个为root左右孩子
                            char top = OPTR.top();
                            TreeNode* root = newnode(top);
                            OPTR.pop();

                            //获得左右子树表达式
                            TreeNode* exp_first = EXPT.top();
                            EXPT.pop();
                            TreeNode* exp_second = EXPT.top();
                            EXPT.pop();

                            //链接左右子树
                            root->left = exp_second;
                            root->right = exp_first;

                            //表达式压回栈
                            EXPT.push(root);

                        }
                    }
                    OPTR.push('/');
                    break;
                }
                case '+': {
                    while (!OPTR.empty()) {
                        char top = OPTR.top();
                        if (top == '(') {
                            //这里代表优先级变大或栈顶元素为（，直接进栈退出和switch语句
                            break;
                        }
                        else {
                            //优先级变小或相等，创建二叉树，表达式前两个为root左右孩子
                            char top = OPTR.top();
                            TreeNode* root = newnode(top);
                            OPTR.pop();

                            //获得左右子树表达式
                            TreeNode* exp_first = EXPT.top();
                            EXPT.pop();
                            TreeNode* exp_second = EXPT.top();
                            EXPT.pop();

                            //链接左右子树
                            root->left = exp_second;
                            root->right = exp_first;

                            //表达式压回栈
                            EXPT.push(root);

                        }
                    }
                    OPTR.push('+');
                    break;
                }

                case '-': {
                    while (!OPTR.empty()) {
                        char top = OPTR.top();
                        if (top == '(') {
                            //这里代表优先级变大或栈顶元素为（，直接进栈退出和switch语句
                            break;
                        }
                        else {
                            //优先级变小或相等，创建二叉树，表达式前两个为root左右孩子
                            char top = OPTR.top();
                            TreeNode* root = newnode(top);
                            OPTR.pop();

                            //获得左右子树表达式
                            TreeNode* exp_first = EXPT.top();
                            EXPT.pop();
                            TreeNode* exp_second = EXPT.top();
                            EXPT.pop();

                            //链接左右子树
                            root->left = exp_second;
                            root->right = exp_first;

                            //表达式压回栈
                            EXPT.push(root);

                        }
                        
                    }
                    OPTR.push('-');
                    break;
                }

                case '(':
                    OPTR.push('(');
                    break;
                case ')': {
                    while (OPTR.top() != '('){
                        char top = OPTR.top();
                        TreeNode* root = newnode(top);
                        OPTR.pop();

                        //获得左右子树表达式
                        TreeNode* exp_first = EXPT.top();
                        EXPT.pop();
                        TreeNode* exp_second = EXPT.top();
                        EXPT.pop();

                        //链接左右子树
                        root->left = exp_second;
                        root->right = exp_first;

                        //表达式压回栈
                        EXPT.push(root);

                    }
                    OPTR.pop();//将）出栈
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
    while (!OPTR.empty()) {
        char top = OPTR.top();
        TreeNode* root = newnode(top);
        OPTR.pop();
        //获得左右子树表达式
        TreeNode* exp_first = EXPT.top();
        EXPT.pop();
        TreeNode* exp_second = EXPT.top();
        EXPT.pop();

        //链接左右子树
        root->left = exp_second;
        root->right = exp_first;

        //表达式压回栈
        EXPT.push(root);
    }
    return EXPT.top();
}

double ValueTree(TreeNode* root) {
    if (root->val >= 48 && root->val <= 57) return root->val - 48;

    double lval = ValueTree(root->left);
    double rval = ValueTree(root->right);

    switch (root->val)
    {
    case '+':
        return lval + rval;
        break;
    case '-':
        return lval - rval;
        break;
    case '*':
        return lval * rval;
        break;
    case '/':
        return lval / rval;
        break;
    default:
        break;
    }
    return -1;
}
int main(void)
{
    int select;
    
    
    while (true)
    {
        cout << "请输入你的选择" << endl;
        cout << "1.输入表达式" << endl;
        cout << "2.退出系统" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
        {
            string exp;
            cin >> exp;
            TreeNode* root = transform(exp);
            cout << endl;
            cout << "输入" << exp << endl;
            cout << "输出" << ValueTree(root) << endl;
            //标识符重置
            cin.clear();
            //清空缓冲区
            cin.sync();
        }
        break;
        case 2:
            cout << "退出成功" << endl;
            exit(-1);
        default:
            cout << "请重新输入" << endl;
            break;
        }
    }
    
    return 0;
}
//参考：
//https://blog.csdn.net/weixin_63267854/article/details/128083840?ops_request_misc=&request_id=&biz_id=102&utm_term=%E5%9F%BA%E4%BA%8E%E4%BA%8C%E5%8F%89%E6%A0%91%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-8-128083840.nonecase&spm=1018.2226.3001.4187
//缓冲区参考
//https://blog.csdn.net/u010632547/article/details/105687659