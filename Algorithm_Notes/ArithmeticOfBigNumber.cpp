#include<stdio.h>
#include<algorithm>
#include<string.h>
struct bign
{
    int d[1000];
    int len;
    int flag;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
        flag=1;
    }
};
void print(bign a)
{
    if(a.flag==0)
        printf("-");
    for(int i=a.len-1;i>=0;i--)
        printf("%d",a.d[i]);
    return;
}
bign change(char str[])
{
    bign a;
    if(str[0]=='-')
    {
        a.len=strlen(str)-1;
        a.flag=0;
    }
    else
        a.len=strlen(str);
    for(int i=0;i<a.len;i++)
        a.d[i]=str[a.len-i-1]-'0';
    return a;
}
int compare(bign a,bign b)
{
    if(a.len>b.len)
        return 1;
    else if(a.len<b.len)
        return -1;
    else
    {
        for(int i=a.len-1;i>=0;i--)
        {
            if(a.d[i]==b.d[i])
                continue;
            else if(a.d[i]<b.d[i])
                return -1;
            else if(a.d[i]>b.d[i])
                return 1;
        }
    }  
    return 0;
}
bign add(bign a,bign b)
{
    bign c;
    int carry=0;
    for(int i=0;i<a.len||i<b.len;i++)
    {
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)
        c.d[c.len++]=carry;
    return c;
}
bign sub(bign a,bign b)
{
    bign c;
    for(int i=0;i<a.len||i<b.len;i++)
    {
        if(a.d[i]<b.d[i])
        {
            c.d[c.len++]=a.d[i]+10-b.d[i];
            a.d[i+1]-=1;
        }
        else
            c.d[c.len++]=a.d[i]-b.d[i];    
    }
    while(c.len>=0&&c.d[c.len-1]==0)
        c.len--;
    return c;
}
bign multi1(bign a, int b)
{
    bign c;
    int carry=0;
    for(int i=0;i<a.len;i++)
    {
        int temp=a.d[i]*b+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    while(carry!=0)
    {
        c.d[c.len++]=carry%10;
        carry/=10;
    }
    while(c.len>=0&&c.d[c.len-1]==0)
        c.len--;
    return c;
}
bign multi2(bign a,bign b)
{
    bign c;
    c.len=a.len+b.len;
    int carry,i,j,temp;
    for(i=0;i<b.len;i++)
    {
        carry=0;
        for(j=0;j<a.len;j++)
        {
            temp=b.d[i]*a.d[j]+carry+c.d[i+j];
            c.d[i+j]=temp%10;
            carry=temp/10;
        }
        if(carry!=0)
            c.d[i+j]=c.d[i+j]+carry;
    }
    while(c.len>=0&&c.d[c.len-1]==0)
        c.len--;

    return c;
}
bign div1(bign a,int b,int &r)
{
    bign c;
    c.len=a.len;
    for(int i=a.len-1;i>=0;i--)
    {
        r=r*10+a.d[i];
        if(r>=b)
        {
            c.d[i]=r/b;
            r=r%b;
        }
        else
            c.d[i]=0;    
    }
    while(c.len>=0&&c.d[c.len-1]==0)
        c.len--;
    return c;
}
bign div2(bign a,bign b, bign &r)
{
    bign c;
    c.len=a.len;
    bign temp;
    temp.len=a.len;
    temp.d[a.len-b.len]=1;
    temp=multi2(b,temp);
    r=a;
    int e=0;
    for(int i=0;i<=a.len-b.len&&compare(temp,b)!=-1;i++)
    {
        while(compare(r,temp)!=-1)
        {
            r=sub(r,temp);
            c.d[a.len-b.len-i]++;
        }
        temp=div1(temp,10,e);
    }
    while(c.len>=0&&c.d[c.len-1]==0)
        c.len--;
    while(r.len>=0&&r.d[r.len-1]==0)
        r.len--;
    return c;
}
int main()
{
    char str1[10],str2[10];
    scanf("%s%s",str1,str2);
    bign a=change(str1);
    bign b=change(str2);
    bign r;
    bign c=div2(a,b,r);
    print(c);printf("\n");
    print(r);printf("\n");

    return 0;
}