10.将一个带头结点的单链表A分解为两个单链表A和B，
    使得A表中含有原表中序号为奇数的元素，而B表中含有原表中序号为偶数的元素
    且相对顺序不变
LinkList SplitA(LinkList &A)
{//assume the number of the first node is odd 
    LinkList B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    LNode *p,*q,*pre;
    int i=1;
    p=A;q=B;
    pre=A;
    p=p->next;
    while(p!=NULL)
    {
        if(i%2==0)
        {
            q->next=p;
            q=p;
            pre->next=p->next;
        }
        p=p->next;
        pre=pre->next;
        i++;
    }
    p->next=NULL;
    q->next=NULL;
    return B;
}