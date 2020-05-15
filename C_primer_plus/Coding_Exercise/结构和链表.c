    Linear_Table:
Initialization:
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}
Find:
int Find(ElementType X, List PtrL)
{
    int i=0;
    while(i<=PtrL->Last && PtrL->Data[i]!=X)
        i++;
    if(i>PtrL->Last) 
        return -1;
    else
        return i;    
}
Insert:
Delete:
    Linked_List:
Length:
FindKth:
Insert: