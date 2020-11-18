7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
bool MergeTwoList(SqList A, SqList B, SqList &C)
{
    int i,j,k=0;
    if(A.length+B.length>C.maxsize)
        return false;
    while(i<A.length && j<B.length)
    {
        if(A.data[i]>=B.data[j])
            C.data[k++]=B.data[j++];
        else
            C.data[k++]=A.data[i++];
    }
    while(j<B.length)
        C.data[k++]=B.data[j++];
    while(i<A.length)
        C.data[k++]=A.data[i++];
    C.length=k;
    return true;
}