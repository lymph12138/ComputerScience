/*
Consider a positive integer N written in standard notation with k+1 digits a(i) 
as a(k) ⋯a(1) a(0) with 0≤ai <10 for all iand ak>0. 
Then N is palindromic if and only if a(i)=a(k−i) for all i. Zero is written 0 and is also palindromic by definition.
Non-palindromic numbers can be paired with palindromic ones via a series of operations.
First, the non-palindromic number is reversed and the result is added to the original number. 
If the result is not a palindromic number, this is repeated until it gives a palindromic number. 
Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )
Given any positive integer, you are supposed to find its paired palindromic number.
Input Specification:
Each input file contains one test case which gives a positive integer no more than 1000 digits.
Output Specification:
For each test case, print line by line the process of finding the palindromic number.
The format of each line is the following:
A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number,
and this process ends until C becomes a palindromic number -- in this case
we print in the last line C is a palindromic number.; or if a palindromic number cannot be found in 10 iterations,
print Not found in 10 iterations. instead.
Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/ 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
void add(string t)
{
    int len = s.length();
    int flag = 0;
    for(int i=0; i<len; i++)
    {
        s[i] = s[i]+t[i]+flag-'0';
        flag = 0;
        if(s[i] > '9')
        {
            s[i] = s[i]-10;
            flag = 1;
        }
    }
    if(flag == 1)
        s = s+'1';
}
int main()
{
    cin >> s;
    for(int i=0; i<10; i++)
    {
        string t = s;
        reverse(t.begin(), t.end());
        if(t==s)
        {
            cout << s << " is a palindromic number.";
            return 0;
        }
        cout << s <<" + " << t << " = ";
        add(t);
        t = s;
        reverse(s.begin(), s.end());
        cout << s << endl;
        if(t==s)
        {
            cout << s << " is a palindromic number.";
            return 0;
        }
    }
    cout << "Not found in 10 iterations.";
    
    return 0;
}