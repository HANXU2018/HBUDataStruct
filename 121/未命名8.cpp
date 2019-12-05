#include<iostream>
#include<vector>
using namespace std;
struct ju{
	float a;
	float b;
};
int main(){
	float max=0;
	int n;
	cin>>n;
	vector<ju> ju(n);
	for(int i=0;i<n;i++){
		float a;
		float b;
		cin>>a>>b;
		ju[i].a=a;
		ju[i].b=b;
	}
	for(int i=0;i<n;i++){
		float len=0;
		float high=ju[i].b;
		for(int l=i;l<n;l++){
		 	 len+=ju[l].a;
		 	 if(high>ju[l].b){
		 	 	high=ju[l].b;
			  }
			  float sum=len*high;
			  if(sum>max){
			  	max=sum;
			  }
			  //cout<<sum<<" "<<len<<" "<<high<<endl;
		 } 
	}
	printf("%.1f",max);
	return 0;
	
}
