带权路径长度(WPL)：设二叉树有n个叶子结点，每个叶子结点带有权值Wk，从根结点到每个叶子结点的长度为Lk
    则每个叶子结点的带权路径长度之和就是WPL = sigma(k=1, n)Wk*Lk
最优二叉树或哈夫曼树：WPL最小的二叉树

哈夫曼树的构造：每次把权值最小的两棵二叉树合并
typedef struct TreeNode *HuffmanTree;
struct TreeNode
{
    int Weight;
    HuffmanTree Left;
    HuffmanTree Right;
}
HuffmanTree Huffman(MinHeap H)
{
    HuffmanTree T;
    BuildMinHeap(H);
    
    for(int i=1; i<H->Size; i++)
    {
        T = Malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    T = DeleteMin(H);
    
    return T;
}
