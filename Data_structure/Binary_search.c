#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */

List ReadInput()
{
    int number;
    scanf("%d", &number);
    List L; L = (List)malloc(sizeof(struct LNode));
    for(L->Last=1; L->Last<=number; L->Last++)
        scanf("%d",&L->Data[L->Last]);
    return L;
}//read input and put it in the Data[], start with 1.
Position BinarySearch(List L, ElementType X)
{
    int Right = L->Last;
    int Left = 1; int mid;
    while(Left <= Right)
    {
        mid = Left+(Right-Left)/2;
        if(L->Data[mid] == X)
            return mid;
        else if(L->Data[mid] > X)
            Right = mid-1;
        else if(L->Data[mid] < X)
            Left = mid+1;
    }
    return NotFound;
}//find the X. if it exists, return the position, else return NotFound, using BinarySearch method.