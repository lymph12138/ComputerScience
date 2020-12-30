p97(1~4)
1.若希望循环队列中的元素都能得到利用，则需设置一个标志域tag，
    并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是“空”还是“满”。
    试编写与此结构相应的入队和出队算法。
    tag=0,empty
    tag=1,full
    maxsize
int EnQueue(SqQueue &Q,ElemType x)
{
    if(Q.front==Q.rear && tag==1)
        return 0; 
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%maxsize;
    if(Q.rear==Q.front)
        tag=1;
    return 1;
}
int DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.front==Q.rear && tag==0)
        return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%maxsize;
    if(Q.front==Q.rear)
        tag=0;
    return 1;
}