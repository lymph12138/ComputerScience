动态规划:(Dynamic Programming)p425
    递归写法：
int dp[maxn];
int F(int n)
{
    if(n==0 || n==1)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    else
    {
        dp[n] = F[n-1]+F[n-2];
        return dp[n];
    }
}
    递推写法：
int n, dp[n][n];//f[n][n];
for(int j=1; j<=n; j++)
    dp[n][j] = f[n][j];
for(int i=n-1; i>=1; i++)
    for(int j=1; j<=i; j++)
        dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+f[i][j];
printf("%d", dp[1][1]);

最大连续子序列和(以A[i]结尾)
int n, dp[n];
dp[0] = A[0];
dp[i] = max(A[i], dp[i-1]+A[i]);//i>0;
int k = 0;
for(int i=0; i<n; i++)
    if(dp[i]>dp[k])
        k = i;
printf("%d", dp[k]);

最长不下降子序列(LIS)(以A[i]结尾)
int n, dp[n];
int ans = -1; //dp[i] = 1;
for(int i=1; i<=n; i++)
{
    dp[i] = 1;
    for(int j=1; j<i; j++)
        if(A[i] >= A[j]
            dp[i] = max(dp[i], dp[j]+1);
    ans = max(ans, dp[i]);
}
printf("%d", ans);

最长公共子序列(LCS)(dp[i][j]表示A序列i位与B序列j位前的LCS长度)
int na, nb, dp[na][nb];//na = A.length()+1, nb = B.length()+1;
for(int i=0; i<=na; i++)
    dp[i][0] = 0;
for(int j=0; j<=nb; j++)
    dp[0][j] = 0;
for(int i=1; i<=na; i++)
{
    for(int j=1; j<=nb; j++)
    {
        if(A[i] == B[j])
            dp[i][j] = dp[i-1][j-1]+1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
printf("%d", dp[na][nb]);