/*
With highways available, driving a car from Hangzhou to any other city is easy.
But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time.
Different gas station may give different price. You are asked to carefully design the cheapest route to go.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: 
Cmax(≤ 100), the maximum capacity of the tank;
D (≤30000), the distance between Hangzhou and the destination city;
Davg(≤20), the average distance per unit gas that the car can run;
and N (≤ 500), the total number of gas stations. 
Then N lines follow, each contains a pair of non-negative numbers: 
Pi, the unit gas price, and Di(≤D), the distance between this station and Hangzhou, for i=1,⋯,N. 
All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. 
It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination,
print The maximum travel distance = X where X is the maximum possible distance the car can run, 
accurate up to 2 decimal places.
Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define inf 99999
struct station
{
    float pi, di;
};
bool cmp(station s1, station s2)
{
    return s1.di<s2.di;
}
int main()
{
    float cmax, d, davg;
    int n;
    scanf("%f %f %f %d", &cmax, &d, &davg, &n);
    vector <station> s(n+1);
    for(int i=0; i<n; i++)
        scanf("%f %f", &s[i].pi, &s[i].di);
    s[n].pi = 0; s[n].di = d;
    sort(s.begin(), s.end(), cmp);
    
    float nowdist = 0;
    float nowprice = 0;
    float maxdist = 0;
    float totalprice = 0;
    float leftdist = 0;
    if(s[0].di!=0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else 
        nowprice = s[0].pi;
    while(nowdist < d)
    {
        maxdist = nowdist+cmax*davg;
        float minprice = inf;
        float minpricedist = 0;
        int flag = 0;
        for(int i=1; i<=n && s[i].di<=maxdist; i++)
        {
            if(s[i].di <= nowdist)
                continue;
            if(s[i].pi <= nowprice)
            {
                totalprice += (s[i].di-nowdist-leftdist)*nowprice/davg;
                leftdist = 0;
                nowprice = s[i].pi;
                nowdist = s[i].di;
                flag = 1;
                break;
            }
            if(s[i].pi < minprice)
            {
                minprice = s[i].pi;
                minpricedist = s[i].di;
            }
        }
        if(flag==0 && minprice!=inf)
        {
            totalprice += nowprice*(cmax-leftdist/davg);
            leftdist = cmax*davg-(minpricedist-nowdist);
            nowprice = minprice;
            nowdist = minpricedist;
        }
        if(flag==0 && minprice==inf)
        {
            nowdist += cmax*davg;
            printf("The maximum travel distance = %.2f", nowdist);
            return 0;
        }
    }
    printf("%.2f", totalprice);
    
    return 0;
}