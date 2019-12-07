#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a,b,t;
	scanf("%d %d",&a,&b);
	vector<int> v(a);
	for(int i=0;i<a;i++)scanf("%d",&v[i]);
	int low=0;
	int high=a-1;
	for(int i=0;i<b;i++){
		scanf("%d",&t);
		 low=0;
		 high=a-1;
		 if(v[low]==t){
		 	high=low;
		 }else if(v[high]==t){
		 	low=high;
		 }
		 while(v[(low+high)/2]!=t){
		 	if(v[(low+high)/2]<t){
		 		low=(low+high)/2;
			 }else{
			 	high=(low+high)/2;
			 }
		 }
		 if(i!=0){
		 	printf(" ");
		 }
		printf("%d",(low+high)/2);
	}
	return 0;
}
