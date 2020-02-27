数组：
    声明：
        int states[50];
        float candy[365];
        char code[20];
    初始化：
        int powers[6] =｛1, 2, 3, 4, 5, 6}; 
        int days[] = {31, 30, 28};//sizeof days/sizeof days[0]=3;
        int days[6] = {31, [1]=28, 31, [4]=30, [2]=44};//{31, 28, 44, 0, 30, 0}
    多维数组：
        int rain[5][12];
        int rain[2][3] = {{1, 2}, {3, 4}};//rain[0][2]=0  rain[1][0]=3  rain[1][1]=4
        int rain[2][3] = {1,2,3,4};//rain[0][2]=3  rain[1][0]=4  rain[1][1]=0
指针：
    声明：
        short dates[4];
        short * pti;
        double bills[4];
        double * ptr;
    初始化：
        pti = dates;
        ptr = bills;
    性质：
        pti + 1 == &dates[1];
        *(ptr + 2) == bills[2];
        指针加1，指针的值递增它所指向的类型的大小
        * 优先级大于 +
函数与指针：
    toatal = sum(marbles);//marbles为数组，求和
    int sum(int * ar)；//ar对应了数组
    ar[i]与*(ar + i)相同
    指针可以表示数组名，数组也能表示指针
    声明函数原型:(定义函数原型不能省略参数名)
        int sum(int * ar, int n);
        int sum(int * , int);
        int sum(int ar[], int n);
        int sum(int [], int);
    函数形参的使用：
        while(start < end)
        {
            total += *start;//把数组元素的值加起来
            start++;//让指针指向下一个元素
        }
        total += *start++;
指针操作：
    赋值：把地址赋给指针
        ptr1 = urn;//urn 数组首地址赋给ptr1
        ptr2 = &urn[2];//urn 数组第三个元素地址赋给ptr2
        不能把double类型的地址赋给指向int类型的指针
    解引用：* 运算符给出指针指向地址上存储的值
        a = *ptr1;//a 为urn数组第一个元素的值
        b = *(ptr1+1);//b 为urn数组第二个元素的值
    取地址：& 运算符给出指针本身的地址
        printf("%p",ptr1);//打印ptr1 指针的地址
    指针与整数相加(相减)：
        ptr1 + 2 == &urn[2];//ptr1 指针地址加2 即等于ptr2
    递增(递减)指针：
        ptr++ == &urn[1];//ptr++ 即等于 urn数组第二个元素的地址
    指针求差(比较)：
        ptr2 - ptr1 == 2;//ptr2 - ptr1 即表示ptr2 与 ptr1 相隔两个数组单位
    切忌解引用未初始化的指针
        未初始化的指针的值是一个随机数，有可能引发程序错误
const 用法：
    const a;//const 值，不能修改值
    int * const b;//const 指针地址，不能修改地址，可以修改值
    const int * const c;//const 值与地址 ，都不能修改
指针与多维数组：int num[2][4]
    printf("%p",num);//打印二维数组第0行第0列元素的地址
    printf("%p",num[0]);//打印二维数组第0行第0列元素的地址
    **num == *num[0] == num[0][0]
    *(*(num+1)+2) == num[1][2]
    int (* ptr1)[2];//声明了一个ptr1 指针指向一个含有两个int 类型值的数组，用于n 行 2 列
    int * ptr2[2];//声明了两个指向int 的指针
    指针和数组表示数组中的元素可以互通，ptr[1][0] 与 num[1][0]
    指针不能进行类型的转换，不同类型所占用的内存大小不一样
    数组大小可以用参数表示，但是一经确定就不能再更改
复合字面量：
    (int [2]) {10, 20};//等同于 int diva[2] = {10, 20},2 可以省略
    int * pt1; pt1 = (int []) {10, 20};
    int (*pt2)[4];//声明一个指向二维数组的指针
    pt2 = (int [2][4]) { {1, 2, 3, 4}, {5, 6, 7, 8} };
    
    
    