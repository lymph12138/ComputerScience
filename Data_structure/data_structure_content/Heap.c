优先队列(Priority Queue)：特殊的“队列”，取出的元素顺序是依照元素的优先权(关键字)大小
用完全二叉树表示
堆的特性：从根结点到任意结点路径上结点序列的有序性
结构性：用数组表示的完全二叉树
有序性：任一结点的关键字是其子树所有结点的最大值(或最小值)
MaxHeap：最大堆  ； MinHeap：最小堆

最大堆(MaxHeap)：完全二叉树，每个结点的元素值不小于其子结点的元素值
1, MaxHeap CreateHeap(int MaxSize)：创建一个空的最大堆
2, bool IsFull(MaxHeap H)：判断最大堆H是否已满
3, Insert(MaxHeap H, ElementType X)：将元素X插入最大堆H
4, bool IsEmpty(MaxHeap H)：判断最大堆H是否为空
5, ElementType DeleteMax(MaxHeap H)：返回H中最大元素

typedef struct HNode *Heap；
struct HNode
{
    ElementType *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
1.创建空的最大堆
MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Elements = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;//哨兵MaxData大于堆中所有元素
    return H;
}
2.判断最大堆H是否已满
bool IsFull(MaxHeap H)
{
    return H->Size == H->Capacity;
}
3.将元素X插入最大堆H
void Insert(MaxHeap H, ElementType X)
{
    if(IsFull(H))
        printf("最大堆已满");
    for(int i = ++H->Size; H->Data[i/2]<X; i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
}
4.判断最大堆H是否为空
bool IsEmpty(MaxHeap H)
{
    return H->Size == 0;
}
5.返回最大堆H中最大元素
ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, X;
    
    if(IsEmpty(H))
    {
        printf("最大堆已为空");
        return -1;
    }
    MaxItem = H->Data[1];
    X = H->Data[H->Size--];
    for(Parent=1; Parent*2<=H->Size; Parent=Child)
    {
        Child = Parent*2;
        if(Child!=H->Size && H->Data[Child]<H->Data[Child+1])
            Child++;
        if(X>=H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    
    return MaxItem;
}
6.建造最大堆
void PercDown(MaxHeap H, int p)
{
    int Parent, Child;
    ElementType X;
    
    X = H->Data[p];
    for(Parent=p; Parent*2<H->Size; Parent=Child)
    {
        Child = Parent*2;
        if(Child!=H-Size && H->Data[Child]<H->Data[Child+1])
            Child++;
        if(X!=H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}
void BuildHeap(MaxHeap H)
{
    for(int i=H->Size/2; i>0; i--)
        PercDown(H, i);
}
