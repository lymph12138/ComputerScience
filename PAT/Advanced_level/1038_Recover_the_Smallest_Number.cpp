/*
Given a collection of number segments, you are supposed to recover the smallest number from them.
For example, given { 32, 321, 3214, 0229, 87 },
we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to 
different orders of combinations of these segments,
and the smallest number is 0229-321-3214-32-87.
Input Specification:
Each input file contains one test case. 
Each case gives a positive integer N (≤10^4) followed by N number segments.
Each segment contains a non-negative integer of no more than 8 digits.
All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the smallest number in one line. Notice that the first digit must not be zero.
Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287
*/  
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2)
{
    return s1+s2 < s2+s1;
}
int main()
{
    int N;
    cin >> N;
    string s[N];
    for(int i=0; i<N; i++)
        cin >> s[i];
    sort(s, s+N, cmp);
    string str;
    for(int i=0; i<N; i++)
        str += s[i];
    while(str[0]=='0' && str.length()!=0)
        str.erase(str.begin());
    if(str.length() == 0)
        cout << 0;
    else
        cout << str;
   
    return 0;
}