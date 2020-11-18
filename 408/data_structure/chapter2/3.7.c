7.设在一个带头结点的单链表中所有元素的数据值无序，试编写一个函数，
    删除表中所有介于给定的两个值（作为函数的参数给出）之间的元素的元素（若存在）
void Delete(LinkList &L, ElemType min, ElemType max)
{
    LNode *pre, *p, *nex;
    p=L->next; pre=L;
    while(p!=NULL)
    {
        nex=p->next;
        if(p->data<min || p->data>max)
            pre->next=p-next;
        else
            pre=p;
        p=p->next;
    }
}