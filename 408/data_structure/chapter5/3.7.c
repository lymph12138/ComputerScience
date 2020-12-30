7.二叉树按二叉链表形式存储，写一个判别给定二叉树是否是完全二叉树的算法
int IsCompelteTree(BiTree T)
{
    InitQueue(Q);
    BinTree p;
    if(T==NULL)
        return 1;
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        if(p)
        {
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else
        {
            while(!IsEmpty(Q))
            {
                DeQueue(Q,p);
                if(!p)
                    return 0;
            }
        }
    }
    return 1;
}