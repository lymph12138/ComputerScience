1.设计一个递归算法，删除不带头结点的单链表中所有值为x的值
void DeleteX(LinkList &L, ElemType x)
{
    LNode *p;
    if(L->Next==NULL)
        return;
    if(L->data==x)
    {
        p=L;
        L=L->Next;
        free(p);
        DeleteX(L, x);
    }
    else
        DeleteX(L->Next, x);
}