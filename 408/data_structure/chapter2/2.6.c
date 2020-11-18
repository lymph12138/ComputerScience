6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同，改为无序表怎么达到O(n)，散列
bool DeleteRepeat(SqList &L)
{
    int k=0;
    if(L.length==0)
        return false;
    if(L.length==1)
        return true;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i]==L.data[i-1])
            k++;
        else 
            L.data[i-k]=L.data[i];
    }
    L.length-=k;
    return true;
}
(0)1 2 2 3 3 4 5(0)
(1)1 2 2 3 3 4 5(0)
(2)1 2 2 3 3 4 5(1)
(3)1 2 3 3 3 4 5(1)
(4)1 2 3 3 3 4 5(2)
(5)1 2 3 4 3 4 5(2)
(6)1 2 3 4 5 4 5(2)
   1 2 3 4 5