#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n,total=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>>que;
	for(int i=0 ,k;i<n;i++){
		cin>>k;
		que.push(k);
	}while(que.size()>1){
		int a=que.top();que.pop();
		int b=que.top();que.pop();
		total+=a+b;
		que.push(a+b);
	}cout<<total;
	return 0;
} 
