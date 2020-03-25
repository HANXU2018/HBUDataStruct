#include<iostream>
using namespace std;
int main(){
	int count=0;
	for(int i=0;i<=2019;i++){
		int t=i;
		while(t>0){
			if(t%10==9){
				count++;
				break;
			}else{
				t=t/10;
			}
		}
		
	}
	cout<<count;
	return 0;
}
