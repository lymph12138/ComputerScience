4.设单链表的表头指针为L，结点结构由data和next两个域构成，其中data域为字符型。
    试设计算法判断该链表的全部n个字符符合I否中心对称。
bool judge(LinkList &L, int n)
{
    LNode *p=L;
    char string[n/2];
    int i=0;
    while(i<=n/2)
    {
        string[i]=p->data;
        i++;
        p=p->next;
    }
    if(n%1==1)
        p=p->next;
    while(p!=NULL)
    {
        if(p->data==string[i])
            i--;
        else
            return false;
        p=p->next;
    }
    return true;
}