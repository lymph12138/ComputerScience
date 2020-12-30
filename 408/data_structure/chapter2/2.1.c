p31(1~13)
1.从顺序表中删除就有最小值的元素（假设唯一）并且由函数返回被删元素的值，
    空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
bool DeleteMin(SqList &L, ElemType &e)
{
    if(L.length==0)
        return false;
    e=L.data[0];
    int locate;
    for(i=0;i<L.length;i++)
    {
        if(e>L.data[i])
        {
            e=L.data[i];
            locate=i;
        }
    }
    L.data[locate]=L.data[L.length-1];
    L.length--;
    return true;
}