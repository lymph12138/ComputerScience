#include <cstdio>
#include <math.h>
#define maxn 100010
struct factor
{
    int x, cnt;
} fac[10];
int P[maxn] = {0}, Prime[maxn], PrimeNum = 0;
void FindPrime()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (P[i] == 0)
        {
            Prime[PrimeNum++] = i;
            for (int j = i + i; j < maxn; j += i)
                P[j] = 1;
        }
    }
}

int main()
{
    int n, sqr, num = 0;
    scanf("%d", &n);
    sqr = sqrt(n);
    FindPrime();
    if (n == 1)
        printf("1=1");
    else
    {
        printf("%d=", n);
        for (int i = 0; i < PrimeNum && Prime[i] <= sqr; i++)
        {
            if (n % Prime[i] != 0)
                continue;
            fac[num].x = Prime[i];
            fac[num].cnt = 0;
            while (n % Prime[i] == 0)
            {
                fac[num].cnt++;
                n /= Prime[i];
            }
            num++;
        }
        if (n != 1)
        {
            fac[num].x = n;
            fac[num].cnt = 1;
            num++;
        }
        for (int i = 0; i < num; i++)
        {
            if (i > 0)
                printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1)
                printf("^%d", fac[i].cnt);
        }
    }

    return 0;
}