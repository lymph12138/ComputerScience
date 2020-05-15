/*
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
A1 = 能被 5 整除的数字中所有偶数的和；
A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1 −n2 +n3 −n4 ⋯；
A3 = 被 5 除后余 2 的数字的个数；
A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A5 = 被 5 除后余 4 的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，
随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。
输出格式：
对给定的 N 个正整数，按题目要求计算 A1 ~A5 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出 N。
输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
*/
#include <stdio.h>
int main()
{
    int a1 = 0; int a2 = 0;int a3 = 0;int a5 = 0; float a4 = 0;
    int c1, c2, c3, c4, c5;
    int n;
    c1 = 0; c2 = 1; c3 = 0; c4 = 0; c5 = 0;
    
    scanf("%d", &n);
    while(1)
    {
        scanf("%d", &n);
        if(n%10 == 0)
            a1 = a1+n;
        else if(n%5 == 1)
        {
            a2 = a2 + c2*n;
            c2 = -c2;
            c1 = 1;
        }
        else if(n%5 == 2)
            a3++;
        else if(n%5 == 3)
        {
            a4 = a4+n;
            c4++;
        }
        else if(n%5 == 4)
            if(n>a5)
                a5 = n;
        if(getchar() == '\n') 
            break;
    }
    if(a1) printf("%d ", a1); else printf("%s", "N ");
    if(c1) printf("%d ", a2); else printf("%s", "N ");
    if(a3) printf("%d ", a3); else printf("%s", "N ");
    if(c4) printf("%.1f ", a4/c4); else printf("%s", "N ");
    if(a5) printf("%d", a5); else printf("%s", "N");
    
    return 0;    
}