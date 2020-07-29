/*
As an emergency rescue team leader of a city, you are given a special map of your country.
The map shows several scattered cities connected by some roads. 
Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. 
When there is an emergency call to you from some other city,
your job is to lead your men to the place as quickly as possible, and at the mean time, 
call up as many hands on the way as possible.
Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: 
N (≤500) - the number of cities (and the cities are numbered from 0 to N?1),
M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. 
Then M lines follow, each describes a road with three integers c1, c2 and L, 
which are the pair of cities connected by a road and the length of that road, respectively. 
It is guaranteed that there exists at least one path from C1 to C2.
Output Specification:
For each test case, print in one line two numbers: 
the number of different shortest paths between C1 and C2, 
and the maximum amount of rescue teams you can possibly gather. 
All the numbers in a line must be separated by exactly one space, 
and there is no extra space allowed at the end of a line.
Sample Input:
5 6 0 2     //四个数字：顶点数N，路径数M，救援队起始位置C1，救援队目的位置C2
1 2 1 5 3   //N个数字：分别为N顶点拥有救援人数
0 1 1       //接下来为连通的M对顶点和两个顶点之间的距离
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4        //找到不同最短路径的个数，以及在此情况下最多能集结救援队的人数
*/
#include <stdio.h>
#define inf 9999

int main()
{
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    
    int map[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j] = inf;
    for(int i=0; i<N; i++)
        scanf("%d", &map[i][i]);
    int v1, v2;
    for(int j=0; j<M; j++)
    {
        scanf("%d %d", &v1, &v2);
        scanf("%d", &map[v1][v2]);
        map[v2][v1] = map[v1][v2];
    }
    
    int path[N], dist[N], num[N], weight[N], collected[N];
    int v, w;
    for(v=0; v<N; v++)
    {
        dist[v] = inf;
        num[v] = 0;
        if(dist[v] < inf)
            path[N] = C1;
        else
            path[N] = -1;
        collected[v] = 0;
    }
    dist[C1] = 0; num[C1] = 1; weight[C1] = map[C1][C1];
    collected[C1] = 0;
    while(1)
    {
    	v = -1; int minv = inf;
        for(int j=0; j<N; j++)
        {
            if(!collected[j] && dist[j]<minv)
            {
                v = j;
                minv = dist[j];
            }
        }
        if(v == -1)
            break;
        collected[v] = 1;
        for(w=0; w<N; w++)
        {
            if(!collected[w] && map[v][w] != inf)
            {
                if(dist[v]+map[v][w] < dist[w])
                {
                    dist[w] = dist[v]+map[v][w];
                    path[w] = v;
                    num[w] = num[v];
                    weight[w] = weight[v]+map[w][w];
                }
                else if(dist[v]+map[v][w] == dist[w])
                {
                    num[w] = num[w]+num[v];
                    path[w] = v;
                    if(weight[v]+map[w][w] > weight[w])
                    weight[w] = weight[v]+map[w][w];
                }
            }
        }
    }
    
    printf("%d %d", num[C2], weight[C2]);
    
    return 0;
}