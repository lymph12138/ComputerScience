2.Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法
int ReverseQueue(Queue &Q,Stack S)
{
    while(!IsEmpty(Q))
    {
        x=DeQueue(Q);
        Push(S,x);
    }
    while(!IsEmpty(S))
    {
        Pop(S,x);
        EnQueue(Q,x);
    }
}