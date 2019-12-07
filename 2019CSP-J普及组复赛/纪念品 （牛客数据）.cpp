typedef long long ll;
using namespace std;
int t,n,m,a[105][105],dp[10005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k;
    cin>>t>>n>>m;
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(t==1)
    {
        cout<<m;
        return 0;
    }
    for(i=1;i<t;i++)
    {
        memset(dp,0,sizeof(dp));
        for(j=1;j<=n;j++)
        {
            if(a[i][j]>=a[i+1][j])
            continue;
            for(k=a[i][j];k<=m;k++)
            {
                dp[k]=max(dp[k],dp[k-a[i][j]]+a[i+1][j]-a[i][j]);
            }

        }
        m=m+dp[m];
    }
    cout<<m;
    return 0;
}