#include<iostream>
using namespace std;
struct Node{
	int add,val,next;
};
Node node[100005];
Node nod[100005];
int main(){
	int add,n;
	cin>>add>>n;
	for(int i=0;i<n;i++){
		int ad,val,next;
		cin>>ad>>val>>next;
		node[ad].add=ad;
		node[ad].val=val;
		node[ad].next=next;
	}
	int count=0;
	while(add!=-1){
		nod[count++]=node[add];
		add=node[add].next;	
	}int flag=1;
	int ff=0;
	int a=0;
	int b=n-1;
	while(a!=b){
		if(flag)printf("%05d %d ",nod[b].add,nod[b].val);
		else printf("%05d\n%05d %d ",nod[b].add,nod[b].add,nod[b].val);
		flag=0;
		b--;
		if(flag)printf("%05d %d ",nod[a].add,nod[a].val);
		else printf("%05d\n%05d %d ",nod[a].add,nod[a].add,nod[a].val);
		flag=0;
		if(a==b)break;
		a++;
	}cout<<-1;
	return 0;
}
