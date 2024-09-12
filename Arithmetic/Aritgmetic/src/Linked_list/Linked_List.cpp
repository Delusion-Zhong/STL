#include <iostream>
#include <string>
using namespace std;
/*
    单向链表
*/

/* 链表节点结构体 */
typedef struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
} ListNode;
// 1.查找节点
int Find(ListNode *head, int target)
// 链表头指针 head  ,查找其中值为 target 的节点
{
    int index = 0;          // 第几个值的记录
    while (head != nullptr) // 1.先要判断head节点不为空指针
    {
        if (head->val == target) // 当前head 指向的节点值要为target的值
            return index;        // 返回当前记录的下标
        head = head->next;       // 当一轮判断后没有遇到，修改head指向下一个节点依次循环
        index++;                 // 每次index记录
    }
    return -1; // 最终循环完毕后没有遇到就返回 -1；
}
//  2.删除节点
void Remove(ListNode *&head, int const val) // 现在需要删除传入进来的index 节点的值
{
    // 假设链表如下：N（当前节点）-->O（被指向）-->P(最后被n指向)-->Q-->nullptr
    // //n->next= n->next->next ;   简单粗暴的方式
    // if (n->next == nullptr)
    //     return;
    // ListNode *O = n->next; //  先获取当前元素指向的 --->>>地址
    // ListNode *P = O->next; //  然后获取到被（O）指向节点的地址
    // n->next = P;           // 然后再让 当前节点指向 被(O)指向 节点的地址
    // delete P;              // 最后  释放 记录O节点地址的空间
    // 检查头节点是否为要删除的节点
    ListNode *temp;
    while (head != nullptr && head->val == val)
    {
        temp = head;
        head = head->next; // 更新头节点
        delete temp;       // 释放旧的头节点

        /*
        temp = n;：临时保存当前的头节点 n，以便在后面删除它。
        n = n->next;：将 n 指针移到下一个节点，更新头节点。
        delete temp;：删除旧的头节点，释放其内存。
        */
    }

    // 如果链表为空，直接返回
    if (head == nullptr)
        return; // 如果在删除头节点之后，链表已经变空（即 head 变成了 nullptr），那么直接返回，避免后续操作。

    ListNode *pre = head;

    // 遍历链表并删除匹配的节点
    while (pre->next != nullptr)
    {
        if (pre->next->val == val)
        {
            temp = pre->next;
            pre->next = pre->next->next; // 跳过要删除的节点
            delete temp;                 // 释放删除的节点
        }
        else
        {
            pre = pre->next; // 继续遍历
        }
    }
}
// 3.修改节点 输入链表的头节点，第几个节点，将要修改的值
void Revise(ListNode *&head, int index, int val)
{

    if (head == nullptr)
    {
        cout << "可能存在空链表" << endl;
        return;
    }
    if (index - 1 < 0)
    {
        cout << "出现无效索引" << endl;
        return;
    }

    // 当头节点为 0的时候，直接修改值
    if (index - 1 == 0)
    {
        head->val = val;
    }

    ListNode *per = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (per == nullptr)
            return;
        per = per->next;
    }

    if (per != NULL)
    {
        per->val = val;
    }
    else
    {
        cout << "遇到index的索引时为空！！" << endl;
    }
}

// 4.访问节点
ListNode *Visit(ListNode *head, int index) // a-->b-->c-->d--->e--a->nullptr
// 链表头指针 head  ,访问索引的index
// 函数返回类型是 ListNode*，即返回一个指向链表中某个节点的指针。
{
    for (int i = 0; i < index - 1; i++)
    {
        if (head == nullptr) // 空指针排查  当 head 为 nullptr 时，表示链表已经结束，无法继续向后遍历。
            return nullptr;
        head = head->next; // 指针移动到链表中的下一个节点
    }
    return head;

    /*   4.访问节点
    假设链表为 a -> b -> c -> d -> e -> nullptr，表示链表节点的值为：
    head = a
    head->next = b
    b->next = c
    c->next = d
    d->next = e
    e->next = nullptr
    调用 Visit(head, 2)：

    head 指向 a。
    第一次循环后，head = head->next，现在 head 指向 b。
    第二次循环后，head = head->next，现在 head 指向 c。
    退出循环，返回指向节点 c 的指针。

*/
}

