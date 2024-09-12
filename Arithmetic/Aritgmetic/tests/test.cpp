#include <iostream>
#include <vector>
using namespace std;

class MyList
{
private:
    int *arr;             // 列表
    int arrCapacity = 10; // 列表容量
    int arrSize = 0;      // 列表的长度
    int extendRatio = 2;  // 每次列表扩容的倍数
public:
    // 构造函数
    MyList()
    {
        arr = new int[arrSize];
    }
    // 析构函数
    ~MyList()
    {
        delete[] arr;
    }
    /* 获取列表长度（当前元素数量）*/

    int Size()
    {
        return arrSize;
    }
    /* 获取列表容量 */
    int Capacity()
    {
        return arrCapacity;
    }
    /* 访问元素 */
    int getList(int index)
    {
        if (index < 0 || index >= Size())
        {
            cout << "访问越界" << endl;
        }
        return arr[index];
    }
    /* 修改元素 */
    int SetList(int index, int num)
    {
        if (index < 0 || index >= Size())
        {
            cout << "索引越界" << endl;
        }
        return arr[index] = num;
    }
    /* 添加元素 在尾部*/
    void add(int num)
    {
        // if (Size() == arrCapacity)
        //     extendCapacity(); // 列表扩容
        arr[Size()] = num;
        arrSize++;
    }
    /* 在中间插入元素 */
    void insert(int index, int num)
    {
        if (index < 0 || index > Size())
        {
            cout << "索引越界";
        }
        // 元素数量超出容量时，触发扩容机制
        if (Size() == arrCapacity)
            extendCapacity(); // 列表扩容

        for (int j = Size(); j >= index; --j) //            0      1     2    3
                                              // 先找到下标，当输入的index小于 j的时候所有元素后移  10   (15)   20   30       size（j）=3   index=3
        {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
        arrSize++;
    }
    /* 删除元素 */
    int Deletearr(int index)
    {
        if (index < 0 || index >= Size())
        {
            cout << " 索引越界,删除失败" << endl;
            return -1;
        }
        int num = arr[index];
        for (int i = index; i < Size(); i++)
        {
            arr[i] = arr[i + 1];
        }
        arrSize--;
        return num;
    }

    /* 列表扩容 */
    void extendCapacity()
    {
        // 重新定义List 倍速的长度
        int NewCapacity = arrCapacity * extendRatio;
        int *NewArr = new int[NewCapacity];
        for (int i = 0; i < Size(); i++)
        {
            NewArr[i] = arr[i];
        };

        delete[] arr; // 释放原来的内存
        arr = NewArr; // 更新 arr 指向新内存
        arrCapacity = NewCapacity;
    }
    /* 将列表转换为 Vector 用于打印 */
    vector<int> toVector()
    {
        // 仅转换有效长度范围内的列表元素
        vector<int> vec(Size());
        for (int i = 0; i < Size(); i++)
        {
            vec[i] = arr[i];
        }
        return vec;
    }
};

int main()
{
    // 创建 MyList 对象
    MyList list;

    // 添加元素到列表
    list.add(10);
    // list.add(20);
    // list.add(30);

    // // 打印列表的内容
    // cout << "列表中的属性: ";
    // for (int i = 0; i < list.Size(); i++)
    // {
    //     cout << list.getList(i) << "";
    // }
    // cout << endl;

    // // // 插入元素到列表
    // // list.insert(3, 15);

    // // // 打印更新后的列表内容
    // // cout << " 打印更新后的列表内容: ";
    // // for (int i = 0; i < list.Size(); i++)
    // // {
    // //     cout << list.getList(i) << " ";
    // // }
    // // cout << endl;

    // // 删除元素
    // int tmp = list.Deletearr(5);

    // if (tmp != -1)
    // {
    //     cout << "打印删除后的列表内容: ";
    //     for (int i = 0; i < list.Size(); i++)
    //     {
    //         cout << list.getList(i);
    //     }
    // }
    cin.get();
    return 0;
}
