/*
设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数
（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
#include <stdio.h>
int N1[2000],N2[2000],N3[4000], N4[4000];
int n1,n2; 
void SumFun();
void TimesFun(); 
int main()
{
	int index,modulus;
	scanf("%d", &n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d %d", &modulus, &index);
		N1[index+999] = modulus;
	}
	scanf("%d", &n2);
	for(int j=0;j<n2;j++)
	{
		scanf("%d %d", &modulus, &index);
		N2[index+999] = modulus;
	}
	TimesFun();
	printf("\n");
	SumFun();
	
	return 0;
}
void SumFun()
{
	int judge=0;
	for(int i=1999;i>0;i--)
	{
		N3[i] = N2[i]+N1[i];
		if(N3[i]!=0 && judge==0)
		{
			printf("%d %d", N3[i], i-999);
			judge=1;
		}
		else if(N3[i]!=0 && judge!=0)
			printf(" %d %d", N3[i], i-999);		
	}
	if(judge==0)
		printf("%d %d", 0, 0);
	
}
void TimesFun()
{
	int judge=0;
	for(int i=1999;i>0;i--)
		for(int j=1999;j>0;j--)
			N4[i+j] = N1[i]*N2[j]+N4[i+j];		
	for(int l=3999;l>0;l--)
	{
		if(N4[l]!=0 && judge==0)
		{
			printf("%d %d", N4[l], l-1998);
			judge=1;
		}
		else if(N4[l]!=0 && judge!=0)
			printf(" %d %d", N4[l], l-1998);
	}
	if(judge==0)
		printf("%d %d", 0, 0); 	
}