假设二叉树二叉链存储结构，设计一个算法，求出根结点到某给定结点之间的路径
int Path(BiTree root,BiTree m)
{
    InitStack(S);
    BiTree p,now=root;
    int i,flag;
    do
    {
        while(root!=NULL)
        {
            Push(S,now);
            now=now->lchild;
        }
        p=NULL;
        flag=1;
        while(!IsEmpty(S) && flag)
        {
            GetTop(S,now);
            if(now->rchild==p)
            {
                if(m==now)
                {
                    while(!IsEmpty(S))
                        Pop(S);
                    return 1;
                }
                else
                {
                    Pop(S);
                    p=now;
                }
            }
            else
            {
                now=now->rchild;
                flag=0;
            }
        }
    }while(!IsEmpty(S));
    return 0;
}