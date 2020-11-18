8.给定两个单链表，编写算法找出两个链表的公共结点
    公共结点：两个链表从某一个结点开始，它们的next都指向听一个结点
LinkList SameNode(LinkList &A, LinkList &B)
{
    LNode *start, *longlist, *shortlist;
    int large=small=temp=0;
    longlist=A; shortlist=B;
    while(longlist!=NULL)
    {
        large++;
        if(longlist->next==NULL)
            break;
    }
    while(shortlist!=NULL)
    {
        small++;
        if(shortlist->next==NULL)
            break;
    }
    if(shortlist!=longlist)
        return NULL;
    if(large<small)
    {
        shortlist=A;
        longlist=B;
        temp=large;
        large=small;
        small=temp;
    }
    else
    {
        shortlist=B;
        longlist=A;
    }
    temp=large-small;
    start=NULL;
    while(temp-->0)
        longlist=longlist->next;
    while(small-->0)
    {
        if(longlist==shortlist)
            start=longlist;
        else
            start=NULL;
        longlist=longlist->next;
        shortlist=shortlist->next;
    }
    return NULL;
}
LinkList SameNode(LinkList &A, LinkList &B)
{
    LNode *A1, *B1, *start;
    A1=Reverse(A); B1=Reverse(B);
    if(A1!=B1)
        return NULL;
    while(A1!=B1)
    {
        start=A1;
        A1=A1->next;
        B1=B1->next;
    }
    return start;
}