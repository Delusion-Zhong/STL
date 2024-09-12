#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{

    vector<int> a = {1, 2, 3};

    for (auto i : a)
    {
        cout << i << endl;
    }
    for (auto &i : a)
    {
        i *= 3;
        cout << i << endl;
    }

    cin.get();
    return 0;
}