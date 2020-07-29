/*
For a student taking the online course "Data Structures" on China University MOOC
(http://www.icourse163.org/),to be qualified for a certificate, 
he/she must first obtain no less than 200 points from the online programming assignments, 
and then receive a final grade no less than 60 out of 100.
The final grade is calculated by G=G(mid−term)×40%+G(final)×60% if G(mid−term)>Gfinal,
or G(final) will be taken as the final grade G.
Here G(mid−term) and G(final) are the student's scores of the mid-term and the final exams, respectively.
The problem is that different exams have different grading sheets.
Your job is to write a program to merge all the grading sheets into one.
Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers: 
P , the number of students having done the online programming assignments;
M, the number of students on the mid-term list; and
N, the number of students on the final exam list.
All the numbers are no more than 10,000.
Then three blocks follow. The first block contains P online programming scores G(p)'s;
the second one contains M mid-term scores G(mid−term)'s;
and the last one contains N final exam scores G(final)'s.
Each score occupies a line with the format:
StudentID Score, where StudentID is a string of no more than 20 English letters and digits,
and Score is a nonnegative integer (the maximum score of the online programming is 900,
and that of the mid-term and final exams is 100).
Output Specification:
For each case, print the list of students who are qualified for certificates.
Each student occupies a line with the format:
StudentID G(p) G(mid−term) G(final) G
If some score does not exist, output "−1" instead.
The output must be sorted in descending order of their final grades (G must be rounded up to an integer). 
If there is a tie, output in ascending order of their StudentID's. 
It is guaranteed that the StudentID's are all distinct, and there is at least one qullified student.
Sample Input:
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
Sample Output:
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/ 
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct students
{
    string name;
    int gp, gm, gf, ga;
};
bool cmp(students s1, students s2)
{
    return s1.ga==s2.ga ? s1.name<s2.name : s1.ga>s2.ga; 
}
map <string, int> pass;
int main()
{
    int p, m, n;
    scanf("%d %d %d", &p, &m, &n);
    int cnt = 1;
    vector <students> v, ans;
    int score;
    string s; 
    for(int i=0; i<p; i++)
    {
        cin >> s >> score;
        if(score >= 200)
        {
            v.push_back(students{s, score, -1, -1, 0});
            pass[s] = cnt++;
        }
    }
    for(int i=0; i<m; i++)
    {
        cin >> s >> score;
        if(pass[s] != 0)
            v[pass[s]-1].gm = score;
    }
    for(int i=0; i<n; i++)
    {
        cin >> s >> score;
        if(pass[s] != 0)
        {
            v[pass[s]-1].gf = score;
            if(v[pass[s]-1].gf > v[pass[s]-1].gm)
                v[pass[s]-1].ga = v[pass[s]-1].gf;
            else
                v[pass[s]-1].ga = int(0.6*v[pass[s]-1].gf+0.4*v[pass[s]-1].gm+0.5);
        }
    }
    for (int i=0; i<v.size(); i++)
        if (v[i].ga >= 60) 
            ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for(int i=0; i<ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].ga);
        
    return 0;
}