{1,2,3,4,5}->{3,4,5,1,2}find the smallest number in this array
int samllest(int A,int length)
{
    int index1=0,index2=length-1,middle;
    while(index1<index2)
    {
        middle=(index1+index2)/2;
        if(A[middle]<A[index1])
            index2=middle;
        else
            index1=middle;
    }
    return A[index1];
}