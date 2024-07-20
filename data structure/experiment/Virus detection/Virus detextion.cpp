#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


typedef struct {
    char ch[600]; //若是非空串，则按串长分配存储区，否则ch为NULL   
    int len; //串长度   
}HString;



int* GetNextVal(const char* s, int len)
{

    int* next = new int[len];
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < len)
    {
        if (j == 0 || s[i] == s[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}


int KMP(const char* s, int slen, const char* t, int tlen)
{

    int i, j;
    int* next = GetNextVal(t, tlen);

    i = 1;
    j = 1;
    while (i <= slen && j <= tlen)
    {
        if (j == 0 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if (j > tlen)
        return i - tlen;
    return 0;
}

void Virus_detection()
{
    int num, m, flag, i, j; char Vir[600];
    HString Virus, Person, temp;
    ifstream inFile("test.txt");
    ofstream outFile("result.txt");
    inFile >> num;//读取待检测的任务数
    while (num--) //依次检测每对病毒DNA和人的DNA是否匹配
    {
        inFile >> Virus.ch + 1;//读取病毒DNA序列
        inFile >> Person.ch + 1;//读取人的DNA序列
        strcpy(Vir, Virus.ch);
        Virus.len = strlen(Virus.ch) - 1;
        Person.len = strlen(Person.ch) - 1;
        flag = 0;//用来标识是否匹配，初始为0，匹配后为非0
        m = Virus.len;
        for (i = m + 1, j = 1; j <= m; j++) Virus.ch[i++] = Virus.ch[j];
        //因病毒为环状，故将病毒的长度扩大2倍
        //即可线性取到所有长度为Virus.len的字符串
        Virus.ch[2 * m + 1] = '\0'; //添加结束符号
        for (i = 0; i < m; i++)
        {
            for (j = 1; j <= m; j++) temp.ch[j] = Virus.ch[i + j];
            //取长为Virus.len的环形字符串
            //即Virus.ch[0]-- Virus.ch[Virus.len-1],
            //Virus.ch[1]-- Virus.ch[0], Virus.ch[2]-- Virus.ch[1]...
            temp.ch[m + 1] = '\0'; //添加结束符号
            temp.len = strlen(temp.ch) - 1;

            flag = KMP(Person.ch, Person.len, temp.ch, temp.len);  //模式匹配


            if (flag) break; //匹配即可退出循环
        }//for
        if (flag)
            outFile << Vir + 1 << " " << Person.ch + 1 << " " << "YES" << endl;
        else
            outFile << Vir + 1 << " " << Person.ch + 1 << " " << "NO" << endl;
    }//while
}


int main()
{
    Virus_detection();
    return 0;
}
