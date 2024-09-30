
#include <iostream>
#include <cstring>
#include "../include/List.h"

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
namespace List_demo

{
    // 例如 存储 学生姓名,学号,成绩 单链表结构如下
    typedef struct student
    {
        string name;
        long num;
        int score;
    } ElemType;

    // 单链表的指针
    typedef struct Lnode
    {
        ElemType data;
        struct Lnode *next;
    } Lnode, *LinkList;
    // 双向链表的指针
    typedef struct DuLnode
    {
        ElemType data;
        struct DuLnode *next, *prior;
    } DuLnode, *DuLinkList;
    namespace LindList // 链表
    {

        // 运输符 重载
        bool operator!=(const ElemType &th, const ElemType &data_b)
        {
            return th.name != data_b.name || th.num != data_b.num || th.score != data_b.score;
        }

        bool operator==(const ElemType &th, const ElemType &data_b)
        {
            return th.name == data_b.name && th.num == data_b.num && th.score == data_b.score;
        }
        istream &operator>>(istream &in, ElemType &data)
        {
            cin >> data.name >> data.num >> data.score; // 读取数据
            return in;
        }

        // 单链表的初始化 （带头节点的单链表）
        Status LinkList_L(LinkList &L)
        {
            // 1.生成新的结点作为头节点，用头指针L 指向头节点
            // 2. 将头节点的指针域置为空
            L = new Lnode; // 使用动态分配了一块Lnode大小的空内存
            L->next = nullptr;
            return OK;
        }

        // 判断连链表是否为空
        Status ListEmpty(LinkList L)
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
        Status DestroyLIst(LinkList &L)
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
        Status ReviseList(LinkList &L)
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
        Status SizeList(LinkList L)
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
        /********************************************************************************************************* */
        // 查找元素(索引查找)
        Status FindList(LinkList L, int index, ElemType &e)
        {
            LinkList p;
            int j = 1;
            p = L->next;           // 首元节点
            while (p && j < index) // 先判断 p 是否为空 并且 满足 j< index
            {                      // 下移计数
                p = p->next;
                ++j;
            }
            if (!p || j > index) // p不为空但是 index的索引大于链表的长度
                return ERROR;
            e = p->data; // 找到了返回数据
            return OK;
        }

        // 按值查找（返回的是p指向linklist节点数据域)
        LinkList Find_data_List(LinkList L, ElemType datp)
        {
            LinkList p;
            p = L->next;
            while (p && p->data != datp) // p->data 相当于 this，而 datp 是作为参数传入的对象
                p = p->next;
            return p;
        }

        // 按值查找（返回的位置的下标)
        Status Find_index_List(LinkList L, ElemType datp)
        {
            LinkList p;
            p = L->next;
            int j = 1;
            while (p && p->data != datp)
            { // 存在两种情况  1 或 0
                p = p->next;
                j++;
            }
            if (p)
                return j;
            else
                return ERROR;
        }

        // 插入
        Status Insert_List(LinkList &L, ElemType datp, int index)
        {
            LinkList p;
            int j = 0;
            while (p && j < index - 1)
            {
                p = p->next;
                ++j;
            }
            if (!p || j > index - 1) // 判断位置非法
                return ERROR;

            // null-------》1（指针p）------(插入datp （指针S）)------》2----------》3
            LinkList s = new Lnode; // new 一块新的地址
            s->data = datp;         // 将新的数据域赋给 s->data
            s->next = p->next;      // 将现在   s.next=p.next 原来指向2的指针赋值给datp（的指针s）
            p->next = s;            // 在将s的地址赋值给1.next （p.next）
            return OK;
        }

        // 删除
        Status Delete_List(LinkList &L, int index) // 1  2  3  4   5
        {
            LinkList p, q; // 创建变量，存储前驱和后继
            int j = 0;
            p = L;
            while (p->next && j < index - 1) // 删除节点的前驱
            {                                // 判断p->next && j < index - 1  两个条件必须都要为真
                p = p->next;
                ++j;
            }
            if (!(p->next) || j > index - 1) // 判断 下一节点或者 j的下边是大于index的下标 则抛出异常
                return ERROR;
            q = p->next;             // 删除节点
            p->next = q->next->next; // 将上一节点的指针 指向  下一节点的下一个节点
            delete q;
            return OK;
        }

