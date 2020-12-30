9.给定一个带表头结点的单链表，设head为头指针，结点结构为（data，next），data为整型元素，next为指针
    写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
void MinDelete(LinkList &head)
{
    LNode *pre,*p;
    while(head->next!=NULL)
    {
        pre=head;
        p=head->next;
        int min=p->data;
        while(p->next!=NULL)
        {
            if(p->next->data < min)
                pre=p;
            p=p->next;
        }
        puts(pre->next->data);
        LNode *u=pre->next;
        pre->next=u->next;
        free(u);
    }
    free(head);
}