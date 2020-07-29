/*
Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B.
For example, after cutting Z = 167334, we have A = 167 and B = 334.
It is interesting to see that Z can be devided by the product of A and B,
as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20).
Then N lines follow, each gives an integer Z (10 ≤ Z <2^31).
It is guaranteed that the number of digits of Z is an even number.
Output Specification:
For each case, print a single line Yes if it is such a number, or No if not.
Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No
*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int z;
        cin >> z;
        string s = to_string(z);
        int len = s.length();
        int a = stoi(s.substr(0,len/2));
        int b = stoi(s.substr(len/2));
        if(a*b!=0 && z%(a*b)==0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}