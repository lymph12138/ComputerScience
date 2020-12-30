p189
5.编程求以孩子兄弟表示法存储的森林的叶子结点数
typedef struct BiTNode
{
    struct BiTNode *child,*nextbro;
    
}*CSTree;
int Leaves(CSTree c)
{
    if(c==NULL)
        return 0;
    if(c->child==NULL)
        return 1+Leaves(c->nextbro);
    else
        return Leaves(c->child)+Leaves(c->nextbro);
}