/*
A traveler's map gives the distances between cities along the highways, together with the cost of each highway.
Now you are supposed to write a program to help a traveler to decide the shortest path 
between his/her starting city and the destination. If such a shortest path is not unique,
you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, 
where N (≤500) is the number of cities (and hence the cities are numbered from 0 to N−1);
M is the number of highways; S and D are the starting and the destination cities, respectively.
Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
Output Specification:
For each test case, print in one line the cities along the shortest path from 
the starting point to the destination, followed by the total distance and the total cost of the path. 
The numbers must be separated by a space and there must be no extra space at the end of output.
Sample Input:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output:
0 2 3 3 40
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 999999999
#define Nmax 510
int n, m, s, d;
int e[Nmax][Nmax], cost[Nmax][Nmax], dist[Nmax], visited[Nmax];
vector <int> pre[510], path, tmppath;
int mincost = inf;
void DFS(int v)
{
    tmppath.push_back(v);
    if(v == s)
    {
        int tmpcost = 0;
        for(int i=tmppath.size()-1; i>0; i--)
        {
            int id = tmppath[i];
            int nextid = tmppath[i-1];
            tmpcost += cost[id][nextid];
        }
        if(tmpcost < mincost)
        {
            mincost = tmpcost;
            path = tmppath;
        }
        tmppath.pop_back();
        return ;
    }
    for(int i=0; i<pre[v].size(); i++)
        DFS(pre[v][i]);
    tmppath.pop_back();
}
int main()
{
    fill(e[0], e[0]+Nmax*Nmax, inf);
    fill(dist, dist+Nmax, inf);
    fill(visited, visited+Nmax, 0);
    scanf("%d %d %d %d", &n, &m, &s, &d);
    int v1, v2, a, b;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d %d", &v1, &v2, &a, &b);
        e[v1][v2] = a;
        e[v2][v1] = a;
        cost[v1][v2] = b;
        cost[v2][v1] = b;
    }
    pre[s].push_back(s);
    dist[s] = 0;
    for(int i=0; i<n; i++)
    {
        int u = -1;
        int min = inf;
        for(int j=0; j<n; j++)
            if(dist[j]<min && visited[j]==0)
            {
                min = dist[j];
                u = j;
            }
        if(u == -1)
            break;
        visited[u] = 1;
        for(int v=0; v<n; v++)
        {
            if(visited[v]==0 && e[u][v]<inf && dist[u]+e[u][v]<dist[v])
            {
                dist[v] = dist[u]+e[u][v]; 
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(visited[v]==0 && e[u][v]<inf && dist[u]+e[u][v]==dist[v])
                pre[v].push_back(u);
        }
    }
    DFS(d);

    for(int i=path.size()-1; i>=0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dist[d], mincost);
    
    return 0;
}