3.对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
    该算法删除线性表中所有值为x的元素
void DeleteX(SqList &L, ElemType x)
{
    int k=0;
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==x)
            k++;
        else
            L.data[i-k]=L.data[i];
    }
    L.length-=k;
}
x=2;
(0)1 3 2 2 4 7 2 6(0)
(1)1 3 2 2 4 7 2 6(0)
(2)1 3 2 2 4 7 2 6(0)
(3)1 3 2 2 4 7 2 6(1)
(4)1 3 2 2 4 7 2 6(2)
(5)1 3 4 2 4 7 2 6(2)
(6)1 3 4 7 4 7 2 6(2)
(7)1 3 4 7 4 7 2 6(3)
(8)1 3 4 7 6 7 2 6(3)
   1 3 4 7 6

