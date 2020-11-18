2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
bool Conversel(SqList &L)
{
    if(L.length==0)
        return false;
    ElemType tmp;
    for(int i=0; i<L.length/2;i++)
    {
        tmp=L.data[L.length-1-i];
        L.data[L.lenth-1-i]=L.data[i];
        L.data[i]=tmp;
    }
    return true;
}