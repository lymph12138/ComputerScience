/*
Given a string, you are supposed to output the length of the longest symmetric sub-string. 
For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.
Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.
Output Specification:
For each test case, simply print the maximum length in a line.
Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/ 
#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int len = s.length();
    int num[len];
    int max = 0;
    int max1 = 0;
    int max2 = 0;
    for(int i=0; i<len; i++)
    {
        num[i] = 0;
        int j = 0;
        while(i-j>=0 && i+j<len && s[i-j]==s[i+j])
        {
            num[i]++;
            j++;
        }
        max1 = 2*num[i]-1;
        if(s[i]==s[i+1] && i+1<len)
        {
            num[i] = 0;
            j = 0;
            while(i-j>=0 && i+j+1<len && s[i-j]==s[i+j+1])
            {
                num[i]++;
                j++;
            }
            max2 = 2*num[i];
        }
        if(max1 > max)
            max = max1;
        if(max2 > max)
            max = max2;
    }
    cout << max;
    
    return 0;
}