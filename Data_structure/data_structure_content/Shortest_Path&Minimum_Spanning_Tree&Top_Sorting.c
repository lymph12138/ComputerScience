最短路径问题：(Shortest Path)在网络中，求两个不同顶点之间的所有路径中，边的权值之和最小的那条路径

BFS
void Dijkstra(Vertex s)
{
    while(1)
    {
        v = 未收录顶点中dist最小者：
        if(这样的v不存在)
            break;
        collected[v] = true;
        for(v的每个邻接点w)
            if(collected[w]==false)
                if(dist[v]+E<v, w> <dist[w])
                {
                    dist[w] = dist[v]+E<v, w>;
                    path[w] = v;
                }
    }
}/*不能解决有负边的情况*/
void Floyd()
{
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            D[i][j] = G[i][j];
            Path[i][j] = -1;
        }
    for(k=0; k<N; k++)
        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
                if(D[i][k]+D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k]+D[k][j];
                    Path[i][j] = k
                }
}

最小生成树：(Minimum Spanning Tree)最小生成树存在 <-> 图连通

void Prim()
{
    MST = {s};
    while(1)
    {
        v = 未收录顶点中dist最小者；
        if(这样的v不存在)
            break;
        将v收录进MST：dist[v] = 0;//初始化为E<v, w>或正无穷
        for(v的每个邻接点w)
            if(dist[w]!=0)
                if(E<v, w> < dist[w])
                {
                    dist[w] = E<v, w>;
                    patent[w] = v;//初始化为-1
                }
    }
    if(MST中收的顶点不到|v|个)
        Error("生成树不存在")；
}
void Kruskal(Graph G)
{
    MST = {};
    while(MST中不到|v|-1条边 && E中还有边)
    {
        从E中取一条权重最小的边E<v, w>;//最小堆
        将E<v, w>从E中删除;
        if(E<v, w>不在MST中构成回路)//并查集
            将E<v, w>加入MST;
        else 
            彻底无视E<v, w>;
    }
    if(MST中不到|v|-1条边)
        Error("生成树不存在")；
}

拓扑排序：如果图中从v到w有一条有向路径，则v一定排在w之前。满足此条件的顶点序列称为拓扑序

void Topsort()
{
    for(图中每个顶点v)
        if(Indegree[v] == 0)
            Enqueue(v, Q);
    while(!IsEmpty(Q))
    {
        v = Dequeue(Q);
        输出v，或者记录v的输出序号;
        cnt++;
        for(v的每个邻接点w)
            if(--Indegree[w] == 0)
                Enqueue(w, Q);
    }
    if(cnt != |v|)
        Error("图中有回路")；
}