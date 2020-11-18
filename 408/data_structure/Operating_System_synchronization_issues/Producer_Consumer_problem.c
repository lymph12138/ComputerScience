    问题描述：一组生产者进程和一组消费者进程共享一个初始为空、大小为n的缓冲区，
只有缓冲区没满时，生产者才能把消息放入缓冲区，否则必须等待；
只有缓冲区不空时，消费者才能从中去取出消息，否则必须等待。
由于缓冲区是临界资源，它只允许一个生产者放入消息，或一个消费者从中取出消息。

semaphore full=0;
semaphore empty=n;
semaphore mutex=1;
Producer()
{
    
    while(1)
    {
        produce an item;
        P(empty);
        P(mutex);
        add the item to buffer;
        V(mutex);
        V(full);
    }
}
Comsumer()
{
    while(1)
    {
        P(full);
        P(mutex);
        take an item away;
        V(mutex);
        V(empty);
        comsume an item;
    }
}

    问题描述：桌子上有一个盘子，每次只能向其中放入一个水果。
爸爸专向盘子中放苹果，妈妈专向盘子中放橘子，儿子专等吃盘子中的橘子，女儿专等吃盘子中的苹果。
只有盘子为空时，爸爸或妈妈才可向盘子中放一个水果；仅当盘子中有自己需要的水果时，儿子或女儿才可以从盘子中取出。
semaphore plate=1;
semaphore apple=0;
semaphore orange=0;
Father()
{
    while(1)
    {
        prepare an apple;
        P(plate);
        put the apple on the plate;
        V(apple);
    }
}
Mother()
{
    while(1)
    {
        prepare an orange;
        P(plate);
        put the orange on the plate;
        V(orange);
    }
}
Son()
{
    while(1)
    {
        P(orange);
        take the orange away from plate;
        V(plate);
        eat the orange;
    }
}
Daughter()
{
    while(1)
    {
        P(apple);
        take the orange away from plate;
        V(plate);
        eat the apple;
    }
}
