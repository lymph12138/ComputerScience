#include <cstdio>
#define maxn 20
int p[maxn], HashTable[maxn]={false};
void generate(int index, int n)
{
    if(index==n+1)
    {
        for(int i=1;i<n+1;i++)
            printf("%d ", p[i]);
        printf("\n");
        return ;
    }
    for(int x=1;x<=n;x++)
    {
        if(!HashTable[x])
        {
            p[index]=x;
            HashTable[x]=true;
            generate(index+1,n);
            HashTable[x]=false;
        }
    }
}
int main()
{
    generate(1,3);

    return 0;
}