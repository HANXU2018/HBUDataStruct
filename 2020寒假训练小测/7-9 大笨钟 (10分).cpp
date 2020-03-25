#include<iostream>
using namespace std;
int main(){
	int a,b;
	scanf("%d:%d",&a,&b);
	int t=a;
	if(b!=0){
		t++;
	}t=t-12;
	if(t>0){
		for(int i=0;i<t;i++){
			cout<<"Dang";
		}
	}else{
		printf("Only %02d:%02d.  Too early to Dang.",a,b);
	}
	return 0;
}
