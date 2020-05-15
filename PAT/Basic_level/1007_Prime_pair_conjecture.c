/*
让我们定义d(n) 为：d(n) = p(n+1)−p(n)，其中p(i) 是第i个素数。
显然有d(1) = 1，且对于n>1有d(n)是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。
输入格式:
输入在一行给出正整数N。
输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。
输入样例:
20
输出样例:
4
*/
#include <stdio.h>
#include <math.h>
int IsPrime(int number);
int main()
{
    int number, count = 0;
    
    scanf("%d",&number);
    for(number; number>4; number--)
        if(IsPrime(number) && IsPrime(number-2))
            count++;
    printf("%d", count);
    
    return 0;
}
int IsPrime(int number)
{
    int n;
    
    n = sqrt(number);
    for(int i=2; i<=n; i++)
        if(number%i == 0)
            return 0;
    return 1;
}
