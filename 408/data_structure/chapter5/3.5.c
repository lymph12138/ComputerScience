5.假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度
递归方法：
int max(int a, int b)
{
    return a>b?a:b;
}
int GetHeight(BiTree T)
{
    if(T==NULL)
        return 0;
    else
        return max(GetHeight(T->lchild)+1,GetHeight(T->rchild)+1);
}
int main()
{
    BiTree T;
    int height=0;
    height=GetHeight(T);
}
非递归方法：
int GetHeight(BiTree T)
{
    int level,last,rear,front;
    rear=-1;front=-1;last=0;level=0;
    BiTree Q[maxsize];
    if(T==NULL)
        return level;
    Queue[++rear]=T;
    BiTree p;
    while(front<rear)
    {
        p=Queue[++front];
        if(p->lchild!=NULL)
            Queue[++rear]=p->lchild;
        if(p->rchild!=NULL)
            Queue[++rear]=p->rchild;
        if(front==last)//visit the last point in this level
        {
            level++;
            last=rear;//positioning the next level last point
        }
    }
    return level;
}// In this algorithm we can also caculate the breadth of every level 
int main()
{
    BiTree T;
    int height=0;
    height=GetHeight(T);
}