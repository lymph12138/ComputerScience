/*
Suppose that all the keys in a binary tree are distinct positive integers.
Given the postorder and inorder traversal sequences, 
you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. 
For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. 
The second line gives the postorder sequence and the third line gives the inorder sequence. 
All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree.
All the numbers in a line must be separated by exactly one space, 
and there must be no extra space at the end of the line.
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
#include <stdio.h>
#include <math.h>
#define max 30
int post[max], in[max], map[max];
void pre(int root, int start, int end, int index)
{
    if(start > end)
        return ;
    int i;
    for(i=start; i<end; i++)
        if(in[i] == post[root])
            break;
    map[index] = post[root];
    pre(root-1-end+i, start, i-1, 2*index+1);
    pre(root-1, i+1, end, 2*index+2);
}
int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &post[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &in[i]);
    pre(N-1, 0, N-1, 0);
    int n = 0;
    int j = 0;
    if(N==0)
        printf("0");
    while(n<N && N!=0)
    {
        if(map[j] != 0)
        {
            printf("%d%s",map[j], n==N-1?"":" ");
            n++;
        }
        j++;
    }
        
    return 0;
}

#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int>post, in;
map<int, int>level;
void pre(int root, int start, int end, int index)
{
    if(start > end)
        return ;
    int i;
    for(i=start; i<end; i++)
        if(in[i] == post[root])
            break;
    level[index] = post[root];
    pre(root-1-end+i, start, i-1, 2*index+1);
    pre(root-1, i+1, end, 2*index+2);
}
int main()
{
    int N;
    scanf("%d", &N);
    post.resize(N);
    in.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &post[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &in[i]);
    pre(N-1, 0, N-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end())
        printf(" %d", it->second);
        
    return 0;
}