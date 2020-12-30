4.试给出二叉树的自下而上、从右到左的层次遍历算法
void LevelOrder2(BiTree T)
{
    InitStack(S);
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        Push(S,p);//push p into Stack S while remove p from Queue Q
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
    while(!IsEmpty(S))//visit Stack S, it is the from bottom to top and from right to left sequence that we want
    {
        Pop(S,p);
        visit(p->data);
    }
}