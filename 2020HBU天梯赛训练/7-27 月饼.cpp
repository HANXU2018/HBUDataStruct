#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct nn{
	double num;
	double price;
	double sum;
};
bool cmp1(nn n1,nn n2){
	return n1.price>n2.price;
}
int main(){
	int a,b;
	cin>>a>>b;
	vector<nn>n(a);
	for(int i=0;i<a;i++){
		cin>>n[i].num;
	}
	for(int i=0;i<a;i++){
		cin>>n[i].sum;
		n[i].price = n[i].sum*1.0/n[i].num; 
	}sort(n.begin(),n.end(),cmp1);
	double ss=0;
	for(int i=0;i<a;i++){
		if(b==0){
			break;
		}
		if(n[i].num<b){
			ss+=n[i].sum;
			b-=n[i].num;
		}else{
			ss+=b*n[i].price;
			b=0;
		}
		//cout<<i<<" "<<ss<<endl;
	}printf("%.2f",ss);
	return 0;
} 
