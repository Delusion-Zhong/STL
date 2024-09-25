 <h1 align="center">    STL    </h1>

 ![这是图片](/STL/images/六大部件.png)

 STL 提供了六大组件，彼此组合套用协同工作。这六大组件分别是：

**1.容器（Containers）**：各种数据结构，如 vector、list、deque、set、map 等。从实现的角度来看，容器是一种 class template。
**2.算法（Algorithms）**：各种常用算法，提供了执行各种操作的方式，包括对容器内容执行初始化、排序、搜索和转换等操作，比如 sort、search、copy、erase。从实现的角度来看，STL 算法是一种 function template。
**3.迭代器（Iterators）**：迭代器用于遍历对象集合的元素，扮演容器与算法之间的胶合剂，是所谓的“泛型指针”，共有 5 种类型，以及其他衍生变化。从实现角度来看，迭代器是一种将 operator*、operator->、operator++、operator-- 等指针操作予以重载的 class template。所有的 STL 容器附带有自己专属的迭代器，因为只有容器设计者才知道如何遍历自己的元素。
**4.仿函数（Functors）**：也称为函数对象（Function object），行为类似函数，可作为算法的某种策略。从实现角度来看，仿函数是一种重载了 operator() 的 class 或者 class template。
**5.适配器（Adaptors）**：一种用来修饰容器或者仿函数或迭代器接口的东西。例如 STL 提供的 queue 和 stack，就是一种空间配接器，因为它们的底部完全借助于 deque。
**6.分配器（Allocators）**：也称为空间配置器，负责空间的配置与管理。从实现的角度来看，配置器是一个实现了动态配置空间、空间管理、空间释放的 class template。

***
 # 容器介绍
 ![GitHub Logo](/STL/images/容器介绍.png)

## 在mingw64中文件夹下源码路劲
 ````
 安装目录：mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include
````
***
 # 1.分配器
   关于分配器的解读：
   https://blog.csdn.net/weixin_52665939/article/details/131620359

## 实例使用 （不建议直接使用分配器）
下面是两不一样的写法 
 ```
    int *p = allocator<int>().allocate(512, (int *)0);
    allocator<int>().deallocate(p, 512);
```
```
    vector<string, __gnu_cxx::_pool_alloc<string>> vec;
 ```
 ***
# 容器介绍
 
## vector

 ![GitHub Logo](/STL/images/vector.png)
  
   在上图中 vector 是一个 自动扩充的数组，每次遇到超出长度都会**2倍扩容 (当在内存中找不到 2倍内存的时候这个容器的生命周期就会结束 )**

  **在每一次扩容的时候都会有大量的拷贝动作**
 


 
    