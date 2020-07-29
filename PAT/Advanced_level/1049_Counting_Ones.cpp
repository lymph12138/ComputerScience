/*
The task is simple: given any positive integer N, 
you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N.
For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
Input Specification:
Each input file contains one test case which gives the positive N (≤2^30).
Output Specification:
For each test case, print the number of 1's in one line.
Sample Input:
12
Sample Output:
5
*/
#include <stdio.h>
int main()
{
    long long N;
    scanf("%lld", &N);
    long long count = 0;
    long long left = 0;
    long long right = 0;
    long long a = 1;
    long long now = 1;
    while(N/a)
    {
        left = N/(a*10);
        right = N%a;
        now = (N/a)%10;
        if(now == 0)
            count += left*a;
        else if(now == 1)
            count += left*a+right+1;
        else
            count += left*a+a;
        a *= 10;
    }
    printf("%lld", count);
    
    return 0;
}