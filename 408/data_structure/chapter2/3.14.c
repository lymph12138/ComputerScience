14.设a和b是两个单链表（带头结点），其中元素递增有序
    设计一个算法从a和b中的公共元素产生单链表c，要求不破坏a，b的结点
    p，q分别遍历a，b两个单链表，遍历途中比较p，q结点元素的大小
    若p->data=q->data则新建一个结点m连接到c链表的最后
    若p->data>q->data，则q=q->next,p不变
    若p->data<q->data，则p=p->next,q不变