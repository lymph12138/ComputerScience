/*
It is vitally important to have all the cities connected by highways in a war. 
If a city is occupied by the enemy, all the highways from/toward that city are closed.
We must know immediately if we need to repair any other highways to keep the rest of the cities connected. 
Given the map of cities which have all the remaining highways marked, 
you are supposed to tell the number of highways need to be repaired, quickly.
For example, if we have 3 cities and 2 highways connecting city1 -city2 and city1 -city3.
Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2 -city3.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K,
which are the total number of cities, the number of remaining highways, 
and the number of cities to be checked, respectively. Then M lines follow, 
each describes a highway by 2 integers, which are the numbers of the cities the highway connects. 
The cities are numbered from 1 to N. Finally there is a line containing K numbers,
which represent the cities we concern.
Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/
#include <stdio.h>

#define max 1000
int Graph[max][max];

void DFS(int map[][max], int vis[], int v)
{
    vis[v] = 1;
    for(int i=1; i<max; i++)
        if(map[v][i] && !vis[i])
            DFS(map, vis, i);
}


int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=0; i<max; i++)
        for(int j=0; j<max; j++)
            Graph[i][j] = 0;
            
    int city1, city2;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &city1, &city2);
        Graph[city1][city2] = 1;
        Graph[city2][city1] = 1;
    }
    
    int number, vis[N+1];
    for(int i=0; i<K; i++)
    {
    	int lost;
    	scanf("%d", &lost);
        number = 0;
        for(int i=0; i<N+1; i++)
            vis[i] = 0;
        vis[lost] = 1;
        for(int j=1; j<=N; j++)
        {
            if(vis[j])
                continue;
            else
                number++;
            DFS(Graph, vis, j);
        }
        printf("%d\n", number-1);
    }
    
    return 0;
}