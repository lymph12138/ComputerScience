/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? 
The answer is yes, if 6 is a decimal number and 110 is a binary number.
Now for any pair of positive integers N1 and N2,
your task is to find the radix of one number while that of the other is given.
Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from 
the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. 
The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.
Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. 
If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.
Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define ToNumber(c) ((c)>='0' && (c)<='9' ? (c)-'0' :(c)-'a'+10)
#define OverFlow -1
#define NotFound -1

long long To10(char *s, long long radix)
{
	long long n, sum;
	for(sum = 0; *s; s++)
	{
		n = ToNumber(*s);
		if((LLONG_MAX - n) / radix < sum)
			return OverFlow;
		sum = sum*radix+n;
	}
	return sum;
}

int minradix(char *s)
{
	char r;
	for(r='0'; *s; s++)
		if(*s > r)
			r = *s;
	return ToNumber(r)+1;
}

long long Binsearch(char *s, long long n, long long rmin, long long rmax)
{
	long long r, m;
	while(rmax >= rmin)
	{
		r = rmin+(rmax-rmin)/2;
		m = To10(s, r);
		if(m>n || m==OverFlow)
			rmax = r-1;
		else if(m<n)
			rmin = r+1;
		else 
			return r;			
	}
	return NotFound;	
}
int main()
{
	int tag, radix;
	long long number, rmax, rmin, r;
	char str1[11], str2[11], *s1, *s2;
	
	scanf("%s %s %d %d", &str1, &str2, &tag, &radix);
	if(tag == 1)
	{
		s1 = str1;
		s2 = str2;
	}
	if(tag == 2)
	{
		s1 = str2;
		s2 = str1;
	}
	number = To10(s1, radix);
	rmin = minradix(s2);
	rmax = LONG_MAX;
	if(strlen(s2) == 1)
	{
		if(number == rmin-1)
			printf("%lld", rmin);
		else
			printf("Impossible");
	}
	else
	{
		r = Binsearch(s2, number, rmin, rmax);
		if(r != NotFound)
			printf("%lld", r);
		else
			printf("Impossible");
	}
	
	return 0;
}
