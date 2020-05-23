树的一些基本术语：
1.结点的度(Degree)：结点的子树个数
2.树的度：树的所有结点最大的度数
3.叶结点(Leaf)：度为0的结点
4.父结点(Parent)：有子树的结点是其子树的根结点的父结点
5.子结点(Child)：若A是B的父结点，则称B结点是A的子结点
6.兄弟结点(Sibling)：具有同一父结点的各个结点彼此是兄弟结点
7.路径：从结点N1到Nk的路径为一个结点序列N1，N2，……，Nk，
8.路径长度：Ni是Ni+1的父结点。路径所包含边的个数为路径的长度
9.祖先结点(Ancenstor)：沿树根到某一结点的路径上的所有结点都是这个结点的祖先结点
10.子孙结点(Descendant)：某一结点的子树中的所有结点是这个结点的子孙结点
11.结点层次(Level)：规定根结点在1层，其他任意结点的层数是其父结点的层数加1
12.树的深度(Depth)：树中所有结点中的最大层次是这棵树的深度

二叉树T：可以为空，若不为空，则他由根结点和称为其左子树TL与右子树TR的两个不相交的二叉树组成，有左右之分

斜二叉树(Skewed Binary Tree)：单边二叉树
完美二叉树(Perfect Binary Tree)，满二叉树(Full Binary Tree)                               1
完全二叉树(Complete Binary Tree)：                                                   2          3   
    有n个结点的二叉树，对树中结点按从上到下、从左到右进行编号，编号为i(0<i<n+1)   4    5     6     7
    结点与满二叉树中编号为i结点在二叉树中位置相同                                8 9 10 11 12 13 14 15
对任何非空二叉树T，若n0表示叶结点的个数、n2是度为2的非叶结点个数，那么两者满足关系：n0 = n2+1

二叉树(Binary Tree)：有穷的结点集合

1, Boolean IsEmpty(BinTree BT)：判断BT是否为空
2, void Traversal(Binary BT)：遍历，按某种顺序访问每个结点
3, BinTree CreatBinTree()：创建一个二叉树

常用遍历方法：
void PreOrderTraversal(BinTree BT)：  先序遍历---根、左子树、右子树
void InOrderTraversal(BinTree BT)：   中序遍历---左子树、根、右子树
void PostOrderTraversal(BinTree BT)： 后序遍历---左子树、右子树、根
void LevelOrderTraversal(BinTree BT)：层次遍历---从上到下、从左到右

链表存储：

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}

二叉树的四种遍历：

1.先序遍历：访问根结点->先序遍历其左子树->先序遍历其右子树
void PreOrderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
2.中序遍历：中序遍历其左子树->访问根结点->中序遍历其右子树
void InOrderTraversal(BinTree BT)
{
    if(BT)
    {
        InOrderTraversal(BT->Left);
        printf("%d", BT->Data);
        InOrderTraversal(BT->Right);
    }
}
3.后序遍历：后序遍历其左子树->后序遍历其右子树->访问根结点
void PostOrderTraversal(BinTree BT)
{
    if(BT)
    {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}
4.层序遍历：

非递归遍历算法(中序遍历)：
void InOrderTraversal(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S))
    {
        while(T)
        {
            Push(T, S);
            T = T->Left;
        }
        if(!IsEmpty(S))
        {
            T = Pop(S);
            printf("%5d", T->Data);
            T = T->Right;
        }
    }
}

非递归遍历算法(层序遍历)：
void LevelOrderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT)
        return;
    Q = CreatQueue(MaxSize);
    AddQ(Q, BT);
    while(!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        printf("%d\n", T->Data);
        if(T->Left)
            AddQ(Q, T->Left);
        if(T->Right)
            AddQ(Q, T->Right);
    }
}