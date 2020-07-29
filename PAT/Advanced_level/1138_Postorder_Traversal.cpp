/*
Suppose that all the keys in a binary tree are distinct positive integers.
Given the preorder and inorder traversal sequences, 
you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), 
the total number of nodes in the binary tree.
The second line gives the preorder sequence and the third line gives the inorder sequence.
All the numbers in a line are separated by a space.
Output Specification:
For each test case,
print in one line the first number of the postorder traversal sequence of the corresponding binary tree.
Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
*/ 
#include <stdio.h>
#define max 50010
int pre[max], in[max], post[max];
int cnt = 0;
void getpost(int root, int left, int right)
{
    if(left > right)
        return ;
    int i;
    for(i=left; i<right; i++)
        if(in[i] == pre[root])
            break;
    getpost(root+1, left, i-1);
    getpost(root+1-left+i, i+1, right);
    post[cnt++] = pre[root];
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &pre[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &in[i]);
    getpost(0, 0, N-1);
    printf("%d", post[0]);
    
    return 0;
}