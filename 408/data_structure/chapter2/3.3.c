3.设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
void PrintFun(LinkList L)
{
    if(L->next!=NULL)
        PrintFun(L->next);
    if(L!=NULL)
        print(L->data);
}