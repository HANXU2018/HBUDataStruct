#include<stdio.h>
int a[1005][1005],max=100006,v,b[1005];
int find(int b[]){
	int i,minv,m=max;
	for(i=1;i<=v;i++){
		if(b[i]&&b[i]<m){
			m=b[i];minv=i;
		}
	}
	if(m<max) return minv;
	else return -1;
}
int main()
{
	int i,c=0,x,y,j,z,t,w,f,s,e;
	scanf("%d %d",&v,&e);
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			a[i][j]=max; 
	for(i=1;i<=v;i++)
		b[i]=max;
	while(e--){
		scanf("%d %d %d",&x,&y,&z);
		a[x][y]=a[y][x]=z;
	}
	
	for(i=1;i<=v;i++)
		b[i]=a[1][i];
	
	b[1]=0;
	c++;
	
	while(1){
		t=find(b);
		if(t==-1) break;
		
		s+=b[t];
		b[t]=0;
		c++;
		
		for(w=1;w<=v;w++){
			if(b[w]&&a[t][w]<max){
				if(a[t][w]<b[w]){
					b[w]=a[t][w];
				}
			}
		}		
	}
	
	if(c==v) printf("%d",s);
	else printf("-1");
	return 0;
 } 

