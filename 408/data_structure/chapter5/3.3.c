p161(3~20)
3.编写后序遍历二叉树的非递归方法
递归方法：
void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T->data);
    }
}
非递归方法：
void PostOrder2(BiTree T)
{
    InitStack(S);
    BiTree p=T;
    r=NULL;
    while(p!=NULL || !IsEmpty(S))
    {
        if(p!=NULL)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            GetTop(S,p);
            if(p->rchild!=NULL && p->rchild!=r)//confirm that p left tree has been visisted just now
            {
                p=p->rchild;
                Push(S,p);
                p=p->lchild;
            }
            else
            {
                Pop(S);
                visit(p->data);
                r=p;
                p=NULL;
            }
        }
    }
}