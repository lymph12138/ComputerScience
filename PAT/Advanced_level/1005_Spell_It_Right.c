/*
Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10^100).
Output Specification:
For each test case, output in one line the digits of the sum in English words. 
There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345
Sample Output:
one five
*/
#include <stdio.h>
int main()
{
    char c;
    int sum = 0;
    
    char *digits[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while((c=getchar()) != '\n')
        sum += c-'0';
    
    if(sum >= 100)
        printf("%s %s %s", digits[sum/100], digits[(sum/10)%10], digits[sum%10]);
    else if(sum >= 10)
        printf("%s %s", digits[sum/10], digits[sum%10]);
    else
        printf("%s", digits[sum]);
        
    return 0;
}