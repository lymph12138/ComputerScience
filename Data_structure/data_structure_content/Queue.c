队列：(Queue) 一定操作约束的线性表
1, Queue CreatQueue(int MaxSize)：生成长度为MaxSize 的空队列
2, int IsFullQ(Queue Q, int MaxSize)：判断队列Q 是否已满
3, void AddQ(Queue Q, ElementType item)：将数据元素item 插入队列Q 中
4, int IsEmptyQ(Queue Q)：判断队列Q 是否已空
5, ElementType DeleteQ(Queue Q)：将队头数据元素从队列中删除并返回

#define MaxSize
struct QNode
{
    ElementType Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;

1.入队列
void AddQ(Queue PtrQ, ElementType item)
{
    if(PtrQ->rear - PtrQ->front == MaxSize)
    {
        printf("队列已满");
        return;
    }
    PtrQ->rear++;
    PtrQ->Data[PtrQ->rear] = item;
}
2.出队列
ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->rear == PtrQ->front)
    {
        printf("队列空");
        return error;
    }
    else
    {
        PtrQ->front++;
        return PtrQ->Data[PtrQ->front];
    }
}

链式存储

自行补充