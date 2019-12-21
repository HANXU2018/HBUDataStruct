#include<iostream>
#include<algorithm>

using namespace std;
struct country{
	int id;
	int num;
	int numi;
	int gold;
	int goldi;
	int preson;
	int p1;
	int p2;
	int way;
	int min;	
};
country cou[250];
bool cmp1(country cou1,country cou2){
	return cou1.num>cou2.num; 
}
bool cmp2(country cou1,country cou2){
	return cou1.gold>cou2.gold;
}
bool cmp3(country cou1,country cou2){
	return 1.0*cou1.num/cou1.preson > 1.0*cou2.num/cou2.preson;
}
bool cmp4(country cou1,country cou2){
	return 1.0*cou1.gold/cou1.preson > 1.0*cou2.gold/cou2.preson;
}
bool cmp0(country cou1,country cou2){
	return cou1.id<cou2.id;
}
int a,b ;
int main(){
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cou[i].id=i;
		cin>>cou[i].num>>cou[i].gold>>cou[i].preson;
	}
	sort(cou+0,cou+a,cmp1);
	for(int i=0;i<a;i++){
		if(i>0&&cou[i].num==cou[i-1].num){
			cou[i].numi=cou[i-1].numi;
		}else{
			cou[i].numi=i;
		}
	}
	sort(cou+0,cou+a,cmp2);
	for(int i=0;i<a;i++){
		if(i>0&&cou[i].gold==cou[i-1].gold){
			cou[i].goldi=cou[i-1].goldi;
		}else{
			cou[i].goldi=i;
		}
	}
	sort(cou+0,cou+a,cmp3);
	for(int i=0;i<a;i++){
		if(i>0&&1.0*cou[i].num/cou[i].preson==1.0*cou[i-1].num/cou[i-1].preson){
			cou[i].p1=cou[i-1].p1;
		}else{
			cou[i].p1=i;
		}
	}
	sort(cou+0,cou+a,cmp4);
	for(int i=0;i<a;i++){
		if(i>0&&1.0*cou[i].gold/cou[i].preson==1.0*cou[i-1].gold/cou[i-1].preson){
			cou[i].p2=cou[i-1].p2;
		}else{
			cou[i].p2=i;
		}
	}
	sort(cou+0,cou+a,cmp0);
	for(int i=0;i<b;i++){
		int d;
		cin>>d;
		cou[d].way=0;
		cou[d].min=cou[d].numi;
		if(cou[d].goldi<cou[d].min){
			cou[d].min=cou[d].goldi;
			cou[d].way=1;
		}
		if(cou[d].p1<cou[d].min){
			cou[d].min=cou[d].p1;
			cou[d].way=2;
		}
		if(cou[d].p2<cou[d].min){
			cou[d].min=cou[d].p2;
			cou[d].way=3;
		}
		if(i>0)cout<<" ";
		cout<<cou[d].min+1<<":"<<cou[d].way+1;
		//cout<<cou[i].goldi<<" "<<cou[i].numi<<" "<< cou[i].p1<<" "<<cou[i].p2<<endl;
	}
	
	return 0;
} 
