/*
Suppose a bank has N windows open for service. There is a yellow line in front of the windows
which devides the waiting area into two parts. The rules for the customers to wait in line are:
The space inside the yellow line in front of each window is enough to contain a line with M customers.
Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will 
have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line.
If there are two or more lines with the same length,
the customer will always choose the window with the smallest number.
Customeri will take Ti minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time
at which a customer has his/her business done.
For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line.
There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively.
At 08:00 in the morning, customer1 is served at window1 while customer2 is served at window2.
Customer3 will wait in front of window1 and customer4 will wait in front of window2. 
Customer5 will wait behind the yellow line.
At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems shorter now.
Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally customer5 at 08:10.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: 
N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line),
K (≤1000, number of customers), and Q (≤1000, number of customer queries).
The next line contains K positive integers, which are the processing time of the K customers.
The last line contains Q positive integers, which represent the customers who are asking about the time 
they can have their transactions done. The customers are numbered from 1 to K.
Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished,
in the format HH:MM where HH is in [08, 17] and MM is in [00, 59].
Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, 
you must output Sorry instead.
Sample Input:   //例：三个窗口：Windows1， Windows2， yellow line（等待窗口，进入等待时间短的窗口）
2 2 7 5         //四个正数：N<=20（窗口数），M<=10（每个窗口能够容纳的数量），K<=1000（顾客数），Q<=1000（输出数量）
1 2 6 4 3 534 2 //K个正数：每个顾客的等待时间
3 4 5 6 7       //Q个正数：输出完成时间
Sample Output:  //HH:MM 开始于08：00 ,  HH<=17,  MM<=59 超出输出Sorry
08:07          
08:06
08:10
17:00
Sorry
*/
#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int poptime, endtime;
    queue<int>q;
};
int main()
{
    int N, M, K, Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    node window[N+1];
    int times[K+1], result[K+1], sorry[K+1];
    for(int i=1; i<=N; i++)
    {
        window[i].poptime = 0;
        window[i].endtime = 0;
    }
    for(int i=1; i<=K; i++)
    {
        scanf("%d", &times[i]);
        result[i] = 0;
        sorry[i] = 0;
    }
    int index = 1;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(index <= K)
            {
                window[j].q.push(times[index]);
                if(window[j].endtime >= 9*60)
                        sorry[index] = 1;
                window[j].endtime += times[index];
                if(i == 1)
                    window[j].poptime = window[j].endtime;
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    while(index <= K)
    {
        int tmpmin = window[1].poptime;
        int tmpwindow = 1;
        for(int i=2; i<=N; i++)
            if(window[i].poptime < tmpmin)
            {
                tmpwindow = i;
                tmpmin = window[i].poptime;
            }
        window[tmpwindow].q.pop();
        window[tmpwindow].q.push(times[index]);
        window[tmpwindow].poptime += window[tmpwindow].q.front();
        if(window[tmpwindow].endtime >= 9*60)
            sorry[index] = 1;
        window[tmpwindow].endtime += times[index];
        result[index] = window[tmpwindow].endtime;
        index++;
    }
    for(int i=0; i<Q; i++)
    {
        int query;
        scanf("%d", &query);
        if(sorry[query])
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", result[query]/60+8, result[query]%60);
    }
    
    return 0;
}

