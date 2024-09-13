#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class demo
{
public:
    long get_a_target_long()
    {
        long target = 0;
        cout << "target(0~" << RAND_MAX << "): ";
        cin >> target;
        return target;
    }
    string get_a_target_string()
    {
        long target = 0;
        char buf[10];
        cout << "target(0~" << RAND_MAX << "): ";
        cin >> target;
        snprintf(buf, 10, "%d", target);
        // 10 是 buf 数组的最大长度（包括结束符 '\0'），这意味着最多可以写入 9 个字符加上一个结束符。
        // "%d" 是格式字符串，用于将 target 格式化为十进制整数的字符串。
        return string(buf);
    }
    int compaeLongs(const void *a, const void *b)
    {
        return (*(long *)a - *(long *)b);
        /*
        (long *)a 和 (long *)b 将 const void * 类型的指针 a 和 b 转换为 long * 类型的指针。
        这是因为 qsort 等排序函数在传递比较函数时，通常使用 void * 类型的参数，以便能够处理不同类型的数据。
       a 和 b 实际上是指向要比较的两个元素的指针，但它们是 void * 类型，因此需要先转换成 long *。
       */
    }
    int compareStrings(const void *a, const void *b)
    {
        if (*(string *)a > *(string *)b)

            return 0;
        else if (*(string *)a < *(string *)b)
            return -1;
        else
            return 0;
    }
};

int main()
{
    cin.get();
    return 0;
}
