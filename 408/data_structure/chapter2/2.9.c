9.线性表(a1,a2,...,an)中的元素递增有序且按顺序存储于计算机内
    设计一算法，完成用最少时间在表中查找数值为x的元素
    若找到则将其与后继元素位置想交换，若找不到则将其插入表中元素仍然有序
int Findx(int A[],int x,int n)
{
    int tag=0;
    int left=0,right=n-1,middle;
    while(right-left!=0)
    {
        middle=(right+left)/2;
        if(A[middle]>x)
            right=middle-1;
        else if(A[middle]<x)
            left=middle+1;
        else
        {
            tag=1;
            break;
        }
    }
    if(tag==0)
    {
        for(j=n;j>middle;j--)
            A[j]=A[j-1];
        A[i]=x;
        return tag;
    }
    else
    {
        int tmp;
        if(middle==n-1)
            return tag;
        tmp=A[i+1];
        A[i+1]=A[i];
        A[i]=tmp;
        return tag;
    }
}