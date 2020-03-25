# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int a[11], dp[11][10];
 
int dfs(int pos, int pre, bool limit)
{
    if(pos == -1)
        return 1;
    if(!limit && dp[pos][pre] != -1) return dp[pos][pre];
    int up = limit?a[pos]:9;
    int ans = 0;
    for(int i=pre; i<=up; ++i)
        ans += dfs(pos-1, i, limit&&i==a[pos]);
    if(!limit)
        dp[pos][pre] = ans;
    return ans;
}
 
int solve(int num)
{
    int k = 0;
    while(num)
    {
        a[k++] = num%10;
        num /= 10;
    }
    return dfs(k-1, 0, true);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int t, a;
    scanf("%d",&a);
        printf("%d\n",solve(a)-1);
    
    return 0;
}
