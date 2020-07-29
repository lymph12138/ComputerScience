/*
Eva is trying to make her own color stripe out of a given one. 
She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces
and sewing the remaining parts together to form her favorite color stripe.
It is said that a normal human eye can distinguish about less than 200 different colors, 
so Eva's favorite colors are limited. However the original stripe could be very long,
and Eva would like to have the remaining favorite stripe with the maximum length.
So she needs your help to find her the best result.
Note that the solution might not be unique, but you only have to tell her the maximum length.
For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}.
If Eva's favorite colors are given in her favorite order as {2 3 1 5 6},
then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.
Input Specification:
Each input file contains one test case. For each case,the first line contains a positive integer N (≤200)
which is the total number of colors involved (and hence the colors are numbered from 1 to N).
Then the next line starts with a positive integer M (≤200) followed by M Eva's favorite color numbers 
given in her favorite order. Finally the third line starts with a positive integer L (≤10^4)
which is the length of the given stripe, followed by L colors on the stripe.
All the numbers in a line a separated by a space.
Output Specification:
For each test case, simply print in a line the maximum length of Eva's favorite stripe.
Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/ 
#include <stdio.h>
#include <algorithm>
using namespace std;
int l1[210], l2[10010];
int main()
{
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);
    int x;
    for(int i=1; i<=M; i++)
    {
        scanf("%d", &x);
        l1[x] = i;
    }
    int L;
    scanf("%d", &L);
    int num = 0;
    for(int i=0; i<L; i++)
    {
        scanf("%d", &x);
        if(l1[x] >= 1)
            l2[num++] = l1[x];
    }
    int dp[num];
    int ans = -1;
    for(int i=0; i<num; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(l2[i]>=l2[j] && (dp[j]+1)>dp[i])
                dp[i] = dp[j]+1;
        ans = max(dp[i], ans);
    }
    
    printf("%d", ans);
}