/*
A clique is a subset of vertices of an undirected graph such that 
every two distinct vertices in the clique are adjacent.
A maximal clique is a clique that cannot be extended by including one more adjacent vertex.
(Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))
Now it is your job to judge if a given subset of vertices can form a maximal clique.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers Nv (≤ 200),
the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, 
each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.
After the graph, there is another positive integer M (≤ 100). 
Then M lines of query follow, each first gives a positive number K (≤ Nv),
then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.
Output Specification:
For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique;
or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.
Sample Input:
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
*/
#include <stdio.h>
#define max 210
int e[max][max];
int main()
{
    int nv, ne;
    scanf("%d %d", &nv, &ne);
    int a, b;
    for(int i=0; i<ne; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    int M, K;
    scanf("%d", &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d", &K);
        int v[K];
        int hash[max] = {0};
        for(int j=0; j<K; j++)
        {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        int isclique = 1;
        int ismaximal = 1;
        for(int j=0; j<K; j++)
        {
            if(isclique == 0)
                break;
            for(int l=j+1; l<K; l++)
                if(e[v[j]][v[l]] == 0)
                {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
        }
        if(isclique == 0)
            continue;
        for(int j=1; j<=nv; j++)
        {
            if(hash[j] == 0)
            {
                for(int l=0; l<K; l++)
                {
                    if(e[j][v[l]] == 0)
                        break;
                    if(l == K-1)
                        ismaximal = 0;
                }
            }
            if(ismaximal == 0)
            {
                printf("Not Maximal\n");
                break;
            }
        }
        if(ismaximal == 1)
            printf("Yes\n");
    }
    
    return 0;
}