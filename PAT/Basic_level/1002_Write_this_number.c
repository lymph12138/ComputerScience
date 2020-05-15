/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/
#include <stdio.h>
int main()
{
    char *number;
    char *PinYin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int count = 0;
    int i=0;
    
    gets(number);
    while(number[i] != '\0')
    {
        count = count+number[i]-'0';
        i++;
    }
    if(count/100)
        printf("%s ",PinYin[count/100]);
    if(count/10)
        printf("%s ",PinYin[(count/10)%10]);
    puts(PinYin[count%10]);
        
    return 0;
}