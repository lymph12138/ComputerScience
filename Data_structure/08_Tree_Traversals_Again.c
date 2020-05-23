/*
An inorder binary tree traversal can be implemented in a non-recursive way with a stack.
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, 
the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4);
pop(); pop(); push(5); push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.
         |->5|
         |   |->6
        1|
         |   |->4
         |->2|
             |->3
Figure 1
Input Specification:
Each input file contains one test case. 
For each case, the first line contains a positive integer N (≤30) which is the 
total number of nodes in a tree (and hence the nodes are numbered from 1 to N). 
Then 2N lines follow, each describes a stack operation in the format: "Push X" 
where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line.
A solution is guaranteed to exist. All the numbers must be separated by exactly one space, 
and there must be no extra space at the end of the line.
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/
#include <stdio.h>
#define MaxSize 30
int PreOrder[MaxSize];
int InOrder[MaxSize];
int PostOrder[MaxSize];
int len = 0;
void BulidOrder(int N);
void Post(int preL, int preR, int inL, int inR);
int main()
{
    int N;
    
    scanf("%d", &N);
    BulidOrder(N);
    Post(0, N-1, 0, N-1);
    for(int i=0; i<N; i++)
		printf("%d%c", PostOrder[i], i<N-1 ? ' ': '\n'); 
    
    return 0;
}
void BulidOrder(int N)
{
    char s[7];
    int stack[N];
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    for(int i=0; i<2*N; i++)
    {
    	int num;
        scanf("%s", s);
        if(s[1] == 'u')
        {
        	scanf("%d", &num);
            PreOrder[n1] = num;
            n1++;
            stack[n2] = num;
            n2++;
        }
        else
        {
            InOrder[n3] = stack[n2-1];
            n3++;
            n2--;
        }
    }
}
void Post(int preL, int preR, int inL, int inR)
{
	int k;
	if(preL>preR)
		return;
	for(k=inL; k<=inR; k++)
		if(InOrder[k]==PreOrder[preL])
			break;//找到中序遍历序列中对应的根结点 
	Post(preL+1, preL+k-inL, inL, k-1);
	Post(preL+k-inL+1, preR, k+1, inR);
	PostOrder[len++]=PreOrder[preL]; 
}