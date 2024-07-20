#include <iostream>
#include <fstream>
#include <string>
#define maxsize 100
using namespace std;

struct Person {
	char sex;
	char name[10];
};
struct squeue
{
	Person* arr;
	int rear;
	int front;
};
void initsqueue(squeue& sq) {
	sq.arr = new Person[maxsize];
	sq.rear = sq.front = 0;
}
bool sq_full(squeue& sq) {
	if ((sq.rear + 1) % maxsize == sq.front) return true;
	return false;
}

bool sq_empty(squeue& sq) {
	if (sq.rear == sq.front) return true;
	return false;
}
//入队
void sq_ensqueue(squeue& sq,Person& val) {
	if (sq_full(sq)) return;
	sq.arr[sq.rear] = val;
	sq.rear = (sq.rear + 1) % maxsize;
}
//出队
void sq_desqueue(squeue& sq,Person& val) {
	if (sq_empty(sq)) return;
	val = sq.arr[sq.front];
	sq.front = (sq.front + 1) % maxsize;
}
//队头元素
Person sq_Gethead(squeue& sq) {
		return sq.arr[sq.front];
}
void DanceSolve(Person dancer[], int num) {
	squeue Fdancer, Mdancer;
	initsqueue(Fdancer);
	initsqueue(Mdancer);
	Person p;
	for (int i = 0; i < num; i++) {
		p = dancer[i];
		if (p.sex == 'F') sq_ensqueue(Fdancer, p);
		else sq_ensqueue(Mdancer, p);
	}
	cout << "Part :" << endl;
	while (!sq_empty(Fdancer) && !sq_empty(Mdancer)) {
		sq_desqueue(Fdancer, p);
		cout << p.name << " ";
		sq_desqueue(Mdancer, p);
		cout << p.name << endl;
	}
	if (!sq_empty(Fdancer)) {
		p = sq_Gethead(Fdancer);
		cout << "next woman first part is :" << p.name << endl;
	}
	else if (!sq_empty(Mdancer)) {
		p = sq_Gethead(Mdancer);
		cout << "next man first part is :" << p.name << endl;
	}
}
void func(void)
{
	Person dancers[maxsize] = { '\0' };
	fstream file;
	file.open("Dancers.txt");
	if (!file) {
		cout << "文件打开失败" << endl;
		return;
	}
	int i = 0;
	while (!file.eof()) {
		file >> dancers[i].name >> dancers[i].sex;
		i++;
	}
	DanceSolve(dancers, i + 1);
}
int main(void) {
	func();
	
	return 0;
}