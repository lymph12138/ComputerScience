6.有一个带头结点的单链表L设计一个算法使元素递增有序
void Increase(LinkList &L)
{
    LNode *p, *nex, *pre;
    p=L->next;
    if(p==NULL)
        return ;
    nex=p->next;
    p->next=NULL;
    p=nex;
    while(p!=NULL)
    {
        pre=L;
        while(pre->next!=NULL && pre->next->data<p->data)
            pre=pre->next;
        nex=p->next;
        p->next=pre->next;
        pre->next=p;
        p=nex;
    }
}