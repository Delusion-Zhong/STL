
#include <iostream>
#include <cstring>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;

// 链表
namespace LinkdList
{
    // 例如 存储 学生姓名,学号,成绩 单链表结构如下
    typedef struct student
    {
        string name;
        long num;
        int score;
    } ELemType;
    // 单链表的指针
    typedef struct Lnode
    {
        ELemType data;
        struct Lnode *next;
    } Lnode, *LinkList;
    // 单链表的初始化 （带头节点的单链表）
    Status LinkdList::LinkList_L(LinkList &L)
    {
        // 1.生成新的结点作为头节点，用头指针L 指向头节点
        // 2. 将头节点的指针域置为空
        L = new Lnode; // 使用动态分配了一块Lnode大小的空内存
        L->next = nullptr;
        return OK;
    }
    // 判断连链表是否为空
    Status LinkdList::ListEmpty(LinkList L)
    {

        if (L->next)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    // 单链表的销毁，
    Status LinkdList::DestroyLIst(LinkList &L)
    {
        LinkList p;
        while (L)
        {
            p = L;       // 先记录 L头节点的位置
            L = L->next; // 获取下一个的指针域
            delete p;    // 然后释放原来位置
        }
        return OK;
    }
    // 清空单链表
    // 思路：依次释放所有节点，将头节点指针域设置为空
    Status LinkdList::ReviseList(LinkList &L)
    {
        LinkList P, Q;
        P = L->next;
        while (P) // 结束条件 P==null
        {

            Q = P->next;
            delete P;
            P = Q;
            Q = P->next;
        }
        L->next = nullptr;
        return OK;
    }
    // 求单链表的表长
    Status LinkdList::SizeList(LinkList L)
    {
        // 先有一个指针，当指针下移 则++ （同时进行判断是否为空）
        LinkList p;
        int index = 0; // 设置一个计数器
        p = L->next;   // 先获取首个节点 （因为这是一个带有头节点的单链表（不计入链表的长度））

        while (p)
        {
            /*
            进行判断p！=null  不是null 时进入循环,计数器加一，p指向下一个节点依次循环
        */
            index++;
            p = p->next;
        }
        return index;
    }

}

int main()
{
    cin.get();
    return 0;
}