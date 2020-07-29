/*
At the beginning of every day, the first person who signs in the computer room will unlock the door,
and the last one who signs out will lock the door. Given the records of signing in's and out's,
you are supposed to find the ones who have unlocked and locked the door on that day.
Input Specification:
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, 
followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.
Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked 
and locked the door on that day. The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier 
than the sign out time for each person, and there are no two persons sign in or out at the same moment.
Sample Input:
3                           //数字M：数据数量
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133          //找到最早的和最晚的人
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int number;
    scanf("%d", &number);
    int H, M, S;
    char name[16], first[16], last[16];
    int ftime = 23*60*60+59*60+59;
    int ltime = 0;
    int ntime;
    for(int i=0; i<number; i++)
    {
        scanf("%s %d:%d:%d", &name, &H, &M, &S);
        ntime = H*60*60+M*60+S;
        if(ntime < ftime)
        {
            strcpy(first, name);
            ftime = ntime;
        }
        scanf("%d:%d:%d", &H, &M, &S);
        ntime = H*60*60+M*60+S;
        if(ntime > ltime)
        {
            strcpy(last, name);
            ltime = ntime;
        }
    }
    printf("%s %s", first, last);
    
    return 0;
}