#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> // 标准算法文文件
void Pirnt(int val);
// vector 容器存放内置数据类型
void test01()
{
    vector<int> v;
    // 向容器插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    ////第一种
    // //  创建迭代器  类似于指针
    // vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向第一个元素
    // vector<int>::iterator itEnd = v.end();     // 结束迭代器 指向最后一个元素下一个位置

    // // 第一种遍历
    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl; // 在这使用的是 迭代器 类似于指针 在这里需要解引用
    //     itBegin++;
    // }

    // 第二种
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // 第三种 遍历
    for_each(v.begin(), v.end(), Pirnt);
};
void Pirnt(int val)
{
    cout << val << endl;
}
int main()
{
    test01();
    cin.get();
    return 0;
}