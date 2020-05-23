/*
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.
Input Specification:
Each input file contains one test case. For each case, 
the first line gives a positive integer N (≤10) 
which is the total number of nodes in the tree -- 
and hence the nodes are numbered from 0 to N?1. 
Then N lines follow, each corresponds to a node,
and gives the indices of the left and right children of the node. 
If the child does not exist, a "-" will be put at the position.
Any pair of children are separated by a space.
Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. 
There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
Sample Input:
8
1 -    
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5
思路：层序遍历，输出叶结点
*/
#include<stdio.h>
#define MaxSize 10
#define Tree int
#define Null -3
struct TreeNode
{
	Tree Left;
	Tree Right;
}T[MaxSize];
Tree BuildTree(struct TreeNode T[])
{
	int N,i,Root=Null;
	char cl,cr;
	scanf("%d",&N);
    int check[MaxSize];
	if(N)
	{
		for(i=0;i<N;i++) check[i]=0;
		for(i=0;i<N;i++)
		{
			scanf("\n%c %c",&cl,&cr);
			if(cl!='-')
			{
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else
				T[i].Left=Null;
			if(cr!='-')
			{
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			else
				T[i].Right=Null;
		}
		for(i=0;i<N;i++)
			if(!check[i]) break;
		Root=i;
	}
	return Root;
}
void PrintfLeaves(Tree R)
{
	int i=0,Tmp,judge=0;
	int Queue[10]={0},Front=-1,Rear=-1;
	if(R==Null)
		return;
	else
	{
		Queue[0]=R;
		Rear++;
		if(T[R].Left==Null&&T[R].Right==Null)
			printf("%d",R);
		else
		{
			while(Front!=Rear)
			{
				Tmp=Queue[Front+1];
				Queue[Front+1]=0;
				Front++;
				if(T[Tmp].Left!=Null)
				{
					Rear++;
					Queue[Rear]=T[Tmp].Left;

				}
				if(T[Tmp].Right!=Null)
				{
					Rear++;
					Queue[Rear]=T[Tmp].Right;
				}
				if(T[Tmp].Left==Null&&T[Tmp].Right==Null)
				{
					if(judge == 1)
    					printf(" ");
    				printf("%d", Tmp);
    				judge = 1;
				}

			}
		}

	}
}
int main()
{
	Tree R;
	R=BuildTree(T);
	PrintfLeaves(R);
	return 0;
}