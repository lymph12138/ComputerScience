二叉搜索树：(Binary Search Tree)二叉排序树或二叉查找树(可以为空)
1.非空左子树的所有键值小于其根结点的键值
2.非空右子树的所有键值大于其根结点的键值
3.左、右子树都是二叉搜索树

二叉搜索树操作的特别函数：
1.Position Find(ElementType X, BinTree BST)：从二叉搜索树BST中查找元素X，并返回其所在结点的地址
2.Position FindMin(BinTree BST)：从二叉搜索树BST中查找并返回最小元素所在结点的地址
3.Position FindMax(BinTree BST)：从二叉搜索树BST中查找并返回最大元素所在结点的地址
4.BinTree Insert(ElementType X, BinTree BST)：把元素X插入到二叉搜索树BST中，并返回根结点
5.BinTree Delete(ElementType X, BinTree BST)：将元素X从二叉搜索树BST中删除，并返回根结点

1.查找元素X
Position Find(ElementType X, BinTree BST)
{
    while(BST)
    {
        if(X > BST->Data)
            BST = BST->Right;
        else if(X < BST->Data)
            BST = BST->Left;
        else
            return BST;
    }
    return NULL;
}
2.查找最小元素
Position FindMin(BinTree BST)
{
    while(BST)
    {
        while(BST->Left)
            BST = BST->Left;
        return BST;
    }
    return NULL;
}
3.查找最大元素
Position FindMax(BinTree BST)
{
    while(BST)
    {
        while(BST->Right)
            BST = BST->Right;
        return BST;
    }
    return NULL;
}
4.插入元素X
BinTree Insert(ElementType X, BinTree BST)
{
    if(!BST)
    {
        BST = malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
        if(X < BST->Data)
            BST->Left = Insert(X, BST->Left);
        else if(X > BST->Data)
            BST->Right = Insert(X, BST->Right);
    return BST;
}
4.删除元素X
BinTree Delete(ElementType X, BinTree BST)
{
    Position Tmp;
    if(!BST) printf("要删除的元素未找到");
    else if(X < BST->Data)
        BST->Left = Delete(X, BST->Left);
    else if(X > BST->Data)
        BST->Right = Delete(X, BST->Right);
    else
        if(BST->Left && BST->Right)
        {
            Tmp = FindMin(BST->Right);
            BST-> Data= Tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right);
        }
        else
        {
            Tmp = BST;
            if(!BST->Left)
                BST = BST->Right;
            else if(!BST->Right)
                BST = BST->Left;
            free(Tmp);
        }
        return BST;
}

平衡二叉树：空树或者任一结点左、右子树高度差不超过1
平衡因子：左、右子树高度差
平衡二叉树的调整：RR, LL, LR, RL
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
Max(int a, int b)
{
    return a>b ? a : b;
}
int GetHeight(AVLTree T)
{
    if(!T)
        return 0;
    return Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
}

AVLTree SingleLeftRotation(AVLTree A)                                      A        --->       B
{                                                                          |                   |
    AVLTree B = A->Left;                                                B-   -AR           BL-   -A
    A->Left = B->Right;                                                 |                  |      |
    B->Right = A;                                                   BL-   -BR                 BL-   -AR
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;   |        
    B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
    return B;
}
AVLTree SingleRightRotation(AVLTree A)
{                                                                       A          --->     B
    AVLTree B = A->Right;                                               |                   |                       
    A->Right = B->Left;                                             AL-   -B             A-   -BR
    B->Left = A;                                                           |             |      |
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;      BL-   -BR     AL-   -BL
    B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;              |
    return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}
AVLTree Insert(AVLTree T, ElementType X)
{
    if(!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Data)
    {
        T->Left = Insert(T->Left, X);
        if(GetHeight(T->Left)-GetHeight(T->Right) == 2)
            if(X < T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
    }
    else if(X > T->Data)
    {
        T->Right = Insert(T->Right, X);
        if(GetHeight(T->Left)-GetHeight(T->Right) == -2)
            if(X > T->Right->Data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
    }
    T->Hight = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return T;
}