// 5. 插入节点
void insert(ListNode *&head, int index, int val) // 链表,插入的位置，插入的值
{
    // void insert(ListNode *&head, ListNode *&p, int val)
    //  ListNode *n1 = head->next; // 保存原来下一节点的地址
    //  p->next = n1;              // 将p这个节点的next指针 指向 n1
    //  head->next = p;            // 在将 n这个节点的next指针指向p

    if (index - 1 < 0)
    {
        cout << "输入下标的值小于索引" << endl;
        return;
    }

    if (index - 1 == 0) // 判断是否是头节点
    {
        // 创建一个新的节点
        ListNode *td = new ListNode(val);
        td->next = head;
        head = td;
        return;
    }
    ListNode *current = head;
    for (int i = 0; i == index - 1; i++)
    {
        if (current == nullptr)
        {
            cout << "索引超出链表长度" << endl;
            return;
        }
        current = current->next;
    }

    if (current != nullptr)
    {
        ListNode *td = new ListNode(val);
        td->next = current->next;
        current->next = td;
    }
    else
    {
        cout << "当前节点的位置有误" << endl;
    }
}

// 6. 释放链表在堆区的数据
void DelectList(ListNode *head)
{
    ListNode *current = head;  //  创建 ListNode类型的指针将头节点赋值给current
    while (current != nullptr) // 判断当前的节点不为nullptr
    {
        ListNode *next = current->next; // 将当前节点的下一个节点存储在 next中

        // 在这里需要先释放在存入，否者会出现 还未被释放， 就被重新赋值

        delete current; // 先释放当前的节点
        current = next; // 将存储在next 中的 节点地址赋值给current
    }
}

// 7. 遍历节点中的值

void PrintList(ListNode *head) //  传入一个头节点
{

    int index = 0;
    ListNode *current = head; // 将头节点传入 指针 current
    while (current != nullptr)
    {
        index++;
        cout << "当前是第: " << index << "  个节点 " << "值为:  " << current->val << " " << endl; //  获取到当前节点的 值
        current = current->next;
    }
    cout << "一共有：" << index << " 个节点" << endl;
}
//  遍历元素
int main()
{
    // 初始化各个节点
    ListNode *n0 = new ListNode(11);
    ListNode *n1 = new ListNode(21);
    ListNode *n2 = new ListNode(31);
    ListNode *n3 = new ListNode(41);
    ListNode *n4 = new ListNode(51);
    ListNode *n5 = new ListNode(61);
    ListNode *n6 = new ListNode(71);
    ListNode *n7 = new ListNode(81);
    ListNode *n8 = new ListNode(91);
    ListNode *n9 = new ListNode(101);

    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = nullptr;

    // 1.查找节点
    // int r = Find(n0, 5);
    // cout << "返回的下标为" << r << endl;

    // 2.删除节点
    // Remove(n0, 11);
    // PrintList(n0); // 遍历节点

    // 3.修改
    // Revise(n0, 9, 300);
    // PrintList(n0);

    // 4.访问节点
    // int a;
    // cin >> a;
    // cin.get();
    // ListNode *p = Visit(n0, a);
    // cout << "访问第" << a << "个节点" << "值为：" << p->val << endl;

    // 5.插入节点
    int a, b;
    cout << "输入想要插入节点的位置：";
    cin >> a;
    cin.get();
    cout << "输入要插入节点的值：";
    cin >> b;
    cin.get();
    insert(n0, a, b);
    PrintList(n0);
    //  释放链表
    DelectList(n0);
    cin.get();
    return 0;
}
