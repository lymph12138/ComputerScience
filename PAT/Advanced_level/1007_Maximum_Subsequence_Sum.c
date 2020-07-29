/*
Given a sequence of K integers { N(1), N(2), ..., N(K)}.
A continuous subsequence is defined to be { N(i), N(i+1), ..., N(j)} where 1≤i≤j≤K.
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. 
For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (≤10000). The second line contains K numbers,
separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and 
the last numbers of the maximum subsequence. The numbers must be separated by one space, 
but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique,
output the one with the smallest indices i and j (as shown by the sample case). 
If all the K numbers are negative, then its maximum sum is defined to be 0,
and you are supposed to output the first and the last numbers of the whole sequence.
Sample Input:
10                           
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include <stdio.h>
int main()
{
    int K;
    scanf("%d", &K);
    
    int max = -1;
    int maxing = 0;
    int number[K];
    for(int i=0; i<K; i++)
        scanf("%d", &number[i]);
    int nf = 0; int nl = 0;
    for(int f=0; f<K; f++)
    {
        maxing = 0;
        for(int l=f; l<K; l++)
        {
            maxing += number[l];
            if(maxing > max)
            {
                nf = f;
                nl = l;
                max = maxing;
            }
        }
    }
    if(max<0)
        printf("%d %d %d", 0, number[0], number[K-1]);
    else
        printf("%d %d %d", max, number[nf], number[nl]);
        
    return 0;
}

#include <stdio.h>
int main()
{
    int K;
    scanf("%d", &K);
    
    int number[K];
    for(int i=0; i<K; i++)
        scanf("%d", &number[i]);
    
    int f = -1; int l = -1; int nf = -1; int nl = 0;
    int sum = 0; int suming = -1;
    for(int i=0; i<K; i++)
    {
        if(suming < 0)
        {
            nf = number[i];
            suming = 0;
        }
        suming += number[i];
        if(suming >= 0)
            nl = number[i];
        if(suming>sum || (!suming && !sum))
        {
            sum = suming;
            f = nf;
            l = nl;
        }
    }
    
    if(f == -1)
        printf("%d %d %d", 0, number[0], number[K-1]);
    else
        printf("%d %d %d", sum, f, l);
        
    return 0;
}
