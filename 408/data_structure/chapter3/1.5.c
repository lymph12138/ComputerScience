5.设有两个栈s1、s2都采用顺序栈方式，并共享一个存储区[0,……,maxsize-1]，
    为了尽量利用空间，减少溢出的可能，可采用栈顶相向、迎面增长的存储方式。
    试设计s1、s2有关入栈和出栈的操作算法。
#define maxsize
typedef struct
{
    Elemtype data[maxsize];
    int top[2];//default top[0]=0, top[1]=maxsize-1
}SqStack;
SqStack S;
bool Push(int i, Elemtype x)
{
    if(i<0 || i>1)
        return false;//wrong stack number
    if(top[1]-top[0]==1)
        return false;//full stack
    if(i==0)
        data[++top[0]]=x;//stack one top number plus one
    else
        data[--top[1]]=x;//stack two top number minus one
    return true;
}
Elemtype Pop(int i)
{
    if(i<0 || i>1)
        return -2;//wrong stack number
    if(i==0)
    {
        if(top[0]==-1)
            return -1;//empty stack one
        else
            return S.data[S.top[0]--];
    }
    else
    {
        if(top[1]==maxsize)
            return -1;//empty stack two
        else
            return S.data[S.top[1]++];
    }
}