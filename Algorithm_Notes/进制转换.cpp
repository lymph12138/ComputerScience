/*
    进制转换
    p进制数x转化为10进制y

#include <stdio.h>

int main() {
    int a, x, p, product=1, y=1;
    scanf("%d %d", &x, &p);
    a=x;
    while(a!=0)
    {
        y=y+(a%10)*product;
        a/=10;
        product=product*p;
    }
    printf("%d", y);

    return 0;
}
*/
/*
    进制转换
    将十进制数y转化为Q进制数z
*/
#include <stdio.h>
int main()
{
    int y1, y2, y, q, z[31], num=0;
    scanf("%d %d %d", &y1, &y2, &q);
    y=y1+y2;
    do
    {
        z[num++]=y%q;
        y/=q;
    } while (y!=0);
    while(num!=0)
        printf("%d", z[--num]);

    return 0;
}
