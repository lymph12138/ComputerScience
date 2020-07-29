/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime.
For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (<10^5) and D (1<D≤10), 
you are supposed to tell if N is a reversible prime with radix D.
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. 
The input is finished by a negative N.
Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#include <stdio.h>
#include <math.h>

int IsPrime(int N)
{
	if(N==0 || N==1)
		return 0;
	for(int i=2; i<=sqrt(N); i++)
		if(N%i == 0)
			return 0;
	return 1;
}
int Reverse(int N, int D)
{
	int r;
	for(r=0; N; N/=D)
	{
		r *= D;
		r += N%D; 
	}
	return r;
}
int main()
{
    int N, D;
    
    while(scanf("%d %d", &N, &D) == 2)
    	puts(IsPrime(N)&&IsPrime(Reverse(N, D)) ? "Yes" : "No");
    
    return 0;
}
