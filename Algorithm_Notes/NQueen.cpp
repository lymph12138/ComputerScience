#include<cstdio>
#include<cmath>
#define maxn 100
int P[maxn], HashTag[maxn]={0}, count=0;
void GenerateP(int n,int index)
{
    if(index==n+1)
    {
        int flag=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(abs(i-j)==abs(P[i]-P[j]))
                    flag=0;
        if(flag)
            count++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!HashTag[i])
        {
            P[index]=i;
            HashTag[i]=1;
            GenerateP(n,index+1);
            HashTag[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    GenerateP(n,1);
    printf("%d",count);
    return 0;
}