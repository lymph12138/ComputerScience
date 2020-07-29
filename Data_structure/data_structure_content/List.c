线性表:(List) ，有序序列

1, List MakeEmpty():初始化一个空线性表L
2, ElementType FindKth(int K, List L):根据位序K，返回相应元素
3, int Find(ElementType X, List L):在线性表L中查找X的第一次出现位置
4, void Insert(ElementType X, int i, List L):在位序i前插入一个新元素X
5, void Delete(int i, List L):删除指定位序i的元素

线性表的顺序存储实现
#define maxsize n;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[maxsize];
    int Last;
};
struct LNode L; List PtrL;
访问下标为i的元素：L.Data[i] or PtrL->Data[i]
线性表的长度：L.Last+1 or PtrL->Last+1

1.初始化（建立空的顺序表）
List MakeEmpty()
{
    List PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}
2.查找第K个元素
ElementType FindKth(int K, List L)
{
    return L->Data[K];
}
3.查找K第一次出现的位置
int Find(ELementType X, List L)
{
    int i = 0;
    while(i<=L->Last && L->Data[i]!=X)
        i++;
    if(i>L->Last) return -1;
    else return i;
}
4.在位序i前插入新元素X
void Insert(ElementType X, int i, List L)
{
    int j = 0;
    if(L->Last==maxsize-1)
    {
        print("表满");
        return;
    }
    if(i<1 || i>=L->Last+2)
    {
        printf("位置不合法")；
        return;
    }
    for(j=L->Last;j>=i-1;j--)
        L->Data[j+1] = L->Data[j];
    L->Data[i-1] = X;
    L->Last++;
    return;
}
5.删除位序i上的元素
void Delete(int i; List L)
{
    int j = 0;
    if(i<1 || i>L->Last+1)
    {
        printf("不存在第%d个元素" , i);
        return;
    }
    for(j=i; j<L->Last; j++)
        L->Data[j-1] = L->Data[j];
    L->Last--;
    return;
}

线性表的链式存储
typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};
struct LNode L;
List PtrL;
1.求表长
int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while(p).
    {
        p = p->Next;
        j++;
    }
    return j;
}
2(1).按序号查找元素
List FindKth(int K, List PtrL)
{
    Lis p = PtrL;
    int i = 0;
    while(i<K && p!=NULL)
    {
        p = p->Next;
        i++;
    }
    if(i==K) return p;
    else return NULL;
}
2(2).按值查找元素
List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while(p!=NULL && p->Data!=X)
        p = p->Next;
    return p;
}
3.插入操作实现
List Insert(ElementType X, int i, List PtrL)
{
    List p, s;
    if(i == 1)
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i-1, PtrL);
    if(p == NULL)
    {
        printf("参数i错误");
        return NULL;
    }
    else 
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}
4.删除操作实现
List Delete(int i, List PtrL)
{
    List p, s;
    if(i == 1)
    {
        s = PtrL;
        if(PtrL != NULL)
            PtrL = PtrL->Next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i, PtrL);
    if(p == NULL)
    {
        printf("第%d个结点不存在", i-1);
        return NULL;
    }
    else if(p->Next == NULL)
    {
        printf("第%d个结点不存在", i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL; 
    }
}


