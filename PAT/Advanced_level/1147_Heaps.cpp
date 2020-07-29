/*
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property:
if P is a parent node of C, then the key (the value) of P is either greater than 
or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. 
A common implementation of a heap is the binary heap, in which the tree is a complete binary tree.
(Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
Your job is to tell if a given complete binary tree is a heap.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers:
M (≤ 100), the number of trees to be tested; and N (1 < N ≤ 1,000), the number of keys in each tree, respectively.
Then M lines follow, each contains N distinct integer keys (all in the range of int),
which gives the level order traversal sequence of a complete binary tree.
Output Specification:
For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for a min heap,
or Not Heap if it is not a heap at all. Then in the next line print the tree's postorder traversal sequence.
All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.
Sample Input:
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
Sample Output:
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
*/ 
#include <cstdio>
#define max 1010
int number[max], m, n;
void getpost(int index)
{
    if(index > n)
        return ;
    getpost(2*index);
    getpost(2*index+1);
    printf("%d%s", number[index],index==1 ? "\n" :" ");
}

int main()
{
    scanf("%d %d", &m, &n);
    while(m--)
    {
        int maxn = 1;
        int minn = 1;
        for(int i=1; i<=n; i++)
            scanf("%d", &number[i]);
        for(int i=2; i<=n; i++)
        {
            if(number[i] > number[i/2])
                maxn = 0;
            if(number[i] < number[i/2])
                minn = 0;
        }
        if(maxn == 1)
            printf("Max Heap\n");
        else if(minn == 1)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");
        getpost(1);
    }
    return 0;
}