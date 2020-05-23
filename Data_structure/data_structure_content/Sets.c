并查集：集合并、查某元素属于什么集合
采用数组存储形式：下标表示元素，值表示父结点，负数表示根结点,绝对值表示元素个数

#define maxn 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[maxn];

void Union(SetType S, SetName Root1, SetName Root2)
{
    if(S[Root2] < S[Root1])
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    else
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}
SetName Find(SetType S, ElementType X)
{
    if(S[X] < 0)
        return X;
    else
        return S[X] = Find(S, S[x]);
}