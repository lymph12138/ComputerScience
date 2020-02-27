基本结构：
#include <stdio.h>
int main(void)
{
    int feet;//变量名
             //空行
    feet=2; //每一行一条语句  
             //空行                                  
    return 0;//结束
}

数据类型：
最初K&R标准 int long short unsigned char float double 
C90标准 signed void 
C99标准 _Bool _Complex _Imaginary

数据类型：
    有符号整型：
        int: 不小于16位 %d [-32767,32767]   
        short:(short int) 不小于16位 %hd 十进制 %ho 八进制 [-32767,32767]
        long:(long int) 不小于32位 %ld十进制 %lo 八进制 %lx 十六进制 [-2147483647,2147483647]
        long long: 不小于64位 %lld 十进制 [-9223372036854775807,9223372036854775807]
    无符号整型：
        unsigned:(unsigned int) %u
        unsigned long: %lu
        unsigned short: %hu
    字符类型：
        char：8位 %c 
    布尔类型：
        _Bool: %d                                                                         
    实浮点类型：%n.mf n为有效数字个数，m为小数点后位数
        float：32位 %f %e 精度6位
        double：64位 %f %e 精度12位
        long double: %lf %le 
    补充：
        sizeof: %zd
        strlen()：%zd
        #define name value
        const：只读
        336=1*256+1*64+1*16 00000001 01010000        
断行方法：
    printf("Here's " "a hero")

输入方法：
    scanf("%d", &number)
    scanf("%s",string)
类型级别：
    long double->double->float->unsigned long long->long long->unsigned long->long->unsigned int->int
    long 与 int 大小相同时 unsigned int->long 
    short 与 char 升级到 int 或 unsigned int
    截断赋值法
    (int)1.8 = 1
#include <ctype.h>：
    isalpha():检验是否为字符
#include <iso646.h>：
    and 表示 &&
    or 表示 ||
    not 表示 ！
优先级:
    () > ! = ++ > * > && > || > +
？: A？B：C：
    A为判定条件，A成立取B，A不成立取C
switch:
        switch(A) 
        {
            case A1:B1;
            case A2:B2; 
            default:break;
        }
        A为判定标准，A1，A2为A的各种情况，B1，B2为取到的结果，或执行的步骤(k可为空)
        default语句可以选择，不一定非要为break

goto：
    FORTRAN 或 BASIC 经常使用goto，C中避免使用goto
getchar() putchar()：
缓冲区(buffer)：
    缓冲输入：
        完全缓冲I/O：
        行缓冲I/O：
    无缓冲输入：
        <conio.h> getche() getch()
文件，流和键盘输入：
    EOF：文件结尾
重定向和文件：
    if(scanf("%d %d", &rows, &cols) != 2)
        break;
    while(getchar() !='\n')
        continue;
    
    while(scanf("%ld", &n) ==1 && n >=0)
        statement;
        
函数：在int函数前声明(不带分号),定义可以在int函数之后
    void starbar(void)
    int average(int a, int b)
指针：一个值为内存地址的变量（或数据对象）
    声明： 
        pointer ptr;//错误方法
        int * pi   char * pc  float * pf, * pg;//正确表达，* 与 变量名之间空格可有可无 
    ptr = &pooh;//把pooh的地址赋给ptr
    val = *ptr; //找出ptr指向的值
    val = pooh;
    应用：
        void interchange(int * u, int * v)
        int function1(int num) function(x)//传递x的值
        int function2(ont * ptr) function2(&x)//传递x的地址
变量：名称、地址和值
    &运算符访问地址，*运算符访问地址上的值

    