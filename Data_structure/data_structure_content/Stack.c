中缀表达式：运算符号位于两个运算数之间
后缀表达式：运算符号位于两个运算数之后

堆栈：（stack），有穷线性表
1, Stack CreateStack(int MaxSize)：生成空堆栈，其最大长度为MaxSize
2, int IsFull(Stack S, int MaxSize)：判断堆栈是否已满
3, void Push(Stack S, ElementType item)：将元素item 压入堆栈
4, int IsEmpty(Stack S)：判断堆栈S 是否为空
5, ElmentType Pop(Stack S)：删除并返回栈顶元素

#define MaxSize
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data[MaxSize];
    int Top;
};

1.入栈
void Push(Stack S, ElementType item)
{
    if(PtrS->Top == MaxSize-1)
    {
        printf("堆栈满");
        return;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}
2.出栈
ElementType Pop(stack PtrS)
{
    if(PtrS->Top == -1)
    {
        printf("堆栈空");
        return error;
    }
    else
        return PtrS->Data[--(PtrS->Top)];
}

一个数组实现两个堆栈：
#define MaxSize
struct DStack
{
    ElementType Data[MaxSize];
    int Top1;
    int Top2;
}S;

S.Top1 = -1; S.Top2 = MaxSize;

1.入栈
void Push(struct DStack *PtrS, ElementType item, int Tag)
{
    if(PtrS->Top2 - PtrS->Top1 == 1)
    {
        printf("堆栈满");
        return;
    }
    if(Tag == 1)//对第一个堆栈操作
        PtrS->Data[++(Ptrs->Top1)] = item;
    else //对第二个堆栈操作
        PtrS->Data[--(Ptrs->Top2)] = item;
}
2.出栈
ElementType Pop(struct DStack *PtrS, int Tag)
{
    if(Tag == 1)
    {
        if(PtrS->Top1 == -1)
        {
            printf("堆栈1空");
            return NULL;
        }
        else
            return PtrS->Data[--(PtrS->Top1)]; 
    }
    else 
    {
        if(PtrS->Top2 == MaxSize)
        {
            printf("堆栈2空");
            return NULL;
        }
        else
            return PtrS->Data[++(PtrS->Top2)];
    }
}

堆栈的链式存储

typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
    Struct SNode *Next;
};

1.初始化
Stack CreatStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
2.判断是否为空
int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}
3.入栈
void Push(ElementType item, Stack S)
{
    struct SNode *TmpCell;
    TemCell = (Struct SNode *)malloc(sizeof(struct SNode));
    TemCell->Element = item;
    TmpCell->Next = S->Next;
    S->Next = TemCell;
}
4.出栈
ElementType Pop(Stack S)
{
    struct SNode *FirstCell;
    ElementType = TopElem;
    if(IsEmpty(S))
    {
        printf("栈空");
        return NULL;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Element;
        free(FirstCell);
        return TopElem;
    }
}
中缀表达式转化为后缀表达式
1.运算数相对顺序不变
2.运算数遇到便输出，遇到运算符先记下来
3.遇到比前面优先级高的运算符号接着记下来
4.遇到比前面优先级低的输出
5.左括号进堆栈后优先级变成最低，右括号直接输出直到遇见左括号
6.同一个优先级左大右小