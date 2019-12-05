#include<iostream>
#include<cstring>
using namespace std;
int n ,m;
int b[2048];
int c[2048];
void build(int* a){
	memset(a, -1, sizeof(int)*2048);
    for(int i = 0; i < n; ++i){
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
int check()
{
    for(int i = 1; i < 2048; ++i)if(b[i] != c[i]) return 0;
    return 1;
}
int main(){
	while(cin>>n){
		if(n==0) break;//程序退出结束条件判断
		cin>>m;
		build(b);
		
		for(int i=0;i<m;i++){
			build(c);
			//cout<<i<<" "<<n<<" "<<m<<endl;
			(check()==1) ? cout<<"Yes\n" : cout<<"No\n";	
		} 
	}
	return 0;
}
