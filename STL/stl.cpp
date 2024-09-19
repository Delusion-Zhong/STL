#include <iostream>
#include <array>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
long get_a_target_long()
{
    long target = 0;
    // 该行代码通过标准输出提示用户输入一个值。RAND_MAX 是 cstdlib 库中定义的常量，表示使用 rand() 函数可以生成的最大随机数。
    cout << "target(0~" << RAND_MAX << "): ";
    cin >> target;
    cin.get(); // 缓冲输入的 /0 换行
    return target;
}
string get_a_target_string()
{
    long target = 0;
    char buf[10];
    cout << "target(0~" << RAND_MAX << "): ";
    cin >> target;
    cin.get();
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
static const long ASIZE = 500000L;

namespace Arraydemo
{

    void test_array()
    {

        array<long, ASIZE> c;
        clock_t timeStart = clock();
        for (long i = 0; i < ASIZE; i++)
        {
            c[i] = rand();
        }
        cout << " 花了多少 时间 :" << (clock() - timeStart) << endl;
        cout << " array 的 长度" << c.size() << endl;
        cout << " array 的 第一个值（front）" << c.front() << endl;
        cout << " array 的 最后一个值（back）" << c.back() << endl;
        cout << " array 的 在地址中的首地址（data） " << c.data() << endl;
        //   cout << "qsort()+bsearch()-milli -seconds:" << (clock() - timeStart);

        timeStart = clock();
        long target = get_a_target_long();
        // 快速排序compareLongs:

        // compareLongs 这是传递给 qsort() 的第四个参数，指向一个比较函数的指针。该函数用于比较数组中的两个元素。
        //     qsort() 使用该函数来确定两个元素的相对顺序（即哪个在前，哪个在后）。
        qsort(c.data(), ASIZE, sizeof(long), compaeLongs);

        {
            /*
                    参数详解
                    &target: bsearch() 的第一个参数，表示你要查找的目标元素的地址。
                    target 是一个 long 类型的变量，代表你希望在数组中查找的具体数值。通过 &target，你把它的地址传递给 bsearch()。
                    c.data():

                    c.data(): bsearch() 的第二个参数，表示要进行二分查找的数组的起始地址。
                    c 是一个 std::vector<long>，调用 c.data() 获取其底层的数组指针。
                    这样，bsearch() 将对 c 数组中的元素进行查找。
                    ASIZE:

                   ASIZE: bsearch() 的第三个参数，表示数组的大小（元素个数）。ASIZE 是数组 c 中元素的数量。
                    sizeof(long):

                   sizeof(long): bsearch() 的第四个参数，表示数组中每个元素的大小（以字节为单位）。由于数组元素是 long 类型，因此 sizeof(long) 返回 long 类型的大小（通常为 4 或 8 字节，取决于系统架构）。


                    compareLongs: bsearch() 的第五个参数，指向一个比较函数的指针。bsearch() 使用该函数比较数组中的元素和目标值，以确定元素是否匹配。
                    compareLongs 是一个比较函数，用于比较两个 long 值的大小。它的定义类似于用于 qsort() 的比较函数，例如：
                    */
            /*
                   bsearch() 函数的工作原理
                   bsearch() 函数用于在已经排序好的数组中执行二分查找。它逐步将数组折半，以查找目标元素的位置。
                   如果找到目标元素，bsearch() 返回该元素的指针。
                   如果没有找到，bsearch() 返回 nullptr。
              */

            /*
            long *pItem = (long *)bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs);

            pItem 是一个指向 long 类型的指针，用于保存 bsearch() 返回的查找到的元素的地址。
           bsearch() 返回一个 void* 指针，需要将其转换为 long* 类型，使用 (long *) 来进行类型转换。
           如果 bsearch() 找到了目标元素，pItem 将指向该元素在数组中的位置；否则，pItem 将为 nullptr。
            */
        }
        long *pItem = (long *)bsearch(&target, (c.data()), ASIZE, sizeof(long), compaeLongs);
        cout << "qsort()+bsearch()-milli -seconds:" << (clock() - timeStart) << endl;

        if (pItem != nullptr)
        {
            cout << "找到了：" << *pItem << " 地址是" << pItem << endl;
        }
        else
        {
            cout << "没有找到" << endl;
        }
    }

} // namespace array
namespace Vectoedemo
{
    void test_vector(long &value)
    {
        vector<string> c;
        char buf[10];
        clock_t timeStart = clock();

        for (long i = 0; i < value; i++)
        {
            try
            {
                snprintf(buf, 10, "%d", rand()); //"%d" 用于表示一个十进制整数的格式化输出，因此函数将使用此格式将rand() 生成的整数转换为字符串。
                c.push_back(string(buf));
            }
            catch (exception &p) //&p 表示通过引用捕获异常对象。这意味着我们在 catch 块中处理的是异常的引用，而不是副本。
            {
                cout << "i=" << i << p.what() << endl;
                abort();
                {
                    /*
                    abort() 是 C++ 标准库中的一个函数，用来立即终止程序的执行。
                    当 abort() 被调用时，它会强制程序终止，而不调用任何对象的析构函数，也不执行任何清理操作。
                    通常，调用 abort() 会导致程序返回一个错误代码，表示程序由于某种严重的错误而终止。*/
                }
            }
        }

        cout << " milli -seconds :" << (clock() - timeStart) << endl;
        cout << "  vector的 长度" << c.size() << endl;
        cout << " vector的 的 第一个值（front）" << c.front() << endl;
        cout << " vector的 的 最后一个值（back）" << c.back() << endl;
        cout << " vector的 的 在地址中的首地址（data） " << c.data() << endl;
        cout << "c.capacity()=" << c.capacity() << endl;

        string target = get_a_target_string();
        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target); // 循环查找 target   查找的值是使用auto 接收  不能直接使用指针去访问
            cout << ":: find  花费的时间(毫秒)：" << (clock() - timeStart) << endl;

            if (pItem != c.end())
            {
                cout << "找到了：" << *pItem << " 地址是" << &pItem << endl;
            }
            else
            {
                cout << " 没有找到！！  " << endl;
            }

            {
                timeStart = clock();
                sort(c.begin(), c.end());
                string *pItem = ((string *)bsearch(&target, (c.data()), c.size(), sizeof(string), compaeLongs));
                cout << "sort()+ bsearch() 花费的时间(毫秒)：" << (clock() - timeStart) << endl;
                if (pItem != nullptr)
                {
                    cout << "找到了：" << *pItem << " 地址是" << &pItem << endl;
                }
                else
                {
                    cout << " 没有找到！！  " << endl;
                }
            }
        }
    }

} // namespace Vectoedemo

int main()
{
    // Arraydemo::test_array();
    long target;
    cout << "存入vector多少个值： ";
    cin >> target;
    Vectoedemo::test_vector(target);
    cin.get();
    return 0;
}