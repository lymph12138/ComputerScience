/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of 
Zhejiang University.Each test is supposed to run simultaneously in several places, 
and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤100),
the number of test locations. Then N ranklists follow,
each starts with a line containing a positive integer K (≤300), the number of testees, 
and then K lines containing the registration number (a 13-digit number) and the total score of each testee.
All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in one line the total number of testees. 
Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks.
The testees with the same score must have the same rank, and the output must be 
sorted in nondecreasing order of their registration numbers.
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct student
{
    long long int no;
    int score, final_rank, location_number, local_rank;
};
bool cmp(student s1, student s2)
{
    return s1.score!=s2.score ? s1.score>s2.score : s1.no<s2.no;
}
int main()
{
    int N;
    cin>>N;
    vector<student>final;
    for(int i=1; i<=N; i++)
    {
        int K;
        cin>>K;
        vector<student>now(K);
        for(int j=0; j<K; j++)
        {
            scanf("%lld %d", &now[j].no, &now[j].score);
            now[j].location_number = i;
        }
        sort(now.begin(), now.end(), cmp);
        now[0].local_rank = 1;
        final.push_back(now[0]);
        for(int j=1; j<K; j++)
        {
            now[j].local_rank = (now[j].score==now[j-1].score)?(now[j-1].local_rank):(j+1);
            final.push_back(now[j]);
        }
    }
    sort(final.begin(), final.end(), cmp);
    final[0].final_rank = 1;
    for(int j=1; j<final.size(); j++)
        final[j].final_rank = (final[j].score==final[j-1].score)?(final[j-1].final_rank):(j+1);
    cout<<final.size()<<"\n";
    for(int i=0; i<final.size(); i++)
        printf("%013lld %d %d %d\n", final[i].no, final[i].final_rank, final[i].location_number, final[i].local_rank);
        
    return 0;
}