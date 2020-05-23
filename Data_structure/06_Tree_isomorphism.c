/*
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。
而图2就不是同构的。
图1                                     图2  
                           |->D                                        |->E    
 |->c|                 |->B|                    |->C|              |->C|
 |   |->G|             |   |->E|                |   |->G|          |   |->D|
 |       |->H          |       |->F             |       |->H       |       |->F
 |                    A|                        |                 A|
A|   |->E|             |->C|   |->H            A|   |->E|          |->B|   |->H
 |->B|   |->F              |->G|                |->B|   |->F           |->G|
     |->D                                           |->D
现给定两棵树，请你判断它们是否是同构的。
输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；
随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号
。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。
输入样例1（对应图1）：                     输入样例2（对应图2）：
8                                          8
A 1 2                                      B 5 7
B 3 4                                      F - -
C 5 -                                      A 0 3
D - -                                      C 6 -
E 6 -                                      H - -
G 7 -                                      D - -
F - -                                      G 4 -
H - -                                      E 1 -
8                                          8
G - 4                                      D 6 -
B 7 6                                      B 5 -
F - -                                      E - -
A 5 1                                      H - -
H - -                                      C 0 2
C 0 -                                      G - 3
D - -                                      F - -
E 2 -                                      A 1 4
输出样例1:                                 输出样例2:
Yes                                        NO
*/
#include <stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -3
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];
Tree BulidTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);
int main()
{
    Tree R1, R2;
    
    R1 = BulidTree(T1);
    R2 = BulidTree(T2);
    if(Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");
        
    return 0;
}
Tree BulidTree(struct TreeNode T[])
{
    int N;
    int cnt = 0;
    Tree Root = -3;
    scanf("%d\n", &N);
    if(N)
    {
        char cl, cr;
        for(int i=0; i<N; i++)
        {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
            T[i].Left = cl-48;
            T[i].Right = cr-48;
        }
        for(int i=0; i<N; i++)
        {
            if(T[i].Left>=0)
                cnt+=T[i].Left;
            if(T[i].Right>=0)
                cnt+=T[i].Right;  
        }
        Root = N*(N-1)/2-cnt;
    }
    return Root;
}
int Isomorphic(Tree R1, Tree R2)
{
    if(R1==Null && R2==Null)
        return 1;
    if(R1==Null&&R2!=Null || R1!=Null&&R2==Null)
        return 0;
    if(T1[R1].Element!=T2[R2].Element)
        return 0;
    if(T1[R1].Left==Null && T2[R2].Left==Null)
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    if(T1[R1].Left!=Null && T2[R2].Left!=Null && 
        T1[T1[R1].Left].Element==T2[T2[R2].Left].Element)
        return Isomorphic(T1[R1].Left, T2[R2].Left) && 
               Isomorphic(T1[R1].Right, T2[R2].Right);
    else
        return Isomorphic(T1[R1].Left, T2[R2].Right) &&
               Isomorphic(T1[R1].Right, T2[R2].Left);
}