/*
Given an increasing sequence S of N integers, the median is the number at the middle position.
For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. 
The median of two sequences is defined to be the median of the nondecreasing sequence 
which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence.
For each sequence, the first positive integer N (≤2×10^5) is the size of that sequence. 
Then N integers follow, separated by a space.
It is guaranteed that all the integers are in the range of long int.
Output Specification:
For each test case you should output the median of the two given sequences in a line.
Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
*/
#include <stdio.h>
int main()
{
    int N1, N2;
    scanf("%d", &N1);
    long long s1[N1];
    for(long long i=0; i<N1; i++)
        scanf("%lld", &s1[i]);
    scanf("%d", &N2);
    long long s2[N2];
    for(int i=0; i<N2; i++)
        scanf("%lld", &s2[i]);
    long long s3[N1+N2];
    int i1 = 0; 
    int i2 = 0;
    int i = 0;
    while(i1<N1 && i2<N2)
    {
        if(s1[i1] <s2[i2])
        {
            s3[i] = s1[i1];
            i1++;
            i++;
        }
        else
        { 
            s3[i] = s2[i2];
            i2++;
            i++;
        }
    }
    if(i1 == N1)
    { 
        while(1)
        { 
            s3[i] = s2[i2];
            i++;
            i2++;
            if(i2 == N2)
                break;
        }
    }
    else if(i2 == N2)
    { 
        while(1)
        { 
            s3[i] = s1[i1];
            i++;
            i1++;
            if(i1 == N1)
                break;
        }
    }
    if((N1+N2)%2==0)
        printf("%lld", s3[(N1+N2)/2-1]);
    else
        printf("%lld", s3[(N1+N2)/2]);
    
    return 0;
}