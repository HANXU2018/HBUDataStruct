#include<iostream>
using namespace std;
int main(){
	int t=10;//½øÖÆ 
	int n;
	cin>>n;
	long long int a=0,b=0;
	int flag=0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="CLEAR"){
			flag=0;	
		}else if(s=="NUM"){
			string num;
			cin>>num;
			int tep=0;
			for(int j=0;j<num.size();j++){
				if(num[j]>='0'&&num[j]<='9'){
					tep=tep*t+num[j]-'0';
				}else if(num[j]>='A'&&num[j]<='Z'){
					tep=tep*t+num[j]-'A'; 
				}
			} 
			b=tep;
			if(flag==0){
				a=tep;
			}else if(flag==1){
				a=a+b;
			}else if(flag==2){
				a=a-b;
			}else if(flag==3){
				a=a*b;
			}else if(flag==4){
				if(b!=0&&a!=0){
					a=a/b;	
				}else{
					a=0;
				}
			}else if(flag==5){
				a=a%b;
			}
			
		}else if(s=="EQUAL"){
			string out;
			while(a>0){
				int p=a%t;
				if(p<=9){
					out=(char)(p+'0')+out;
				}else{
					out=(char)(p+'A'-10)+out;
				}
				a=a/t;
			}
			cout<<out<<endl;
		}else if(s=="CHANGE"){
			cin>>t;
		}else if(s=="ADD"){
			flag=1;
		}else if(s=="SUB"){
			flag=2;
		}else if(s=="MUL"){
			flag=3;
		}else if(s=="DIV"){
			flag=4;
		}else if(s=="MOD"){
			flag=5;
		}
	}
	
	return 0;
} 
