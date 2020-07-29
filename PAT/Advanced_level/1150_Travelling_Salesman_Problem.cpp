/*
The "travelling salesman problem" asks the following question:
"Given a list of cities and the distances between each pair of cities,
what is the shortest possible route that visits each city and returns to the origin city?" 
It is an NP-hard problem in combinatorial optimization,
important in operations research and theoretical computer science.
(Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)
In this problem, you are supposed to find, from a given list of cycles, 
the one that is the closest to the solution of a travelling salesman problem.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200),
the number of cities, and M, the number of edges in an undirected graph.
Then M lines follow, each describes an edge in the format City1 City2 Dist,
where the cities are numbered from 1 to N and the distance Dist is positive and is no more than 100.
The next line gives a positive integer K which is the number of paths, followed by K lines of paths, 
each in the format:     n C1 C2 ... Cn
where n is the number of cities in the list, and Ci's are the cities on a path.
Output Specification:
For each path, print in a line Path X: 
TotalDist (Description) where X is the index (starting from 1) of that path, 
TotalDist its total distance (if this distance does not exist, output NA instead),
and Description is one of the following:
TS simple cycle if it is a simple cycle that visits every city;
TS cycle if it is a cycle that visits every city, but not a simple cycle;
Not a TS cycle if it is NOT a cycle that visits every city.
Finally print in a line Shortest Dist(X) = TotalDist where X is the index of the cycle 
that is the closest to the solution of a travelling salesman problem, and TotalDist is its total distance. 
It is guaranteed that such a solution is unique.
Sample Input:
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6
Sample Output:
Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8
*/ 
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
#define max 210
#define inf 100*max
int n, m, ansid;
int anstotal = inf;
int e[max][max] = {0};
void check(int id)
{
    int total = 0;
    int number;
    int flag = 1;
    cin >> number;
    set <int> s;
    vector <int> v(number);
    for(int i=0; i<number; i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    for(int i=1; i<number; i++)
    {
        if(e[v[i]][v[i-1]] == 0)
            flag = 0;
        total += e[v[i]][v[i-1]];
    }
    if(flag == 0)
        printf("Path %d: NA (Not a TS cycle)\n", id);
    else if(v[0]!=v[number-1] || s.size()!=n)
        printf("Path %d: %d (Not a TS cycle)\n", id, total);
    else if(number != n+1)
    {
        printf("Path %d: %d (TS cycle)\n", id, total);
        if(total < anstotal)
        {
            ansid = id;
            anstotal = total;
        }
    }
    else
    {
        printf("Path %d: %d (TS simple cycle)\n", id, total);
        if(total < anstotal)
        {
            ansid = id;
            anstotal = total;
        }
    }
}
int main()
{
    int v1, v2, d, k;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> v1 >> v2 >> d;
        e[v1][v2] = d;
        e[v2][v1] = d;
    }
    cin >> k;
    for(int i=1; i<=k; i++)
        check(i);
    printf("Shortest Dist(%d) = %d", ansid, anstotal);
    
    return 0;
}