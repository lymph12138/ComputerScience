/*
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.
For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.
Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10^5) 
which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.
Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
Sample Input:           Sample Output:
00100 6 4               00000 4 33218
00000 4 99999           33218 3 12309
00100 1 12309           12309 2 00100
68237 6 -1              00100 1 99999
33218 3 00000           99999 5 68237
99999 5 68237           68237 6 -1
12309 2 33218
*/
#include <stdio.h>
int FindAd(int Ad, int Add[], int n);
int main()
{
    int FtAd, n, K, add1, add2;
    scanf("%d %d %d", &FtAd, &n, &K);
    
    int Ad1[3*n], N[3*n], Ad2[3*n];
    for(int i=0; i<n; i++)
        scanf("%d %d %d", &Ad1[i], &N[i], &Ad2[i]);
    add = FindAd(FtAd, Ad1);
    Ad1[n] = FtAd; N[n] = add; Ad2[n] = Ad2[add];
    for(int i=1; i<n; i++)
    {
        add = FindAd(Ad2[n], Ad1);
        Ad1[n+i] = Ad1[n+i-1]; N[n+i] = add; Ad2[n+i] = Ad2[add];
    }
    for(int i=0; i<2*n; i++)
        printf("%d %d %d\n", Ad1[i], N[i], Ad2[i]);
        
    return 0;
}
int FindAd(int Ad, int Add[])
{
    int n = sizeof(Add)/sizeof(Add[0]);
    for(int i=0; i<n; i++)
        if(Add[i]==Ad)
        {
            return i;
            break;
        }
}

