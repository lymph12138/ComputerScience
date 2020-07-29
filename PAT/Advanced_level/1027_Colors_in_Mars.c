/*
People in Mars represent the colors in their computers in a similar way as the Earth people.
That is, a color is represented by a 6-digit number,
where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue.
The only difference is that they use radix 13 (0-9 and A-C) instead of 16. 
Now given a color in three decimal numbers (each between 0 and 168),
you are supposed to output their Mars RGB values.
Input Specification:
Each input file contains one test case which occupies a line containing the three decimal color values.
Output Specification:
For each test case you should output the Mars RGB value in the following format:
first output #, then followed by a 6-digit number where all the English characters must be upper-cased. 
If a single color is only 1-digit long, you must print a 0 to its left.
Sample Input:
15 43 71
Sample Output:
#123456
*/
#include <stdio.h>
#define To13(n) ((n)>=10&&(n)<=12 ? n-10+'A' : n+'0')
int main()
{
    int red, green, blue;
    scanf("%d %d %d", &red, &green, &blue);
    char Red[2], Green[2], Blue[2];
    int n;
    n = red/13; Red[0] = To13(n);
    n = red%13; Red[1] = To13(n);
    n = green/13; Green[0] = To13(n);
    n = green%13; Green[1] = To13(n);
    n = blue/13; Blue[0] = To13(n);
    n = blue%13; Blue[1] = To13(n);
    printf("%c%c%c%c%c%c%c", '#', Red[0], Red[1], Green[0], Green[1], Blue[0], Blue[1]);
    
    return 0;
}