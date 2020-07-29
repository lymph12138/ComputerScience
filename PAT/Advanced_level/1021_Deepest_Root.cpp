/*
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root.
Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤10^4)
which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, 
each describes an edge by given the two adjacent nodes' numbers.
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, 
print them in increasing order of their numbers. In case that the given graph is not a tree,
print Error: K components where K is the number of connected components in the graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/ 
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define Nmax 10010
int N = 0;
int Maxheight = 0;
vector <vector<int>> v;
bool visited[Nmax];
vector <int> tmp;
set <int> s;
void DFS(int node, int height)
{
    if(height > Maxheight)
    {
        tmp.clear();
        tmp.push_back(node);
        Maxheight = height;
    }
    else if(height == Maxheight)
        tmp.push_back(node);
    visited[node] = true;
    for(int i=0; i<v[node].size(); i++)
        if(visited[v[node][i]] == false)
            DFS(v[node][i], height+1);
}
int main()
{
    scanf("%d", &N);
    v.resize(N+1);
    int v1, v2;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d %d", &v1, &v2);
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    int s1;
    int count = 0;
    for(int i=1; i<=N; i++)
    {
        if(visited[i] == false)
        {
            DFS(i, 1);
            if(i == 1)
            {
                if(tmp.size()!=0)
                    s1 = tmp[0];
                for(int j=0; j<tmp.size(); j++)
                    s.insert(tmp[j]);
            }
            count++;
        }
    }
    if(count > 1)
        printf("Error: %d components", count);
    else
    {
        tmp.clear();
        Maxheight = 0;
        fill(visited, visited+10010, false);
        DFS(s1, 1);
        for(int i=0; i<tmp.size(); i++)
            s.insert(tmp[i]);
        auto it = s.begin();
        for(; it!=s.end(); it++)
            printf("%d\n", *it);
    }
    
    return 0;
}
