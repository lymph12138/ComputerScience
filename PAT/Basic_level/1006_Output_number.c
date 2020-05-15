/*
让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），
换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，
因为它有 2 个“百”、3 个“十”、以及个位的 4。
输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。
输出格式：
每个测试用例的输出占一行，用规定的格式输出 n。
输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123
*/
#include <stdio.h>
int main()
{
    int number, i=1;
    int count[3];
    
    scanf("%d",&number);
    count[0] = number/100;
    count[1] = (number/10)%10;
    count[2] = number%10;
    while(count[0])
    {
        printf("%c", 'B');
        count[0]--;
    }
    while(count[1])
    {
        printf("%c", 'S');
        count[1]--;
    }
    while(count[2])
    {
        printf("%d", i);
        i++;
        count[2]--;
    }
    
    return 0;
}
