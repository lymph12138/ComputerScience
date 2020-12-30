p207
6.试编写一个算法，判断给定的二叉树是否是二叉排序树
#define min -123456
int predata=min;
int IsBST(BiTree T)
{
    int t1,t2;
    if(T==NULL)
        return 1;
    else
    {
        t1=IsBST(T->lchild);
        if(t1==0 || predata>=T->data)
            return 0;
        predata=T->data;
        t2=IsBST(T->rchild);
        return t2;
    }
}