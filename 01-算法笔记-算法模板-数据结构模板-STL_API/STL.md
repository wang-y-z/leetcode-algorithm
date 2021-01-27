## vector

```C++
变长数组，倍增的思想
	size()  返回元素个数
	empty()  返回是否为空
	clear()  清空
	front()/back()
	push_back()/pop_back()
	begin()/end()
	[]
	支持比较运算，按字典序
```

## string

```C++
string，字符串
	szie()/length()  返回字符串长度
	empty()
	clear()
	substr(起始下标，(子串长度))  返回子串
	c_str()  返回字符串所在字符数组的起始地址
```

## stack

```C++
stack, 栈
	size()
	empty()
	push()  向栈顶插入一个元素
	top()  返回栈顶元素
	pop()  弹出栈顶元素
```



## priority_queue

```C++
priority_queue, 优先队列，默认是大根堆
	push()  插入一个元素
	top()  返回堆顶元素
	pop()  弹出堆顶元素
	定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;
```

其实就是堆，默认是大根堆，小根堆可以直接这样写`priority_queue,greater> q;`

> greater的作用可以这样记：当想要反转STL容器的比较方式时就可以传入这个参数
> 为了方便最好还是直接记住，如果不想记，可以每次将插入的数都变成他的相反数（大小关系就反过来了，变相处理成小根堆），取出的时候 再乘个-1变回来就行

## deque

```C++
deque, 双端队列
	size()
	empty()
	clear()
	front()/back()
	push_back()/pop_back()
	push_front()/pop_front()
	begin()/end()
	[]
```

deque（双端队列），功能很多很强大，但是效率低，很慢，一般不用

## queue

```C++
queue, 队列
	size()
	empty()
	push()  向队尾插入一个元素
	front()  返回队头元素
	back()  返回队尾元素
	pop()  弹出队头元素
```

## pair

```C++
pair<int, int>
	first, 第一个元素
	second, 第二个元素
	支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
```

pair底层就是一个结构体，可以将pair当成结构体来用，一般存一个二元组（多元也行，pair套pair，疯狂套娃）；

> 并且他已经帮你实现好了比较功能（第一关键字优先），写法又很简洁，省很多代码 

## set、multiset、map、multimap

```C++
set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
		size()
		empty()
		clear()
		begin()/end()
		++, -- 返回前驱和后继，时间复杂度 O(logn)
		
		set/multiset
			insert()  插入一个数
			find()  查找一个数
			count()  返回某一个数的个数
			erase()
				(1) 输入是一个数x，删除所有x   O(k + logn)
				(2) 输入一个迭代器，删除这个迭代器
			lower_bound()/upper_bound()
				lower_bound(x)  返回大于等于x的最小的数的迭代器
				upper_bound(x)  返回大于x的最小的数的迭代器
		map/multimap
			insert()  插入的数是一个pair
			erase()  输入的参数是pair或者迭代器
			find()
			[]   时间复杂度是 O(logn)
			lower_bound()/upper_bound()

	unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
		和上面类似，增删改查的时间复杂度是 O(1)
		不支持 lower_bound()/upper_bound()， 迭代器的++，--
```

基于AVL平衡二叉树（具体来说是红黑树），内部有序
其中虽说数组是int映射到其他类型，是特殊的map，但数组支持随机存取是O(1)的，map查找是O(logn)的

> 树高logn

## unorder_set、unorder_multiset、unorder_map、unorder_multimap

基于哈希实现，增删改查等大部分操作的复杂度都是O(1)，但因为内部无序，故不支持lower_bound()和upper_bound()，也不支持迭代器的加或减

> 即所有和排序相关的操作都不行，享受好处就要付出代价

## bitset

```C++
bitset, 圧位
	bitset<10000> s;
	~, &, |, ^
	>>, <<
	==, !=
	[]
	
	count()  返回有多少个1
	
	any()  判断是否至少有一个1
	none()  判断是否全为0
	
	set()  把所有位置成1
	set(k, v)  将第k位变成v
	reset()  把所有位变成0
	flip()  等价于~
	flip(k) 把第k位取反
```

压位。bitset存储二进制数位。就像一个bool类型的数组一样，但是有空间优化——bool型元素占1B，bitset中的一个元素只需要1bit，相对于bool来说优化了八倍。存一个10000*10000的bool矩阵，直接存就超出空间限制，此时就可以用bitset来存。
一般使用中可以把bitset看成数组，每个元素只占1bit，支持与或非异或取等操作
一般来说bitset初始化就需要设置大小，如`bitset<32> a；`就表示a中存了32个二进制位