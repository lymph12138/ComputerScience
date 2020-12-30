8.已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,...,am)和(b1,b2,...,bn)
    试编写一个函数，将数组中两个顺序表的位置互换(b1,b2,...,bn)(a1,a2,...,am)
void main()
{
    Reverse(A,0,m-1);
    Reverse(A,m,m+n-1);
    Reverse(A,0,m+n-1);
}
void Reverse(int A[],int low,int upper)
{
    int tmp;
    int a=low,b=upper;
    for(int i=0;i<(b-a)/2;i++)
    {
        tmp=A[a+i];
        A[a+i]=A[b-i];
        A[b-i]=tmp;
    }
}
