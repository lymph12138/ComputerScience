2.在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，
    假设值为x的结点不唯一，试编写算法实现上述操作
void DeleteX(LinkList &L, ElemType x)
{
    LNode *p, *pre, *q;
    p=L->next; pre=L;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q=p;
            pre->next=q->next;
            p=p->next;
            free(q);
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
}