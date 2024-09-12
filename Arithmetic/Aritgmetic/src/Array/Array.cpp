#include <iostream>
#include <cstdlib> // 包含 rand() 和 srand()
#include <ctime>   // 包含 time()
using namespace std;

// 初始化数组

// 指针引用传递 通过指针引用传递，test() 函数可以修改调用者传入的指针
// 确保函数内部对指针的修改在外部也生效。
// 在堆区开辟内存
// void test(int *&arr, int *&nums)
// {

//     int *arr = new int[5];
//     int *nums = new int[5];
// };
// 指针传递 只需要释放内存，而不需要修改指针，所以普通指针传递就足够了。
// void DelectArr(int *arr, int *nums)
// {
//     delete[] nums;
//     delete[] arr;
// };

// 1.随机访问一个元素
int RandomAccess(int const *const nums, int const size)
{
    // 获取一个随机数
    int Index = rand() % size;
    // 获取到nums[Index]的值
    int randomNum = nums[Index];
    cout << "获取到的随机数是：" << nums[Index] << "    下标是：" << Index << endl;
    return randomNum;
}

// 2. 插入数据  （会对数据修改 因此使用指针的引用传递）
int *insert(int *&nums, int const size, int const num, int const index)
{
    // 创建一个新数组，大小比原数组大1
    int *res = new int[size + 1];

    // 复制原数组中 index 之前的元素
    for (int i = 0; i < index; i++)
    {
        res[i] = nums[i];
    }

    // 插入新元素
    res[index] = num;

    // 复制 index 之后的元素
    for (int i = index; i < size; i++)
    {
        res[i + 1] = nums[i];
    }

    // 释放原数组
    delete[] nums;

    // 返回新数组
    return res;
}

// 3.删除数据 （会对数据修改 因此使用指针的引用传递）
int *DelectArray(int *&nums, int const size, int const index) // 5 --下标 4
{                                                             // 把索引 index 之前的元素赋值给res
    int *res = new int[size - 1];
    for (int i = 0; i < index; i++)
    {
        /*将第 i-1的值赋值给i */
        res[i] = nums[i];
    }
    for (int i = index; i < size - 1; i++)
    {
        res[i] = nums[i + 1];
    }
    return res;
};

// 4.查找元素

int find(int const *nums, int const size, int const target)
{
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == target)
        {
            return i; // 循环结束后未找到目标值，返回 -1
        }
    };
    return -1; // 循环结束后未找到目标值，返回 -1
};

// 5. 扩容数组  （会对数据修改 因此使用指针的引用传递）
int *Expansion(int *&nums, int const size, int const enlarge)
{
    int index = size + enlarge;
    int *res = new int[index];
    for (int i = 0; i < size; i++)
    {
        res[i] = nums[i];
    }

    delete[] nums;
    cout << "扩容长度到" << index << endl;
    return res;
}
// 修改数组的元素
int *Revise(int *&nums, int size, int index, int num)
{
    int *res = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            nums[i] = num;
        }
    }
    for (int i = 0; i < size; i++)
    {
        res[i] = nums[i];
    }
    delete[] nums;
    return res;
}

// 遍历数组
void Traverse(int const *const nums, int const size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " "; // 输出数组的值
    }
    cout << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // 初始化随机数生成器
    int const size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    // 1.获取一个随机的一个元素
    // RandomAccess(arr, 6);

    // 2.插入一个元素
    cout << "修改前的数组:";
    Traverse(arr, size); // 遍历初始化的全部10个元素
    cout << "修后前的数组:";
    arr = insert(arr, size, 100, 5); // 在索引 5 的位置插入 100
    Traverse(arr, size + 1);

    // 3.删除一个元素
    arr = DelectArray(arr, size, 5);
    Traverse(arr, size - 1);

    // 4.查找元素
    cout << "下标为：" << find(arr, size, 100) << endl;

    // 5.扩容数组
    arr = Expansion(arr, size, 5);
    Traverse(arr, 15);

    // 修改元素
    arr = Revise(arr, size, 0, 15);
    Traverse(arr, size);

    delete[] arr; // 释放new出来的空间 以防内存泄漏
    cin.get();
    return 0;
}
/*  
    1. 出现对动态内存分配不熟练，最后没有delec []arr
    2.在对内存进行操作的时候，不熟悉使用地址等

     */