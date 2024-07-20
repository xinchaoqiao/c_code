#include <iostream>
#include <string>
using namespace std;
 
// 定义链表节点结构体
struct ListNode {
	long long ISBN;          // ISBN值
	int Price;		   // 价格
	string Book_Name;  // 书名
	ListNode* next;
	ListNode() : ISBN(0), Price(0), Book_Name("无"), next(NULL) {};
};
//菜单
void showMenu(void) {
	cout << "****************************" << endl;
	cout << "	1.显示全部书籍	" << endl;
	cout << "	2.查找	" << endl;
	cout << "	3.插入	" << endl;
	cout << "	4.删除	" << endl;
	cout << "	5.修改	" << endl;
	cout << "	6.价格升序	" << endl;
	cout << "	7.图书数量	" << endl;
	cout << "	8.退出系统	" << endl;
	cout << "****************************" << endl;
}
//自带书籍
ListNode* Book(void) {
	ListNode* head = NULL;
	ListNode* cur = NULL;
	cout << "请输入想要添加几本书" << endl;
	int n;
	cin >> n;
	cout << "请依次输入书籍的ISBN、书名、价格" << endl;
	for (int i = 0; i < n; i++) {
		if (!head) {
			head = new ListNode;
			cout << "请输入第" << i + 1 << "本图书" << endl;
			cin >> head->ISBN >> head->Book_Name >> head->Price;
			cur = head;
		}
		else
		{
			cur->next = new ListNode;
			cout << "请输入第" << i + 1 << "本图书" << endl;
			cin >> cur->next->ISBN >> cur->next->Book_Name >> cur->next->Price;
			cur = cur->next;
		}
	}
	return head;
}
//1显示书籍
void show_Book(ListNode* head) {
	const char tab = '\t';
	ListNode* cur = head;
	while (cur) {
		cout << "ISBN: " << cur->ISBN << tab << "书名：" << cur->Book_Name << tab << "价格："
			<< cur->Price << endl;
		cur = cur->next;
	}
}
//2查找书籍
void find_Book(ListNode* head) {
	if (head == nullptr) {
		cout << "没有书籍_Find" << endl;
		return;
	}
	long long Find;
	bool sta = false;
	ListNode* cur = head;
	cout << "请输入想要查找书籍的ISBN码" << endl;
	cin >> Find;
	while (cur) {
		if (cur->ISBN == Find) {
			sta = true;
			cout << "找到了" << endl;
			cout << "ISBN:" << cur->ISBN << "   Name:" << cur->Book_Name << "   价格："
				<< cur->Price << endl;
			return;
		}
		//if (!cur->next) return;
		cur = cur->next;
	}
	if (!sta) {
		cout << "没有此书" << endl;
	}
}
//3插入书籍
ListNode* inSert(ListNode* head) {
	ListNode* cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	int k;
	cout << "请输入要插入书的数量" << endl;
	cin >> k;
	if (k == 0) {
		cout << "输入了无效值" << endl;
		return head;
	}
	int i = 0;
	cout << "请依次输入书籍的ISBN、名称、价格" << endl;
	while (k-- > 0) {
		cur->next = new ListNode;
		cur = cur->next;
		cout << "第" << ++i << "本书" << endl;
		cin >> cur->ISBN >> cur->Book_Name >> cur->Price;
	}
	return head;
}
//4删除书籍
ListNode* delete_Book(ListNode* head) {
	ListNode* cur = head;
	cout << "请输入要删除的书籍ISBN值" << endl;
	long long Find;
	cin >> Find;
	//对第一个节点进行判断
	if (cur->ISBN == Find) {
		if (cur->next) {
			head = head->next;
			delete cur;
			cout << "删除成功" << endl;
			return head;
		}
		else
		{
			delete cur;
			cout << "书籍为空" << endl;
			return head;
		}
	}
	//对后续节点进行判断
	bool sta = false;
	while (cur->next) {//这里cur->next指向head->next
		if (cur->next->ISBN == Find) {
			ListNode* temp = cur->next;
			if (cur->next->next) {
				cur->next = cur->next->next;
				delete temp;
				cout << "删除成功" << endl;
				break;
			}
			else
			{
				cur->next = NULL;
				delete temp;
				if (!cur) {
					cout << "没有书籍" << endl;
					return head;
				}
				cout << "删除成功" << endl;//这里刚开始漏了
				break;
			}
		}
		cur = cur->next;
	}
	return head;
}
//5修改书籍
ListNode* modify_Book(ListNode* head) {
	ListNode* cur = head;
	cout << "请输入要修改书籍的ISBN码" << endl;
	long long Find;
	bool sta = false;
	cin >> Find;
	while (cur) {
		if (cur->ISBN == Find) {
			sta = true;
			string name;
			int price;
			cout << "请依次输入修改后的书名、价格" << endl;
			cin >> name >> price;
			cur->Book_Name = name;
			cur->Price = price;
			break;
		}
	}
	if (!sta) {
		cout << "没有此书籍" << endl;
	}
	return head;
}
//6价格升序从小到大
ListNode* book_Sort(ListNode* head) {
	if (!head) return nullptr;
	ListNode* dummyNode = new ListNode;
	dummyNode->next = head;
	int n = 0; // 统计链表长度
	ListNode* p = head;
	while (p) {
		n++;
		p = p->next;
	}
	while (n--) { // 外层循环n次
		// 初始化pre和p          
		ListNode* pre = dummyNode;
		ListNode* p = dummyNode->next;
		bool finished = true;
		while (p && p->next) { // 内层循环
			ListNode* node1 = p;
			ListNode* node2 = p->next;
			bool swap_flag = false; // 标记是否交换
			if (node1->Price > node2->Price) {
				swap_flag = true;
				finished = false;
				pre->next = node2;
				
				ListNode* tmp = node2->next; // 记录下一个节点，防止丢失
				node2->next = node1;
				node1->next = tmp;
			}
			pre = (swap_flag) ? node2 : node1;
			p = (swap_flag) ? node1 : node2;
		}
		if (finished) break;
	}
	return dummyNode->next;
}
//7图书数量
// void book_Count(ListNode* head) {
// 	ListNode* cur = head;
// 	int count = 0;
// 	while (cur) {
// 		count++;
// 		cur = cur->next;
// 		if (!cur->next) break;
// 	}
// 	cout << "有" << count << "本图书" << endl;
// }
//图书数量改版
int book_Count(ListNode* head) {
	if (!head) return 0;
	return book_Count(head->next) + 1;
}
//功能函数
void func() {
	static ListNode* l1 = Book();
	int Select;
	while (1) {
		showMenu();
		cout << "请输入你的选项" << endl;
		cin >> Select;
		switch (Select)
		{
		case 1://显示全部书籍
			show_Book(l1);
			break;
		case 2://查找书籍
			find_Book(l1);
			break;
		case 3://插入书籍
			l1 = inSert(l1);
			break;
		case 4://删除书籍
			l1 = delete_Book(l1);
			break;
		case 5://修改书籍
			l1 = modify_Book(l1);
			break;
		case 6://ISBN排序
			l1 = book_Sort(l1);
			break;
		case 7://统计书籍
			//book_Count(l1);
			cout << "共有" << book_Count(l1) << "本图书" << endl;
			break;
		case 8:
			exit(-1);
		default:
			cout << "输入了错误的选项，请重新输入" << endl;
			break;
		}
	}
}
int main(void)
{
	func();
	return 0;
}