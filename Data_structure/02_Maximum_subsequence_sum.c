/*
Given a sequence of K integers { N(1), N(2), ..., N(K) }.
A continuous subsequence is defined to be { N(i), N(i+1), ..., N(j) } where 1≤i≤j≤K.
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.
For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000).
The second line contains K numbers, separated by a space.
Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. 
The numbers must be separated by one space, but there must be no extra space at the end of a line.
In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). 
If all the K numbers are negative, then its maximum sum is defined to be 0, 
and you are supposed to output the first and the last numbers of the whole sequence.
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
输出格式：输出最大和max，子序列左指标i 对应的数，子序列右指标j 对应的数。
特例：如果有两个相同的子列有相同最大和输出指标数小的那一个,
      如果输入的数全为正数，输出 0 0 对应的数 n-1 对应的数（n 为输入元素的个数） 
*/
#include <stdio.h>
int main()
{
    int n;
    int max=-1;
    int maxing=0;
    scanf("%d", &n);
    int number[n];
    for(int i=0; i<n; i++)
    	scanf("%d", &number[i]);
    int i=0; int j=0;
    int i1=0; int j1=0;
    
    for(int i=0; i<n; i++)
    {
        maxing = 0;
        for(int j=i; j<n; j++)
        {
        	maxing = maxing+number[j];
        	if(maxing > max)
        	{
        		i1 = i; j1 = j;
        		max = maxing;
			}
		}
    }
    if(max<0)
    	printf("%d %d %d", 0, number[0], number[n-1]);
    else
    	printf("%d %d %d", max, number[i1], number[j1]);	
    
    return 0;
}