#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int count=0,time=0;
		int id=1;
		string s;
		int a,b;
		int num[1005]{0};
		
		while(id!=0){
			cin>>id>>s;
			scanf("%d:%d",&a,&b);
			int t=a*60+b;
			if(s[0]=='S'){
				num[id]=t;
			}else{
				if(num[id]>0){
					count++;
					time+=(t-num[id]);
					//cout<<"       "<<id<<"===="<<t<<num[id];
					num[id]=0;
				}
			}
		}
			double tt=time*1.0;
			if(count>1){
				tt=(time*1.0)/count;
			}printf("%d %d\n",count,(int)(tt+0.5));		
	}
	return 0;
} 
