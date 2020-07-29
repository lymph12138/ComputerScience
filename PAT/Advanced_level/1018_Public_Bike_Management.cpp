/*
There is a public bike service in Hangzhou City which provides great convenience to the tourists 
from all over the world. One may rent a bike at any station and return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. 
A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty,
PBMC will collect or send bikes to adjust the condition of that station to perfect. 
And more, all the stations on the way will be adjusted as well.
When a problem station is reported, PBMC will always choose the shortest path to reach that station. 
If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
                    PBMC
                    (-)
                  1/ | \1
              s1(6) 3|  (7)s2
                  1\ | /1
                    (0)s3
The above figure illustrates an example. The stations are represented by vertices 
and the roads correspond to the edges.
The number on an edge is the time taken to reach one end station from another.
The number written inside a vertex S is the current number of bikes stored at S. 
Given that the maximum capacity of each station is 10. 
To solve the problem at S3,we have 2 different shortest paths:
1.PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC,
    because we can collect 1 bike from S1 and then take 5 bikes to S3,
    so that both stations will be in perfect conditions.
2.PBMC -> S2 -> S3. This path requires the same time as path 1, 
    but only 3 bikes sent from PBMC and hence is the one that will be chosen.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers:
Cmax(≤100), always an even number, is the maximum capacity of each station;
N (≤500), the total number of stations; 
Sp, the index of the problem station (the stations are numbered from 1 to N, 
and PBMC is represented by the vertex 0); 
and M, the number of roads. The second line contains N non-negative numbers Ci(i=1,?,N) 
where each Ci is the current number of bikes at Si respectively. 
Then M lines follow, each contains 3 numbers: Si, Sj, and Tij 
which describe the time Tij taken to move betwen stations Si and Sj.
All the numbers in a line are separated by a space.
Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send.
Then after one space, output the path in the format: 0?>S1?>??>Sp. 
Finally after another space, output the number of bikes that we must take back to PBMC 
after the condition of Sp is adjusted to perfect.
Note that if such a path is not unique, output the one that requires minimum number of bikes 
that we must take back to PBMC. The judge's data guarantee that such a path is unique.
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
#define Nmax 510
int Cmax, N, Sp, M;
int weight[Nmax], Graph[Nmax][Nmax];
#define inf 999
int dist[Nmax], visit[Nmax];
vector <int> pathLast[Nmax];
vector <int> path, currentpath;
int sent = inf;
int collect = inf;
void Dijkstra()
{
    while(visit[Sp] == 0)
    {
        int v=-1;
        int min = inf;
        for(int i=0; i<=N; i++)
            if(visit[i]==0 && dist[i]<min)
            {
                min = dist[i];
                v = i;
            }
        visit[v] = 1;
        for(int i=0; i<=N; i++)
            if(Graph[v][i]!=0 && visit[i]==0 && dist[v]+Graph[v][i]<dist[i])
            {
                dist[i] = dist[v]+Graph[v][i];
                pathLast[i].clear();
                pathLast[i].push_back(v);
            }
            else if(Graph[v][i]!=0 && dist[v]+Graph[v][i]==dist[i])
                pathLast[i].push_back(v);
    }
}
void DFS(int v)
{
    if(v == 0)
    {
        int currentsent = 0;
        int currentcollect = 0;
        for(int i=currentpath.size()-1; i>=0; i--)
        {
            if(weight[currentpath[i]] >=0 )
                currentcollect += weight[currentpath[i]];
            else
            {
                if(currentcollect > abs(weight[currentpath[i]]))
                    currentcollect += weight[currentpath[i]];
                else 
                {
                    currentsent += abs(weight[currentpath[i]])-currentcollect; 
                    currentcollect = 0;
                }
            }
        }
        currentpath.push_back(v);
        if(currentsent < sent)
        {
            sent = currentsent;
            collect = currentcollect;
            path = currentpath;
        }
        else if(currentsent==sent && currentcollect<collect)
        {
            collect = currentcollect;
            path = currentpath;
        }
        currentpath.pop_back();
    }
    currentpath.push_back(v);
    for(int i=0; i<pathLast[v].size(); i++)
        DFS(pathLast[v][i]);
    currentpath.pop_back();
}
int main()
{
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &weight[i]);
        weight[i] -= Cmax/2; 
        dist[i] = inf;
    }
    for(int i=0; i<Nmax; i++)
        for(int j=0; j<Nmax; j++)
        {
            Graph[i][j] = 0;
            Graph[j][i] = 0;
        }
    int v1, v2, e;
    for(int i=0; i<M; i++)
    {
        scanf("%d %d %d", &v1, &v2, &e);
        Graph[v1][v2] = e;
        Graph[v2][v1] = e;
    }
    dist[0] = 0;
    Dijkstra();
    DFS(Sp);
    
    printf("%d ", sent);
    for(int i=path.size()-1; i>=0; i--)
        printf("%d%s",  path[i], i==0?"":"->");
    printf(" %d", collect);
    
    return 0;
}