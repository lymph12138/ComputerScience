/*
One way that the police finds the head of a gang is to check people's phone calls. 
If there is a phone call between A and B, we say that A and B is related.
The weight of a relation is defined to be the total time length of all the phone calls made between the two persons.
A "Gang" is a cluster of more than 2 persons who are related to each other with 
total relation weight being greater than a given threshold K. In each gang, 
the one with maximum total weight is the head. Now given a list of phone calls,
you are supposed to find the gangs and the heads.
Input Specification:
Each input file contains one test case.
For each case, the first line contains two positive numbers N and K (both less than or equal to 1000),
the number of phone calls and the weight threthold, respectively.
Then N lines follow, each in the following format:Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, 
and Time is the length of the call. A name is a string of three capital letters chosen from A-Z.
A time length is a positive integer which is no more than 1000 minutes.
Output Specification:
For each test case, first print in a line the total number of gangs.
Then for each gang, print in a line the name of the head and the total number of the members.
It is guaranteed that the head is unique for each gang.
The output must be sorted according to the alphabetical order of the names of the heads.
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/ 
#include <iostream>
#include <map>
using namespace std;
map <string, int> StringToInt;
map <int, string> IntToString;
map <string, int> ans;
#define nmax 2010
int e[nmax][nmax], weight[nmax];
bool visited[nmax];
int idnumber = 1;
int K;
int stoifun(string s)
{
    if(StringToInt[s] == 0)
    {
        StringToInt[s] = idnumber;
        IntToString[idnumber] = s;
        return idnumber++;
    }
    else
        return StringToInt[s];
}
void dfs(int u, int &head, int &members, int &total)
{
    visited[u] = true;
    members++;
    if(weight[u] > weight[head])
        head = u;
    for(int v=1; v<idnumber; v++)
    {
        if(e[u][v]>0)
        {
            total += e[u][v];
            e[u][v] = 0;
            e[v][u] = 0;
            if(visited[v] == false)
                dfs(v, head, members, total);
        }
    }
}
void dfstravel()
{
    for(int i=1; i<idnumber; i++)
    {
        if(visited[i] == false)
        {
            int head = i;
            int members = 0;
            int total = 0;
            dfs(i, head, members, total);
            if(members>2 && total>K)
                ans[IntToString[head]] = members;
        }
    }
}
int main()
{
    fill(e[0], e[0]+nmax*nmax, 0);
    fill(visited, visited+nmax, false);
    fill(weight, weight+nmax, 0);
    int N, w;
    cin >> N >> K;
    string s1, s2;
    for(int i=0; i<N; i++)
    {
        cin >> s1 >> s2 >> w;
        int id1 = stoifun(s1);
        int id2 = stoifun(s2);
        e[id1][id2] += w;
        e[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    dfstravel();
    cout << ans.size() << "\n";
    for(auto it=ans.begin(); it!=ans.end(); it++)
        cout << it->first << " " << it->second << "\n";
        
    return 0;
}