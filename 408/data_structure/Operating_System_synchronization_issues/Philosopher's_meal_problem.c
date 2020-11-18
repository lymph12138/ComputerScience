    问题描述：一张圆桌上坐着5名哲学家，每两名哲学家之间的桌上摆一根筷子，两根筷子之间是一碗米饭。
哲学家们只思考和吃饭，哲学家在思考时，并不影响他人。只有当哲学家饥饿时，才试图拿起左、右两跟筷子（一根一根拿起）。
若筷子已在他人手上，则需要等待。饥饿的哲学家只有同时拿到了两根筷子才可以开始进餐，进餐完毕后，放下筷子继续思考。
semaphore chopsticks[5]={1,1,1,1,1};
semaphore mutex=1;
Philosopheri()
{
    while(1)
    {
        P(mutex);
        P(chopsticks[i%5]);
        P(chopsticks[i-1]);
        V(mutex);
        eating;
        V(chopsticks[i-1]);
        V(chopsticks[i%5]);
        thinking;
    }
}