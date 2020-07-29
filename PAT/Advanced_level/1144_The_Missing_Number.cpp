/*
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5).
Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.
Output Specification:
Print in a line the smallest positive integer that is missing from the input list.
Sample Input:
10
5 -25 9 6 1 3 4 2 5 17
Sample Output:
7
*/
#include <stdio.h>
#include <map>
using namespace std;
map <int, int> number;
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        number[a]++;
    }
    int num = 0;
    while(++num)
        if(number[num] == 0)
            break;
    printf("%d",num);

    return 0;
}