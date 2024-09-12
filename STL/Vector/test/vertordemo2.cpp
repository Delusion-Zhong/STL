#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{

    int ai[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int>> vi(ai, ai + 6);
    cout << count_if(vi.begin(), vi.end(),
                     not1(bind2nd(less<int>(), 40)));
    cin.get();
    return 0;
}
/*
1.count_if
    count_if 是一个算法函数，用于统计满足给定条件的元素个数。
    参数 first 和 last：这两个参数指定了要检查的范围 [first, last)。
    参数 pred：这是一个谓词（即一个函数或函数对象），它对每个元素进行检查，返回 true 或 false。count_if 会统计范围内符合 pred 这个条件的元素数量。
    vector<int> vi = {1, 2, 3, 4, 5};
    int count = count_if(vi.begin(), vi.end(), [](int x) { return x > 3; });
    // count 的值是 2，因为 4 和 5 大于 3



2.bind2nd
bind2nd 是一个函数适配器，用于创建一个新的函数对象，该对象将固定的第二个参数（x）与给定的二元谓词（pred）的第一个参数进行比较。新的函数对象只有一个参数，它会用这个参数和固定的 x 值进行比较。

参数 pred：这是一个二元谓词（接受两个参数的函数对象）。
参数 x：这是固定的第二个参数。
auto pred = bind2nd(less<int>(), 10);
// 这个谓词检查第一个参数是否小于 10


3. less<int >
    less 是一个函数对象，用于检查两个值的大小关系。它的作用是判断第一个值是否小于第二个值。

4. not1
not1 是一个函数适配器，用于创建一个新的谓词，它是原始谓词的逻辑非（取反）。即，如果原谓词返回 true，not1 创建的谓词将返回 false，反之亦然。

参数 pred：这是一个一元谓词（接受一个参数的函数对象）。

auto pred = [](int x) { return x < 10; };
auto not_pred = not1(pred);
// not_pred 现在是一个谓词，它返回 true 当且仅当 x 不小于 10



count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
bind2nd(less<int>(), 40)：创建一个函数对象，这个对象用于比较一个数是否小于 40。它会生成一个谓词 x < 40。
not1(...)：对上述谓词进行逻辑取反。结果是一个谓词 x >= 40。
count_if(...)：统计 vi 向量中满足 x >= 40 这个条件的元素个数。
最终，cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))); 这行代码的作用是输出 vi 向量中大于或等于 40 的元素个数。



*/