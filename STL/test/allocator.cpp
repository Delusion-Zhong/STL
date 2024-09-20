#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() 
{
    // 直接使用分配器分配 内存

     int *p = allocator<int>().allocate(512, (int *)0);
     allocator<int>().deallocate(p, 512);

    // vector<string, __gnu_cxx::_pool_alloc<string>> vec;
    vector <string , __gnu_cxx::new_allocator<string>> vec;
    cin.get();
    return 0;


    
}