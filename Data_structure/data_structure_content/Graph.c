图：(Graph)多对多的关系
包含：一组顶点V(Vertex)、一组边(有向或无向)

1, Graph Create()：建立并返回空图
2, Graph InsertVertex(Graph G, Vertex v)：将顶点v插入图G
3, Graph InsertEdge(Graph G, Edge e)：将边e插入图G
4, void DFS(Graph G, Vertex v)：从顶点v出发深度优先遍历图G
5, void BFS(Graph G, Vertex v)：从顶点v出发宽度优先遍历图G
6, void ShortestPath(Graph G, Vertex v, int Dist[])：计算图G中顶点v到任意其他顶点的最短距离
7, void MST(Graph G)：计算图G的最小生成树

邻接矩阵G[N][N]--N个顶点从0到N-1编号
        {1  若<vi, vj>是G中的边
G[i][j] {
        {0  否则
用一个长度为N(N+1)/2 的一维数组A存储无向图的邻接矩阵，G[i][j]在A中对应的下标是：(i*(i+1)/2+j)

邻接表：G[N]为指针数组，对应矩阵每行一个链表，只存非0元素
G[0]->1->3：表示0与1和3连接
G[1]->5->3->0->2：表示1与5、3、0和2连接
。。。。

深度优先搜索(Depth First Search, DFS)：类似于树的先序遍历
void DFS(Vertex v)
{
    visited[v] = true;
    for(v的每个邻接点w)
        if(！visited[w])
            DFS(w);
}

广度优先搜索(Breadth First Search, BFS)：按类似同心圆的搜索方法
void BFS(Vertex v)
{
    visited[v] = true;
    Enqueue(v, Q);
    while(!IsEmpty(Q))
    {
        v = Dequeue(Q);
        for(v的每个邻接点w)
        if(!visited[w])
        {
            visited[w] = true;
            Enqueue(w, Q);
        }
    }
}

连通：如果从v到w存在一条(无向)路径，则称v和w是连通的
连通图：图中任意两顶点均连通
连通分量：无向图的极大连通子图

强连通图：有向图中顶点v和w之间存在双向路径，则称v和w是强连通的

void Visit(Vertex V)
{
    printf("正在访问顶点%d\n", V);
}
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{
    PtrToAdjVNode W;
    
    Visit(V);
    Visited[V] = true;
    
    for(W=Graph->G[V].FirstEdge; W; W=W->Next)
        if(!Visited[W->AdjV])
            DFS(Graph, W->AdjV, Visit);
}

bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
    return Graph->G[V][W]<INFINITY ? true : false;
}
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
    Queue Q;
    Vertex V, W;
    
    Q = CreateQueue(MaxSize);
    Visit(S);
    Visited[S] = true;
    AddQ(Q, S);
    
    while(!IsEmpty(Q))
    {
        V = DeleteQ(Q);
        for(W=0; W<Graph->Nv; W++)
            if(!Visited[W] && IsEdge(Graph, V, W))
            {
                Visit(W);
                Visited[W] = true;
                AddQ(Q, W);
            }
    }
} 

建立图：
用邻接矩阵建立图：
          { 1  若<vi, vj>是G中的边
G[i][j] = {
          { 0  否则

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

1.MGraph初始化
typedef int Vertex;
MGraph CreatGraph(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct PtrToGNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    for(V=0; V<Graph->Nv; V++)
        for(W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = 0;
    
    return Graph;
}
2.向MGraph中插入边
typedef struct ENode *PtrToENode;
struct PtrToENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight；
    
    Graph->G[E->V2][E->V1] = E->Weight;//若为无向图 
}
3.完整建立一个MGraph
int G[maxn][maxn], Nv, Ne;
void BuildGraph()
{
    int i, j, v1, v2, w;
    
    scanf("%d", &Nv);
    for(i=0; i<Nv; i++)
        for(j=0; j<Nv; j++)
            G[i][j] = 0;
    scanf("%d", &Ne);
    for(i=0; i<Ne; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}

邻接表表示图：
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct AdjVNode *PtrToAdjVNode；
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};