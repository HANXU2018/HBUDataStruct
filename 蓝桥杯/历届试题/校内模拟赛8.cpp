#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool num1[1001][1001];
int num2[1001][1001];
int fun(int num,int ab){
	num2[num][ab]=1;
	int sum=1;
	for(int i=1;i<ab;i++){
		if(!num1[i][abs(num-i)]){
			num2[i][abs(num-i)]=fun(i,abs(num-i));
			//cout<<"µ÷ÓÃ"<<i<<" "<<abs(num-i)<<endl; 
			num1[i][abs(num-i)]=true;
		}
		//cout<<num2[i][abs(num-i)] <<" "<<i<<" "<<abs(num-i)<<endl;
		sum+=num2[i][abs(num-i)];
	}
	//cout<<"sum=="<<sum<<" "<<num<<" "<<ab<<endl;
	return sum;
}
int main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=fun(i,n-i);
	}
	cout<<sum;
	return 0;
} 
