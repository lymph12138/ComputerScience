/*
The task is really simple: given N exits on a highway which forms a simple cycle, 
you are supposed to tell the shortest distance between any pair of exits.
Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10^5]),
followed by N integer distances D1 D2 ⋯ DN, where Di is the distance between the i-th and the (i+1)-st exits, 
and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space.
The second line gives a positive integer M (≤10^4), with M lines follow, 
each contains a pair of exit numbers, provided that the exits are numbered from 1 to N.
It is guaranteed that the total round trip distance is no more than 10^7.
Output Specification:
For each test case, print your results in M lines, 
each contains the shortest distance between the corresponding given pair of exits.
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/ 
//1(1)2(2)3(4)4(14)5(9)1
#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int sum[N+1];
    sum[0] = 0;
    for(int i=1; i<N; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    scanf("%d", &sum[N]);
    int M, d1, d2, tmp, count, min;
    scanf("%d", &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d %d", &d1, &d2);
        if(d1>d2)
        {
            tmp = d1;
            d1 = d2;
            d2 = tmp;
        }
        count = sum[d2-1]-sum[d1-1];
        min = count;
        count = sum[N-1]-count+sum[N];
        if(count < min)
            min = count;
        printf("%d\n", min);
    }
    
    return 0;
}