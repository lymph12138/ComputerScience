int QsortDivide(int A[], int n)
{//return middle, 0~middle is A1,middle+1~n-1 is A2
    int left=0,right=n-1,middle;
    int low,high;
    while(1)
    {
        middle=A[left];
        while(right>left)
        {
            low=left; high=right;
            while(right>left && A[right]>=middle)
                right--;
            A[left]=A[right];
            while(right>left && A[left]<=middle)
                left++;
            A[right]=A[left];
        }
        A[left]=middle;
        if(left==(n-1)/2)
            break;
        else if(left>(n-1)/2)
            left=low;
        else if(left<(n-1)/2)
            right=high;
    }
    return left;
}