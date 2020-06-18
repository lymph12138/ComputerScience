符号表：(散列表，哈希表)SymbolTable
名字(Name)-属性(Attribute)

1, SymbolTable InitializeTable(int TableSize)：创建一个长度为TableSize的符号表
2, Boolean IsIn(SymbolTable Table, NameType Name)：查找特定的名字Name是否在符号表Table中
3, AttributeType Find(SymbolTable Table, NameType Name)：获取Table中特定名字Name对应的属性
4, SymbolTable Modefy(SymbolTable Table, NameType Name, AttributeType Attr)：将Table中指定名字Name的属性修改为Attr
5, SymbolTable Insert(SymbolTable Table, NameType Name, AttributeType Attr)：向Table中插入新名字Name及属性Attr
6, SymbolTable Delete(SymbolTable Table, NameType Name)：从Table中删除一个名字Name及其属性

散列(Hashing), 冲突(Collision) 取余

散列函数的构造：计算简单，地址空间分布均匀，尽量减少冲突

1.直接定址法
h(key) = a*key+b(const);
2.除数留余法
h(key) = key mod p;(ex. key%17)p is a prime number
3.数字分析法
h(key) = atoi(key+7)
4.折叠法
关键词分割相加，以达到折叠的目的
5.平方取中法
关键词平方取中间的几位数
6.Other
h(key) = (sigma key[i]) mod TableSize;
h(key) = (key[0]*z7^2 + key[1]*27 + key[2]) mod TableSize;
h(key) = ((i=0, n-1)sigma key[n-i-1]*32^i) mod TableSize;

冲突处理：换个位置(开放地址法)，同一位置的冲突对象组织在一起(链地址法)
开放地址法：一旦发生冲突(该地址已有其它元素)，就按照某种规则去寻找另一空地址
    hi(key) = (h(key)+di) mod TableSize;
di决定了不同的解决冲突方案：线性探测，平方探测，双散列
1.线性探测法(Linear Probing)以增量序列1，2，循环试探下一个存储地址
散列查找性能分析：
    成功平均查找长度(ASLs)：冲突次数加1
    不成功平均查找长度(ASLu)
2.平方探测法(Quadratic Probing)以增量序列1^2, -1^2, 2^2, -2^2,

