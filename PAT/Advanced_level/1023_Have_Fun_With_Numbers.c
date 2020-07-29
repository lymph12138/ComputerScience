/*
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, 
with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number 
consisting exactly the numbers from 1 to 9, only in a different permutation. 
Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. 
That is, double a given number with k digits, you are to tell if the resulting number consists of 
only a permutation of the digits in the original number.
Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number 
that consists of only a permutation of the digits in the original number, or "No" if not.
Then in the next line, print the doubled number.
Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char num[22];
    scanf("%s", num);
    int judge[10];
    for(int i=0; i<10; i++)
        judge[i] = 0;
    int flag = 0;
    int len = strlen(num);
    for(int i=len-1; i>=0; i--)
    {
        int tmp = num[i]-'0';
        judge[tmp]++;
        tmp = 2*tmp+flag;
        flag = 0;
        if(tmp >= 10)
        {
            tmp = tmp-10;
            flag = 1;
        }
        judge[tmp]--;
        num[i] = (tmp+'0');
    }
    int flag1 = 1;
    for(int i=0; i<10; i++)
        if(judge[i] != 0)
            flag1 = 0;
    if(flag==0 && flag1 == 1)
        printf("Yes\n");
    else
        printf("No\n");
    if(flag == 1)
        printf("%d%s", flag, num);
    else
        printf("%s", num);
        
    return 0;
}