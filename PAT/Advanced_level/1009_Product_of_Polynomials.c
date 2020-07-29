/*
This time, you are supposed to find A×B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, 
and each line contains the information of a polynomial:
K N1 a(N1) N2 a(N2) ... NK a(NK)
where K is the number of nonzero terms in the polynomial,
Ni and a(Ni) (i=1,2,⋯,K) are the exponents and coefficients, respectively. 
It is given that 1≤K≤10, 0≤NK<⋯<N2<N1≤1000.
Output Specification:
For each test case you should output the product of A and B in one line,
with the same format as the input. Notice that there must be NO extra space at the end of each line.
Please be accurate up to 1 decimal place.
Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
*/
#include <stdio.h>
#define max 2010
int main()
{
    float A[max], B[max], C[max];
    for(int i=0; i<max; i++)
    {
        A[i] = 0;  B[i] = 0;  C[i] = 0;
    }
    
    int index;
    int K1;
    scanf("%d", &K1);
    for(int i=0; i<K1; i++)
    {
        scanf("%d", &index); 
        scanf("%f", &A[index]);
    }
    int K2;
    scanf("%d", &K2);
    for(int i=0; i<K2; i++)
    {
        scanf("%d", &index);
        scanf("%f", &B[index]);
    }
        
    for(int i=0; i<max/2; i++)
        for(int j=0; j<max/2; j++)
            C[i+j] += A[i]*B[j];
    
    int judge = 0;
    for(int i=0; i<max; i++)
        if(C[i] != 0)
            judge++;
    printf("%d", judge);
    for(int i=max-1; i>=0; i--)
        if(C[i] != 0)
            printf(" %d %.1f", i, C[i]);
            
        return 0;
}