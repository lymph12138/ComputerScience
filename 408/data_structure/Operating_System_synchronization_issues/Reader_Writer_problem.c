    问题描述：有读者和写者两组并发的进程，共享一个文件，
当两个或以上的读进程访问共享数据时不会产生副作用，
但若某个写进程和其他进程（读进程或写进程）同时访问共享数据时则可能导致数据不一致的错误。
因此要求：
一：允许多个读者可以同时对文件执行读操作；
二：只允许一个写者往文件中写信息；
三：任一写者都在完成操作之前不允许其他读者或写者工作；
四：写者执行写操作前，应让已有的读者和写者全部退出。
分析：互斥：读者与写者，写者与写者
Readers first:
int rc=0;
semaphore rcm=1;
semaphore write=1;
Reader()
{
    while(1)
    {
        P(rcm);
        rc++;
        if(rc==1)
            P(write);
        V(rcm);
        reading;
        P(rcm);
        rc--;
        if(rc==0)
            V(write);
        V(rcm);
    }
}
Writer()
{
    while(1)
    {
        P(write);
        writing;
        V(write);
    }
}
Weak Writers first:
int rc=0;
semaphore rcm=1;
semaphore write=1;
semaphore read=1;
Reader()
{
    while(1)
    {
        P(read);
        P(rcm);
        rc++;
        if(rc==1)
            P(write);
        V(rcm);
        V(read);
        reading;
        P(rcm);
        rc--;
        if(rc==0)
            V(write);
        V(rcm);
    }
}
Writer()
{
    while(1)
    {
        P(read);
        P(write);
        writing;
        V(write);
        V(read);
    }
}
Strong Writers first:
int rc,wc=0;
semaphore rcm,wcm=1
semaphore read,write,wf=1;
Reader()
{
    while(1)
    {
        P(wf);
        P(read);
        P(rcm);
        rc++;
        if(rc==1)
            P(write);
        V(rcm);
        V(read);
        V(wf);
        reading;
        P(rcm);
        rc--;
        if(rc==0)
            V(write);
        V(rcm);
    }
}
Writer()
{
    while(1)
    {
        P(wcm);
        wc++;
        if(wc==1)
            P(read);
        V(wcm);
        P(write);
        writing;
        V(write);
        P(wcm);
        wc--;
        if(wcm==0)
            V(read);
        V(wcm);
    }
}
这里wf的设立是为了保证写者优先级的再次提高。
因为wf的初值为1，在读进程执行完P(wf)后等在P(read)这一句的读者最多只有1个。
写进程队列一经申请便一直占用着read信号量，知道所有写进程都完成才让出。
假设读队列现在有n个进程，新进来的写进程等待次数从n+1次变为了2次，提高了写进程的优先级。