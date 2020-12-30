8.假设二叉树采用二叉链接表存储结构存储，试设计一个算法
    计算一颗给定二叉树的所有双分支结点个数（类似于求树高)
int DoubleSonsNode(BiTree b)
{
    if(b==NULL)
        return 0;
    if(b->lchild!=NULL && b->rchild!=NULL)
        return DoubleSonsNode(b->lchild)+DoubleSonsNode(b->rchild)+1;
    else 
        return DoubleSonsNode(b->lchild)+DoubleSonsNode(b->rchild);
}