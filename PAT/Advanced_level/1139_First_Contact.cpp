/*
Unlike in nowadays, the way that boys and girls expressing their feelings of love 
was quite subtle in the early years. When a boy A had a crush on a girl B,
he would usually not contact her directly in the first place. Instead, he might ask another boy C, 
one of his close friends, to ask another girl D, who was a friend of both B and C,
to send a message to B -- quite a long shot, isn't it? Girls would do analogously.
Here given a network of friendship relations, you are supposed to help a boy or a girl to list all their friends 
who can possibly help them making the first contact.
Input Specification:
Each input file contains one test case. For each case, 
the first line gives two positive integers N (1 < N ≤ 300) and M,
being the total number of people and the number of friendship relations, respectively. 
Then M lines follow, each gives a pair of friends. Here a person is represented by a 4-digit ID.
To tell their genders, we use a negative sign to represent girls.
After the relations, a positive integer K (≤ 100) is given, which is the number of queries. 
Then K lines of queries follow, each gives a pair of lovers, separated by a space.
It is assumed that the first one is having a crush on the second one.
Output Specification:
For each query, first print in a line the number of different pairs of friends they can find to help them, 
then in each line print the IDs of a pair of friends.
If the lovers A and B are of opposite genders, you must first print the friend of A who is of the same gender of A,
then the friend of B, who is of the same gender of B. If they are of the same gender, 
then both friends must be in the same gender as theirs. It is guaranteed that each person has only one gender.
The friends must be printed in non-decreasing order of the first IDs, and for the same first ones, 
in increasing order of the seconds ones.
Sample Input:
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003
Sample Output:
4
1002 2004
1003 2002
1003 2003
1004 2002
4
2001 1002
2001 1003
2002 1003
2002 1004
0
1
2003 2001
0
*/ 
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define max 10010
map <int, bool> arr; 
vector <int> v[max];
struct node
{
    int s1, s2;
};
bool cmp(node n1, node n2)
{
    return n1.s1==n2.s1 ? n1.s2<n2.s2 : n1.s1<n2.s1;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.length() == s2.length())
        {
            v[abs(stoi(s1))].push_back(abs(stoi(s2)));
            v[abs(stoi(s2))].push_back(abs(stoi(s1)));
        }
        arr[abs(stoi(s1))*10000+abs(stoi(s2))] = true;
        arr[abs(stoi(s2))*10000+abs(stoi(s1))] = true;
    }
    int K;
    cin >> K;
    for(int i=0; i<K; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        vector <node> ans;
        for(int j=0; j<v[abs(a1)].size(); j++)
        {
            for(int l=0; l<v[abs(a2)].size(); l++)
            {
                if(v[abs(a1)][j]==abs(a2) || v[abs(a2)][l]==abs(a1))
                    continue;
                if(arr[v[abs(a1)][j]*10000+v[abs(a2)][l]] == true)
                    ans.push_back(node{v[abs(a1)][j],v[abs(a2)][l]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans.size() << endl;
        for(int j=0; j<ans.size(); j++)
            printf("%04d %04d\n", ans[j].s1, ans[j].s2);
    }
    
    return 0;
}