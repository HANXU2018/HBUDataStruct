#include<iostream>
using namespace std;
int yue(int x,int y){
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}
int main(){
	int n;
	cin>>n;
	int a,b;
	scanf("%d/%d",&a,&b);
	int ma=a,mb=b;
	for(int i=1;i<n;i++){
		scanf("%d/%d",&a,&b);
		ma=ma*b+a*mb;
		mb=mb*b;
		int t=yue(ma,mb);
		ma=ma/t;
		mb=mb/t;
	}
	if(mb==1){
		cout<<ma;
	}else {
		if(ma>mb){
			cout<<ma/mb<<" ";
		}
		cout<<ma%mb<<"/"<<mb;	
	}
	return 0;
}
