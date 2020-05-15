/*
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。
字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，
单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。
输出格式：
每个测试用例的输出占一行，输出倒序后的句子。
输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    char str[81];
    gets(str);
    char *p = str, *i;
    
    while(*++p);                                      //to the end of the string
    while(p > str)
    {
        while(isspace(*--p));                         //to the end of the word
        while(p>str && isspace(*(p-1))==0)            //to the start of the word
            p--;                          
        for(i=p; *i && isspace(*i)==0; putchar(*i++));//print the word
        putchar(p>str ? ' ' : '\0');                  //print space before the end
    }
    
    return 0;
}
