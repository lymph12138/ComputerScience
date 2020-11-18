5.试编写带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)
void Reverse(LinkList &L)
{
    LNode *p, *pre, *nex;
    p=L->next;
    if(p==NULL)
        return ;
    pre=L;
    nex=p->next;
    p->next=NULL;
    while(nex!=NULL)
    {
        pre=p;
        p=nex;
        nex=nex->next;
        p->next=pre;
    }
    L->next=p;
}
