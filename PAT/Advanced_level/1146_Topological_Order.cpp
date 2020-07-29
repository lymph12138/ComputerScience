/*
This is a problem given in the Graduate Entrance Exam in 2018:
Which of the following is NOT a topological order obtained from the given directed graph? 
Now you are supposed to write a program to test each of the options.
gre.jpg
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers 
N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges.
Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N.
After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, 
each gives a permutation of all the vertices. All the numbers in a line are separated by a space.
Output Specification:
Print in a line all the indices of queries which correspond to "NOT a topological order". 
The indices start from zero. All the numbers are separated by a space, 
and there must no extra space at the beginning or the end of the line. 
It is graranteed that there is at least one answer.
Sample Input:
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
Sample Output:
3 4
*/ 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    vector <int> v[1010];
    int in[1010] = {0};
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }
    int K;
    int flag = 0;
    scanf("%d", &K);
    for(int i=0; i<K; i++)
    {
        int judge = 1;
        vector <int> tin(in, in+N+1);
        for(int j=0; j<N; j++)
        {
            scanf("%d", &a);
            if(tin[a] != 0)
                judge = 0;
            for(int l=0; l<v[a].size(); l++)
                tin[v[a][l]]--;
        }
        if(judge == 1)
            continue;
        printf("%s%d", flag==0?"":" ", i);
        flag = 1;
    }
    
    return 0;
}