4.试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）。
void DeleteMin(LinkList &L)
{
    LNode *p, *pre, *minp, *minpre;
    p=L->next; pre=L;
    if(p==NULL)
        return ;
    minp=L->next; minpre=L;
    while(p!=NULL)
    {
        if(minp->data > p->data)
        {
            minp=p;
            minpre=pre;
        }
        p=p->next;
        pre=pre->next;
    }
    minpre->next=minp->next;
    free(minp);
}