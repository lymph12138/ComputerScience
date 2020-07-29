/*
This time, you are supposed to find A+B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, 
and each line contains the information of a polynomial:
K N1(aN1)N2(aN2) ... NK(aNK)
where K is the number of nonzero terms in the polynomial, 
Ni and aNi(i=1,2,⋯,K) are the exponents and coefficients, respectively. 
It is given that 1≤K≤10，0≤NK<⋯<N2<N1≤1000.
Output Specification:
For each test case you should output the sum of A and B in one line, 
with the same format as the input. Notice that there must be NO extra space at the end of each line. 
Please be accurate to 1 decimal place.
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
*/
#include <stdio.h>

float L1[1001], L2[1001], L3[1001];
int n1, n2;
int AddFun();

int main()
{
	int index, n3;
	float modulus;
	
	scanf("%d", &n1);
	for(int i=0; i<n1; i++)
	{
		scanf("%d %f", &index, &modulus);
		L1[index]=modulus;	
	}
	scanf("%d", &n2);
	for(int j=0; j<n2; j++)
	{
		scanf("%d %f", &index, &modulus);
		L2[index]=modulus;	
	}
	n3 = AddFun();
	printf("%d", n3);
	for(int i=1000; i>=0; i--)
	{
		if(L3[i]!=0)
			printf(" %d %.1f", i, L3[i]);
	}
	
	return 0;
}

int AddFun()
{
	int n = 0;
	
	for(int i=0; i<1001; i++)
	{
		L3[i] = L1[i]+L2[i];
		if(L3[i]!=0)
			n++;	
	}
	
	return n;
}

#include <stdio.h>

typedef struct Poly
{
    float modulus;
    int index;
}Poly[20];

int main()
{
    int n1, n2;
    Poly L1, L2, L3;
    float m;
    int i;
    
    scanf("%d", &n1);
    for(int j=0; j<n1; j++)
    {
        scanf("%d %f", &i, &m);
        L1[j].modulus = m;
        L1[j].index = i;
    }
    scanf("%d", &n2);
    for(int j=0; j<n2; j++)
    {
        scanf("%d %f", &i, &m);
        L2[j].modulus = m;
        L2[j].index = i;
    }
    
    int l1, l2, l3;
    l1=0; l2=0; l3=0;
    while(l1<=n1 && l2<=n2)
    {
        if(L1[l1].index > L2[l2].index)
        {
            L3[l3].index = L1[l1].index;
            L3[l3].modulus = L1[l1].modulus;
            l1++; l3++;
        }
        else if(L1[l1].index < L2[l2].index)
        {
            L3[l3].index = L2[l1].index;
            L3[l3].modulus = L2[l1].modulus;
            l2++; l3++;
        }
        else
        {
            if(L1[l1].modulus+L2[l2].modulus != 0)
            {
                L3[l3].index = L1[l1].index;
                L3[l3].modulus = L1[l1].modulus+L2[l2].modulus;
                l3++;
            }
            l1++; l2++;
        }
    }
    
    printf("%d", l3);
    for(int j=0; j<l3; j++)
        printf(" %d %.1f", L3[j].index, L3[j].modulus);

    return 0;
}
