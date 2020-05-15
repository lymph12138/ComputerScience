/*
设计函数求一元多项式的导数。（注：x^n（n为整数）的一阶导数为nx^(n−1)。）
输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。
输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，
但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。
输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, count=0;
    
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(!n && !count)
        {
            printf("%d %d",0 ,0);
            break;
        }
        if(!n)
            break;
        if(!count)
        {
            printf("%d %d", m*n, n-1);
            count++;
        }
        else
            printf(" %d %d", m*n, n-1);
        if(getchar()!=' ')
            break;
    }
    
    return 0;
}
int main()
{
    int coef, index, count = 0;

    while(scanf("%d %d", &coef, &index) != EOF)
    {
        if(index) /* Constant terms result in zero */
        {
            if(count++) putchar(' ');
            printf("%d %d", coef * index, index - 1);
        }
    }

    /* Zero polynomial or constant */
    if(count == 0)
        puts("0 0");

    return 0;
}