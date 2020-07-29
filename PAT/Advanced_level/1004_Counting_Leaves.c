/*
A family hierarchy is usually presented by a pedigree tree.
Your job is to count those family members who have no child.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 0<N<100, 
the number of nodes in a tree, and M (<N), the number of non-leaf nodes. Then M lines follow, 
each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, 
K is the number of its children, followed by a sequence of two-digit ID's of its children. 
For the sake of simplicity, let us fix the root ID to be 01.
The input ends with N being 0. That case must NOT be processed.
Output Specification:
For each test case, you are supposed to count those family members 
who have no child for every seniority level starting from the root. 
The numbers must be printed in a line, separated by a space, 
and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. 
Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. 
Then we should output 0 1 in a line.
Sample Input:
2 1           //两个数字：N族谱的结点数，M非叶结点的结点数
01 1 02       //M行输入：ID 非叶结点的结点，K 此结点的孩子个数，。。 根结点的ID为01
Sample Output:
0 1           //输出每一层结点中叶结点的数量
*/
#include<stdio.h>

int main()
{
    int N, M, ID, CID, K;
    scanf("%d %d", &N, &M);
    
    int map[N][N], judge[N];
    for(int i=0; i<N; i++)
        judge[i] = -1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j] = -1;
    map[0][0] = 0;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &ID, &K);
        for(int j=0; j<K; j++)
        {
            scanf("%d", &CID);
            map[ID-1][CID-1] = 1;
        }
        judge[ID-1] = 1;
    }
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[j][i] == 1)
            {
                map[i][i] = map[j][j]+1;
                break;
            }
        }
    }
    
    int levelmax = 0;
    int count = 0;
    for(int i=0; i<N; i++)
        if(map[i][i] > levelmax)
            levelmax = map[i][i];
    if(judge[0] == -1)
        printf("%d", 1);
    else
        printf("%d", 0);        
    for(int i=1; i<=levelmax; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(judge[j]==-1 && map[j][j]==i)
                count++;
        }
        printf(" %d", count);
        count = 0;
    }
    
    return 0;
}