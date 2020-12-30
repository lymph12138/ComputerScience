6.设一棵二叉树中各结点的值互不相同，其先序遍历和中序遍历序列分别存于两个一维数组A[1..n]和B[1..n]中，
    试编写算法建立该二叉树的二叉链表。
BiTree PreInCreatBinTree(int p1, int p2, int i1, int i2, ElemType A[], ElemType B[], int n)
{//p1 is the first node of subsequence of PreOrder sequence, p2 is the last
 //i1 is the first node of subsequence of InOrder sequence, i2 is the last
    root=(BiTNode*)malloc(sizeof(BiTNode));
    root->data=A[p1];
    for(int m=i1;m<i2;m++)
        if(B[m]==A[p1])
            break;
    int llen=m-i1;
    int rlen=i2-m;
    if(llen)
        root->lchild=NULL;
    else
        root->lchild=PreInCreatBinTree(p1+1,p1+llen,i1,i1+llen-1,A,B,n);
    if(rlen)
        root->rchild==NULL;
    else
        root->rchild=PreInCreatBinTree(p2-rlen+1,p2,i2-rlen+1,i2,A,B,n);
    return root;
}
int main()
{
    BiTree T = PreInCreatBinTree(1,n,1,n,A,B,n);
}