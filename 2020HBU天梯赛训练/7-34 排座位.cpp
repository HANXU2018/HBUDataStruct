#include<iostream>
using namespace std;
int num[105][105];
int fa[105];
int getfa(int a){
	if(fa[a]==a)return a;
	else fa[a]=getfa(fa[a]);
	return fa[a];
}
void uni(int a,int b){
	int faa=getfa(a);
	int fab=getfa(b);
	if(faa<fab) fa[b]=faa;
	else fa[a]=fab;
}
int main(){
	int a,b,c,d,e,f;
	for(int i=0;i<102;i++)fa[i]=i;
	cin>>a>>b>>c;
	for(int i=0;i<b;i++){
		cin>>d>>e>>f;
		num[d][e]=f;
		num[e][d]=f;
		if(f==1)uni(d,e);
	}while(c-->0){
		cin>>d>>e;
		bool flag1=false,flag2=false;
		if(num[d][e]==-1)flag2=true;//µĞÈË 
		flag1 = (getfa(d)==getfa(e));
		if(flag1&&!flag2)cout<<"No problem"<<endl;
		else if(!flag1&&!flag2)cout<<"OK"<<endl;
		else if(flag1&&flag2)cout<<"OK but..."<<endl;
		else if(!flag1&&flag2)cout<<"No way"<<endl;
	}
	
	return 0;
}
