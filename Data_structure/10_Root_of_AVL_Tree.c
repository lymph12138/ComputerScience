/*
An AVL tree is a self-balancing binary search tree. 
In an AVL tree, the heights of the two child subtrees of any node differ by at most one; 
if at any time they differ by more than one, rebalancing is done to restore this property.
Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. 
Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the root of the resulting AVL tree in one line.
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
#include <stdio.h>
typedef struct AVLNode *AVLTree;
typedef struct AVLNode
{
    int Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T, int X);
int max(int a, int b);
int GetHeight(AVLTree T);

int main()
{
    int N, number;
    scanf("%d", &N);
    AVLTree T = NULL;
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &number);
        T = Insert(T, number);
    }
    printf("%d", T->Data);
    
    return 0;
}
int max(int a, int b)
{
    return a>b ? a : b;
}
int GetHeight(AVLTree T)
{
    if(!T)
        return 0;
    else
        return max(GetHeight(T->Left), GetHeight(T->Right))+1;
}
待续：