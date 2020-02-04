#include<iostream>
using namespace std;
int num[27][200005];
int count[27];

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	getchar();
	char c;
	int i=0;
	while((c=getchar())!='\n'){
		count[c-'a']++;
		num[c-'a'][count[c-'a']]=i++;
	}
	int min=200005;
	int flag=0;
	for(int i=0;i<26;i++){
//		cout<<i<<"*";
//		for(int j=1;j<=count[i];j++){
//			cout<<num[i][j]; 
//		} cout<<endl;
		int t=count[i];
		while(t>=b){
			flag=1;
			int sum=num[i][t]-num[i][t-b+1]+1;
			if(sum<min)min=sum;
			t--;
		}
	}if(flag)cout<<min;
	else cout<<-1;
	return 0;
}