        // 头插法
        Status Head_Insert_List(LinkList &L, int index)
        {
            LinkList Q;        // 建立链表
            Q->next = nullptr; // 头节点的next为空
            for (int i = index; i > 0; --i)
            {
                LinkList p = new Lnode;
                cin >> p->data; // 当在这里在data中输入信息的时候，用到的（>> 运算符重载 ）
                p->next = Q->next;
                Q->next = p;
            }
            L = Q; // 将头节点返回给Q
            return OK;
        }

        // 尾差法     1    2       3      4         5   --->null
        Status Tail_Insert_List(LinkList &L, int index)
        {
            // 检查索引是否有效
            if (index < 0)
                return ERROR;

            LinkList K = L; // 尾指针，初始化为链表的头节点

            // 如果链表为空，初始化链表并输入第一个节点的数据
            if (!L)
            {
                L = new Lnode;     // 创建新节点
                cin >> L->data;    // 输入节点数据
                L->next = nullptr; // 新节点的下一个指针设为 nullptr
                return OK;         // 返回成功状态
            }

            // 找到链表的尾节点
            while (K->next)
            {
                K = K->next; // 移动指针到下一个节点
            }

            // 插入新节点
            for (int i = 0; i < index; i++)
            {
                LinkList Q = new Lnode; // 创建新节点
                cin >> Q->data;         // 输入新节点的数据
                Q->next = nullptr;      // 新节点的下一个指针设为 nullptr
                K->next = Q;            // 将尾节点的下一个指针指向新节点
                K = Q;                  // 更新尾指针 K 为新节点
            }

            return OK; // 返回成功状态
        }

    } // namespace 单链表

    namespace Circulate_List //  循环链表
    {
        // 带有尾指针的循环链表的合并
        LinkList &Connect(LinkList &Ta, LinkList &Tb) // 两个尾节点
        {
            LinkList p;                // 存放 Ta的头节点
            p = Ta->next;              // 获取Ta的头节点
            Ta->next = Tb->next->next; // 将Tb的头节点的地址赋值为Ta尾节点的下一个节点
            delete Tb->next;           // 释放Tb的空头结点（带有空头节点的链表）
            Tb->next = p;              // 将合并的尾节点 下一个节点赋为头节点 （尾头相连）
            return Tb;                 // 返回合并链表的尾节点
        }

    }

    namespace DulindList // 双向链表
    {
        // 查找索引元素
        DuLinkList FindList(DuLinkList L, int index)
        {
            DuLinkList p;

            p = L->next;
            int j = 1;             // 首元节点
            while (p && j < index) // 先判断 p 是否为空 并且 满足 j< index
            {                      // 下移计数
                p = p->next;
                ++j;
            }
            if (!p || j > index) // p不为空但是 index的索引大于链表的长度
                return ERROR;

            return p;
        }
        // 插入元素

        Status Insert_List(DuLinkList &L, int index, ElemType e)
        {
            DuLinkList p;                  // 定义当前节点
            if (!(p = FindList(L, index))) // 查找到当前索引链表的位置
                return ERROR;

            DuLinkList s;        // 插入的新元素节点
            s->data = e;         // 将数据传入 双链表节点 s中
            s->prior = p->prior; // 当前节点的上一个节点
            s = p->prior->next;  // 将上一个节点的下一个节点设置为 当前节点 S
            s->next = p;         // 将p 设置为 s的next
            p->prior = s;        // 将s设置为p的prior
            return OK;
        }
        // 根索引删除元素
        Status Delete_List(DuLinkList &L, int index, ElemType &e)
        {
            DuLinkList p;                  // 查找到index节点
            if (!(p = FindList(L, index))) // 查找到当前索引链表的位置
                return ERROR;
            e = p->data;
            // 假设现在有链表  a<====>b<====>c  删除b
            //   b             c
            //   |            |
            p->prior->next = p->next;  // 将c的地址 给到a的next
            p->next->prior = p->prior; // 将a的节点给到c的piror
            delete p;
        }
    }

}

int main()
{

    cin.get();
    return 0;
}