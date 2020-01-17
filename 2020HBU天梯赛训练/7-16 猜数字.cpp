#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    string num[105];
    string s;
    int t;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        num[t]=s;
        sum+=t;
    }t = sum/n /2;
    //cout<<num[28]<<endl;
    for(int i=0;i<100;i++){
        if(num[t-i]!=""){
			cout<<t<<" "<<num[t-i]<<endl;
			break; 
		} 
        else if(num[t+i]!=""){
        	cout<<t<<" "<<num[t+i]<<endl;
        	break;
		}
    }
    return 0;
}
