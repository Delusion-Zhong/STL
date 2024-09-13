#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class Person
{
public:
    Person(string name, int age) : name(name), age(age) {};

    string name;
    int age;
};
void Print(const Person &p);
void test()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 40);
    Person p3("ccc", 10);
    Person p4("ddd", 40);
    Person p5("mmm", 2010);
    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    // for_each(v.begin(), v.end(), Print);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "name" << (*it).name << "age" << (*it).age << endl;
        cout << "name" << it->name << "age" << it->age << endl;
    }
}
void Print(const Person &p)
{
    cout << "Name: " << p.name << ", Age: " << p.age << endl;
}

// 自定义数据类型
void test2()
{
    vector<Person *> v;
    Person p1("aaa", 10);
    Person p2("bbb", 40);
    Person p3("ccc", 10);
    Person p4("ddd", 40);
    Person p5("mmm", 2010);
    // 向容器中添加数据  存放地址
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name" << (*it)->name << "age" << (*it)->age << endl;
    }
}
int main()
{
    // test();
    test2();
    cin.get();
    return 0;
}
