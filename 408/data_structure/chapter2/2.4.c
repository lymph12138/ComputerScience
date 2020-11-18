4.从有序表中删除其值在给定值s与t之间（要求s<t）的所有元素，
    如果s或t不合理或顺序表为空，则显示出错信息并退出运行
bool DeleteFromStoT(SqList &L, ElemType s, ElemType t)
{
    if(s>=t||L.length==0)
        return false;
    int k=0;
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]>s&&L.data[i]<t)
            k++;
        else
            L.data[i-k]=L.data[i];
    }
    L.length-=k;
    return true;
}