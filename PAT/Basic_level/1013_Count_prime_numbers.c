/*
令 Pi 表示第 i 个素数。现任给两个正整数 M≤N≤10^4，
请输出 PM 到 PN 的所有素数。
输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。
输出格式：
输出从 PM 到 PN 的所有素数，每 10 个数字占 1 行，
其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <stdio.h>
#include <math.h>
int IsPrime(int numebr);
int main()
{
    int m, n, count = 1;
    int pm, pn;
    
    scanf("%d %d", &m, &n);
    pm = 2;
    while(count<m)
    {
        pm++;
        if(IsPrime(pm))
            count++;
    }
    count = 1;
    printf("%d%c", pm, n-m ? ' ' : '\0');
    while(count<n-m+1)
    {
        pm++;
        if(IsPrime(pm))
        {
            count++;
            printf("%d", pm);
            if(n-m+1!=count && count%10!=0) printf("%c", ' ');
            else if(n-m+1!=count && count%10==0) printf("%c", '\n');
            else if(n-m+1==count) printf("%c", '\0');
        }
    }
    
    return 0;
}
int IsPrime(int number)
{
    int n;
    
    n = sqrt(number);
    for(int i=2; i<=n; i++)
        while(number%i == 0)
            return 0;
    return 1;
}