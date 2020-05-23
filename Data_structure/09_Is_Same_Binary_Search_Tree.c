/*
给定一个插入序列就可以唯一确定一棵二叉搜索树。
然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列
{2, 1, 3}和{2, 3,1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，
你需要判断它们是否能生成一样的二叉搜索树。
输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。
第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。
输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No
*/
#include <stdio.h>
typedef struct TreeNode *Tree;
struct TreeNode
{
    int Data;
    Tree Left;
    Tree Right;
    int flag;
};

int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);
Tree Insert(Tree T, int v);
Tree NewNode(int v);
Tree MakeTree(int N);
int check(Tree T, int v);

int main()
{
    int N, L;
    Tree T;
    
    scanf("%d", &N);
    while(N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for(int i=0; i<L; i++)
        {
            if(Judge(T, N))
                printf("Yes\n");
            else
                printf("No\n");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    
    return 0;
}
void ResetT(Tree T)
{
    if(T->Left)
        ResetT(T->Left);
    if(T->Right)
        ResetT(T->Right);
    T->flag = 0;
}
void FreeTree(Tree T)
{
    if(T->Left)
        FreeTree(T->Left);
    if(T->Right)
        FreeTree(T->Right);
    free(T);
}
Tree NewNode(int v)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->Data = v;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}
Tree Insert(Tree T, int v)
{
    if(!T)
        T = NewNode(v);
        else
        {
            if(v > T->Data)
                T->Right = Insert(T->Right, v);
            else 
                T->Left = Insert(T->Left, v);
        }
        return T;
}
Tree MakeTree(int N)
{
    Tree T;
    int v;
    scanf("%d", &v);
    T = NewNode(v);
    for(int i=1; i<N; i++)
    {
        scanf("%d", &v);
        T = Insert(T, v);
    }
    return T;
}
int check(Tree T, int v)
{
    if(T->flag)
    {
        if(v < T->Data)
            return check(T->Left, v);
        else if(v > T->Data)
            return check(T->Right, v);
        else
            return 0;
    }
    else
    {
        if(v == T->Data)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}
int Judge(Tree T, int N)
{
    int v;
    int mark = 0;
    scanf("%d", &v);
    if(v != T->Data)
        mark = 1;
    else
        T->flag = 1;
    for(int i=1; i<N; i++)
    {
        scanf("%d", &v);
        if(!mark && !check(T, v))
            mark = 1;
    }
    if(mark)
        return 0;
    else 
        return 1;
}

