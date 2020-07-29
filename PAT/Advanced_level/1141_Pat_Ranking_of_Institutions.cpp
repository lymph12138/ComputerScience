/*
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances.
Now you are asked to generate the ranklist.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5),
which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:
ID Score School
where ID is a string of 6 characters with the first one representing the test level: B stands for the basic level, 
A the advanced level and T the top level; Score is an integer in [0, 100]; 
and School is the institution code which is a string of no more than 6 English letters (case insensitive). 
Note: it is guaranteed that ID is unique for each testee.
Output Specification:
For each case, first print in a line the total number of institutions.
Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:
Rank School TWS Ns
where Rank is the rank (start from 1) of the institution; School is the institution code (all in lower case); ; 
TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5,
where ScoreX is the total score of the testees belong to this institution on level X; 
and Ns is the total number of testees who belong to this institution.
The institutions are ranked according to their TWS.
If there is a tie, the institutions are supposed to have the same rank,
and they shall be printed in ascending order of Ns. If there is still a tie, 
they shall be printed in alphabetical order of their codes.
Sample Input:
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
Sample Output:
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/ 
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
map <string, int> cnt;
map <string, double> sum;
struct node
{
    string school;
    int tws, ns;
};
vector <node> ans;
bool cmp(node a, node b)
{
    if(a.tws != b.tws)
        return a.tws>b.tws;
    else if(a.ns != b.ns)
        return a.ns<b.ns;
    else
        return a.school<b.school;
}
int main()
{
    int N;
    scanf("%d", &N);
    string id, school;
    int score;
    for(int i=0; i<N; i++)
    {
        cin >> id >> score >> school;
        for(int j=0; j<school.length(); j++)
            school[j] = tolower(school[j]);
        cnt[school]++;
        if(id[0] == 'T')
            sum[school] += score*1.5;
        else if(id[0] == 'A')
            sum[school] += score;
        else
            sum[school] += score/1.5;
    }
    for(auto it=cnt.begin(); it!=cnt.end(); it++)
        ans.push_back(node{it->first, (int)sum[it->first],cnt[it->first]});
    sort(ans.begin(), ans.end(), cmp);
    
    cout << ans.size() << endl;
    int rank[ans.size()];
    rank[0] = 1;
    printf("%d ", rank[0]);
    cout << ans[0].school;
    printf(" %d %d\n", ans[0].tws, ans[0].ns);
    for(int i=1; i<ans.size(); i++)
    {
        if(ans[i].tws == ans[i-1].tws)
            rank[i] = rank[i-1];
        else
            rank[i] = i+1;
        printf("%d ", rank[i]);
            cout << ans[i].school;
            printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    
    return 0;
}