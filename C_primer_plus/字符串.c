gets() gets_s() fgets() puts() fputs() strcat() strncat() strcmp() strcpy() sprintf() strchr() 
字符串以空字符（\0）结尾
puts()函数只显示字符串，而且自动在显示的字符串末尾加上换行符
字符串数组和初始化：
    char str[];
    指针可以指向数组
    str[7] == *(str + 7);
    谨慎修改指针指向的字符串
    合理使用指针替换数组减少内存使用
两种数组的声明：
    char fruit1[3][7];
    const char *fruit2[3];
    后者占用内存一般更少
拷贝指针数组是拷贝地址而不是整个数组
注意声明数组时就注明大小便于分配空间
gets()函数：
    函数介绍：
        由于scanf() 只能读取一个单词，引入gets() 函数
        读取整行输入，直至遇到换行符，常与puts() 函数配合使用
        put() 函数用于显示字符串，并且在末尾添加换行符
    函数使用方法：
        gets(words);//words 存储字符串，但不包括换行符
        puts(words) == printf("%s\n",words);//作用等价
    安全问题：
        由于不能确定读入字符串的大小，则有可能占用未分配内存
gets() 函数的替代品：
    fgets(words, n，stdin) 函数：fputs(words, stdout)
        读入 words 大小为n-1 个字符，并且会存储换行符
        相应的fputs() 函数在输出时并不会添加换行符
        fget() 函数返回指向char 的指针，读到末尾回空指针
        while(fets(words, stlen, stdin) != NULL && words[0] != '\n')
            fputs(words, stdout);
        系统使用缓冲的 I/O。这意味着用户在按下Return 键之前，输入都被存储在临时存储区（缓冲区）中。
        按下Return 键就在输入中增加了一个换行符，并把整行输入发送给fgets() 函数。
        对于输出，fputs() 函数把字符发送给另一个缓冲区，当发送换行符时，缓冲区的内容被发送至屏幕。
    gets_s(words, n) 函数：
        只从标准输入中读取数据，所以不需要第三个参数
        读到换行符，会丢弃它而不是存储它
        读到最大字符数都没有读到换行符，会执行以下几部。首先把目标数组中的首字符设置为空字符，
        读取并丢弃随后的输入直至读到换行符或文件结尾，然后返回空指针。
    s_gets() 函数：
puts() 函数：
    参数为字符串的指针，输出时在其末尾添加换行符，遇到空字符停止输出
    fputs(words, stdout) 函数：不会在输出末尾添加换行符
自定义输入/输出函数：
#include <stdio.h>
void put1(const char * string)
{
    while(*string)
        putchar (*string++);
}
字符串函数：
    strlen(string) 函数：统计字符串的长度
    strcat(string1, string2) 函数：将string2 拼接在string1 后面
    strncat(string1, string2, n) 函数：将string2 拼接在 string1 后面，直到第n 个字符或者遇到空字符停止
    strcmp(string1, string2) 函数：比较字符串
    strncmp(string1, string2， n) 函数：比较字符串，直到发现不同字符为止
    strcpy(string1, string2) 函数：拷贝string2 整个字符串到string1，返回第一个参数的值，即一个字符的地址
    strncpy(string1, string2, n) 函数：拷贝string2 字符串到sstring1，直到第n 个字符串或者遇到空字符停止
    sprintf(formal, "",string) 函数：sprintf 与 printf 用法相同，只不过是把输出存储在formal（地址）中
    
        
        
    
    