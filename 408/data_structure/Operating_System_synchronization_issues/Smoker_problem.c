    问题描述：假设一个系统有三个抽烟者进程和一个供应者进程。每个抽烟者不停地卷烟并抽掉它。
但要卷起并抽掉一只烟，抽烟者需要有三种材料：烟草、纸和胶水。三个抽烟者中，
第一个拥有烟草，第二个拥有纸，第三个拥有胶水。供应者进程无限的提供三种材料。
供应者每次将两种材料放到桌上，拥有剩下那种材料的抽烟者卷起一根烟并抽掉它，
并给供应者一个信号告诉已完成，此时供应者就会将另外两种材料放到桌上，如此重复。 
semaphore mutex0=0;
semaphore mutex1=0;
semaphore mutex2=0;
semaphore finish=0;
int random=0;
producer()
{
    while(1)
    {
        random=any integer;
        random=random%3;
        if(random==0)
            V(mutex0);
        else if(random==1)
            V(mutex1);
        else
            V(mutex2);
        put two materials on the table;
        P(finish);
    }
}
smokeri()
{
    while(1)
    {
        P(mutexi);
        smoking;
        V(finish);
    }
}