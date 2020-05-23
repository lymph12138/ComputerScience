稳定性：任意两个相等的数据，排序前后的相对位置不发生改变
简单排序：
1.void BubbleSort(ElementType A[], int N)
{//冒泡排序
    int p, i, flag;
    for(p=N-1; p>0; p--)
    {
        flag = 0;
        for(i=0; i<p; i++)
        {
            if(A[i] > A[i+1])
            {
                Swap(A[i], A[i+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}//稳定，T = O(N^2)
2.void InsertionSort(ElementType A[], int N)
{//插入排序
    int p, i, tmp;
    for(p=1; p<n; p++)
    {
        tmp = A[p];
        for(i=p; i>0 && A[i-1]>tmp; i--)
            A[i] = A[i-1];
        A[i] = tmp;
    }
}//稳定，T = O(N^2)

3.希尔排序：增量序列 Dm>...>D2>D1=1
void ShellSort(ElementType A[], int N)
{
    for(D=N/2; D>0; D/2=2)
    {
        for(p=D; p<N; p++)
        {
            tmp = A[p];
            for(i=p; i>=D && A[i-D]>tmp; i-=D)
                A[i] = A[i-D]
            A[i] = tmp;
        }
    }
}//不稳定，T = O(N^2)
Hibbard增量序列：Dk = 2^k-1 T = O(N^1.5)
Sedgewick增量序列：Dk = 4^k-3*2^k+1 T = O(N^1.33)

4.堆排序：建立最大堆
void HeapSort(ElementType A[], int N)
{
    for(i=N/2-1; i>=0; i--)
        PercDown(A, i, N);
    for(i=N-1; i>0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}//不稳定，T = O(NlogN)

5.归并排序：分而治之
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
    int LeftEnd, NumElements, Tmp;
    int i;
    
    LeftEnd = R-1;
    Tmp = L;
    NumElements = RightEnd-L+1;
    
    while(L<=LeftEnd && R<=RightEnd)
    {
        if(A[L] <= A[R])
            TmpA[Tmp++] = A[L++];
        else
            TmpA[Tmp++] = A[R++];
    }
    while(L<=LeftEnd)
        TmpA[Tmp++] = A[L++];
    while(R<=RightEnd)
        TmpA[Tmp++] = A[R++];
    for(i=0; i<NumElements; i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}
void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
    int Center;
    
    if(L<RightEnd)
    {
        Center = (L+RightEnd)/2;
        Msort(A, TmpA, L, Center);
        Msort(A, TmpA, Center+1, RightEnd);
        Merge(A, TmpA, L, Center+1, RightEnd);
    }
}
void MergeSort(ElementType A[], int N)
{//归并排序
    ElementType *TmpA;
    TmpA = (ElementType *)malloc(N*sizeof(ElementType));
    
    Msort(A, TmpA, 0, N-1);
    free(TmpA);
}//稳定，T = O(NlogN)

6.快速排序：分而治之
ElementType Median(ElementType A[], int Left, int Right)
{
    int Center = (Left+Right)/2;
    if(A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);
    Swap(&A[Center], &A[Right-1]);
    return A[Right-1];
}
void Qsort(ElementType A[], int Left, int Right)
{
    int Pivot, Cutoff, Low, High;
    
    if(Cutoff <= Right-Left)
    {
        Pivot = Median(A, Left, Right);
        Low = Left;
        Hight = Right-1;
        while(1)
        {
            while(A[++Low] < Pivot);
            while(A[--High] >Pivot);
            if(Low < High)
                Swap(&A[Low], &A[High]);
            else
                break;
        }
        Swap(&A[Low], &A[Right-1]);
        Qsort(A, Left, Low-1);
        Qsort(A, Low+1, Right);
    }
    else InsertionSort(A+Left, Right-Left+1);
}
void QuickSort(ElementType A[])
{
    Qsort(A. 0, N-1);
}//不稳定，T = O(N^2)

7.表排序
8.基数排序