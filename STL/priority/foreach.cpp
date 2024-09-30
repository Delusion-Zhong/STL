#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    // auto 自动推导数据类型
    vector<int> a = {1, 2, 3};

    for (auto i : a)
    {
        cout << i << endl;
    }

    // 上面的一种foreach 用来你遍历
    //  下面的这一种使用的是引用传递，然后给 i遍历的每一个值进行 *3 的 操作
    for (auto &i : a)
    {
        i *= 3;
        cout << i << endl;
    }
    cin.get();
    return 0;
}