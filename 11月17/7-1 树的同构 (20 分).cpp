#include <bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    int l,r;
};
struct node t1[20],t2[20];
void build(struct node *t, int n)
{
    for(int i = 0; i < n; i ++)
    {
        char s[55];
        scanf("%s", s);
        t[i].data = s[0];
        scanf("%s", s);
        if(s[0] == '-') t[i].l = 100;
        else t[i].l = s[0] - '0';
        scanf("%s", s);
        if(s[0] == '-') t[i].r = 100;
        else t[i].r = s[0] - '0';
    }
}
int ok(int i, int j)
{
    if(t1[t1[i].l].data == t2[t2[j].l].data && t1[t1[i].r].data == t2[t2[j].r].data)
        return 1;
    else if(t1[t1[i].r].data == t2[t2[j].l].data && t1[t1[i].l].data == t2[t2[j].r].data)
        return 1;
    else return 0;
}
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        build(t1,n);
        scanf("%d",&m);
        build(t2,m);
        int f = 0,i,j;
        for(i = 0; i < n; i ++)
        {
            for( j = 0; j < m; j ++)
            {
                if(t1[i].data == t2[j].data)
                {
                    if(ok(i,j)==0){
                        f = 1;
                        break;
                    }
                    else break;
                }
            }
            if(f)break;
            if(j >= m){f = 1;break;}
        }
        if(f)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}