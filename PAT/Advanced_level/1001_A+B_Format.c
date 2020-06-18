/*
Calculate a+b and output the sum in standard format -- that is,
the digits must be separated into groups of three by commas (unless there are less than four digits).
Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where ?10^6≤a,b≤10^6.
The numbers are separated by a space.
Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input:
-1000000 9
Sample Output:
-999,991
*/
#include <stdio.h>
int main()
{
    int a, b, c;
    
    scanf("%d %d", &a, &b);
    c = a+b;
    if(c<0)
    {
        c=-c;
        printf("%c", '-');
    }
    if(c<1000)
        printf("%d", c);
    else if(c<1000000)
        printf("%d,%03d", c/1000, c%1000);
    else 
        printf("%d,%03d,%03d", c/1000000, (c/1000)%1000, c%1000);
            
    return 0;
}