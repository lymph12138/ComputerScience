#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 30100
struct student
{
    char renum[15];
    int score;
    int LocationNumber;
    int LocalRank;
}stu[maxn];
bool cmp(student a, student b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return strcmp(a.renum,b.renum)<0;
}
int main()
{
    int N, K, num=0;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &K);
        for(int j=1;j<=K;j++)
        {
            scanf("%s %d", stu[num].renum, &stu[num].score);
            stu[num].LocationNumber=i;
            num++;
        }
        sort(stu+num-K,stu+num,cmp);
        stu[num-K].LocalRank=1;
        for(int j=num-K+1;j<=num;j++)
        {
            if(stu[j].score==stu[j-1].score)
                stu[j].LocalRank=stu[j-1].LocalRank;
            else
                stu[j].LocalRank=j-num+K+1;
        }
    }
    sort(stu,stu+num,cmp);
    printf("%d\n", num);
    int rank=1;
    printf("%s %d %d %d %d\n", stu[0].renum, rank, stu[0].LocationNumber, stu[0].LocalRank, stu[0].score);
    for(int i=1;i<num;i++)
    {
        if(stu[i].score!=stu[i-1].score)
            rank=i+1;
        printf("%s %d %d %d %d\n", stu[i].renum, rank, stu[i].LocationNumber, stu[i].LocalRank, stu[i].score);     
    }

    return 0;
}