#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

struct people{
	int id,fid,mid,k,sum,area;
	int cid[20];
	bool vis=false;
};
struct home{
	int id,pnum,sum,area;
	bool vis=false;
};
bool cmp1(home a,home b){
	if(a.vis!=b.vis){
		if(a.vis==true){
			return true;
		}else return false;
	}
	if(a.area*b.pnum != b.area*a.pnum){
		return a.area*b.pnum > b.area*a.pnum;
	}else if(a.id!=b.id){
		return a.id<b.id;
	}
}
people pp[10005];
home hh[10005];
bool vis[10005];
int fa[10005];
int getfa(int x){
	while(x!=fa[x]){
		x=fa[x];
	}return x;
};
void uni(int a,int b){
	int faa = getfa(a);
	int fab = getfa(b);
	if(faa<fab){
		fa[fab]=faa;
	}else if(fab<faa){
		fa[faa]=fab;
	}
}
int main(){
	for(int i=0;i<10005;i++)fa[i]=i;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id,fid,mid,k;
		cin>>id>>fid>>mid>>k;
		vis[id]=true;
		pp[i].vis=true;
		pp[i].id=id;
		pp[i].fid=fid;
		pp[i].mid=mid;
		pp[i].k=k;
		if(fid!=-1){
			uni(fid,id);
			vis[fid]=true;	
		}
		if(mid!=-1){
			uni(mid,id);
			vis[mid]=true;
		}
		for(int j=0;j<k;j++){
			int cid;
			cin>>cid;
			pp[i].cid[j]=cid;
			vis[cid]=true;
			uni(cid,id);
		}
		int sum,area;
		cin>>sum>>area;
		pp[i].sum=sum;
		pp[i].area=area;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
			int ffa=getfa(pp[i].id);
			if(hh[ffa].vis!=true)cnt++;
			hh[ffa].vis=true;
			hh[ffa].id=ffa;
			if(pp[i].vis==true){
				hh[ffa].sum+=pp[i].sum;
				hh[ffa].area+=pp[i].area;
			}
		
	}
	for(int i=0;i<10005;i++){
		if(vis[i]){
			hh[getfa(i)].pnum++;
		}
	}
	sort(hh+0,hh+10005,cmp1);
	cout<<cnt<<endl; 
	for(int i=0;i<cnt;i++){
		printf("%04d %d %0.3f %0.3f\n",hh[i].id,hh[i].pnum,1.0*hh[i].sum/hh[i].pnum,1.0*hh[i].area/hh[i].pnum);
	} 
	return 0;
} 
