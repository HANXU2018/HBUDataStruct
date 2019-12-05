#include<bits/stdc++.h>
 using namespace std;
const int maxn = 1024 + 7; 
int n, m;
int a[maxn], b[maxn]; 
void build1()
{
    memset(a, -1, sizeof a);
    for(int i = 0; i < n; ++i)
    {
        int id = 1, x;
        scanf("%d", &x);
        while(1)
        {
            if(a[id] == -1)
            {
                a[id] = x;
                break;
            }
            else if(x < a[id])
            {
                id *= 2;
            }
            else id = 2*id+1;
        }
    }
}
void build2()
{
    memset(b, -1, sizeof b);
    for(int i = 0; i < n; ++i)
    {
        int id = 1, x;
        scanf("%d", &x);
        while(1)
        {
            if(b[id] == -1)
            {
                b[id] = x;
                break;
            }
            else if(x < b[id])
            {
                id *= 2;
            }
            else id = 2*id+1;
        }
    }
}
 
int check()
{
    for(int i = 1; i < maxn; ++i)if(a[i] != b[i]) return 0;
    return 1;
}
 
int main()
{
 
    while(cin>>n>>m)
    {
        if(n==0)
            break;
        build1();
        for(int i = 0; i < m; ++i)
        {
            build2();
            if(check()) cout<<"Yes";
            else cout<<"No";
        }
    }
 
    return 0;
}
