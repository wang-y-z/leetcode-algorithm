# C++ Tricks
[toc]



### 取最值

```C++
int a = std::min({x1,x2,x3,x4});
```
### Lambda表达式
> 不用再显式编写函数
```C++
std::sort(v.begin(),v.end(),[](int a, int b){return (a%10)>(b%10);});//比较两个数个位数顺序
[](参数列表,...){code;};
在 () 中传入参数，在 {} 中编写代码，[] 是一个捕获列表，可以指定外部作用域中，可以使用的局部变量：
[] — 捕获列表为空，表示在 lambda 表达式中不能使用任何外部作用域的局部变量，只能使用传进去的参数。
[=] — 表示按照值传递的方法捕获父作用域的所有变量。
[&] — 表示按照引用传递的方法捕获父作用域的所有变量。
[this] — 在成员函数中，按照值传递的方法捕获 this 指针。
[a, &b] — 不建议直接使用 [=] 或 [&] 捕获所有变量，可以按需显式捕获，就是在 [] 指定变量名，[a] 表示值传递，[&b] 表示引用传递。
```

### emplace_back()取代push_back()

>  emplace_back 比 push_back 更有效率，因为 push_back 会先创建一个临时变量（构造函数），然后将其拷贝到 vector 的末尾（拷贝构造函数）。但 emplace_back 就直接在 vector 的末尾构造值（构造函数），少调用了一次拷贝构造函数。 C++11

### tuple秒杀pair

```cpp
#include <tuple>

std::tuple<int, char, std::string> tp = std::make_tuple(1, 'a', "he");
std::cout << std::get<0>(tp) << "," << std::get<1>(tp) << "," << std::get<2>(tp) << std::endl;
```

 通过 `std::get(tp)` 来获取 tp 中的每个值。 

### 不用 for 循环，对数组进行深拷贝

```cpp
#include <algorithm>

int x[3]={1,2,3}; 
int y[3]; 
std::copy_n(x, 3, y);
```

- 第一个参数是指向第一个源元素的输入迭代器；
- 第二个参数是需要复制的元素的个数；
- 第三个参数是指向目的容器的第一个位置的迭代器。