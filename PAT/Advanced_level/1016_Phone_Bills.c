/*
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, 
depending on the time of day when the call is made.
When a customer starts connecting a long-distance call,
the time will be recorded, and so will be the time when the customer hangs up the phone.
Every calendar month, a bill is sent to the customer for each minute called 
(at a rate determined by the time of day). Your job is to prepare the bills for each month,
given a set of phone call records.
Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll 
(cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (≤1000), followed by N lines of records.
Each phone call record consists of the name of the customer (string of up to 20 characters without space),
the time and date (MM:dd:HH:mm), and the word on-line or off-line.
For each test case, all dates will be within a single month.Each on-line record is paired 
with the chronologically next record for the same customer provided it is an off-line record. 
Any on-line records that are not paired with an off-line record are ignored, 
as are off-line records not paired with an on-line record. 
It is guaranteed that at least one call is well paired in the input. 
You may assume that no two records for the same customer have the same time.
Times are recorded using a 24-hour clock.
Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, 
first print in a line the name of the customer and the month of the bill in the format shown by the sample. 
Then for each time period of a call, print in one line the beginning and ending time and date (dd:HH:mm), 
the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order.
Finally, print the total charge for the month in the format shown by the sample.
Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer
{
	char name[21];
	int month, day, hour, min ,time, state;
}customer;
int cmp(const void *record1, const void *record2)
{
	customer r1 = *(customer*)record1;
	customer r2 = *(customer*)record2;
	
	return strcmp(r1.name, r2.name) ? strcmp(r1.name, r2.name) : r1.time-r2.time; 
} 
int calculate(customer r1, customer r2, int toll[])
{
	int h, time1, time2;
	int charge = 0;
	int start = r1.time;
	int end = r2.time;
	for(time1=start; time1<end; time1=time2)
	{
		time2 = (time1/60+1)*60;
		h = (time1/60)%24;
		charge += ((time2>end ? end : time2)-time1)*toll[h];
	}
	
	return charge;
}
int main()
{
	int toll[24];
	for(int i=0; i<24; i++)
		scanf("%d", &toll[i]);
	int N;
	scanf("%d", &N);
	customer records[N];
	char line[10];
	for(int i=0; i<N; i++)
	{
		scanf("%s %d:%d:%d:%d %s", &records[i].name, &records[i].month, 
		      &records[i].day, &records[i].hour, &records[i].min, &line);
		records[i].time = (records[i].day*24+records[i].hour)*60+records[i].min;
		records[i].state = strcmp("on-line", line)==0 ? 1 : 0; 
	}
	qsort(records, N, sizeof(customer), cmp);
	int charge = 0;
	int total = 0;
	for(int i=1; i<N; i++)
	{
		if(strcmp(records[i].name, records[i-1].name) != 0)
		{
			if(total != 0)
				printf("Total amount: $%.2f\n", total*0.01);
			total = 0;
		}
		else if(records[i-1].state==1 && records[i].state==0)
		{
			if(total == 0)
				printf("%s %02d\n", records[i].name, records[i].month);
			charge = calculate(records[i-1], records[i], toll);
			total += charge;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
			records[i-1].day, records[i-1].hour, records[i-1].min,
			records[i].day, records[i].hour, records[i].min, 
			records[i].time-records[i-1].time, charge*0.01);
		}
	}
	if(total != 0)
		printf("Total amount: $%.2f\n", total*0.01);
		
	return 0;
}