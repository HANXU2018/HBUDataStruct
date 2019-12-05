#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	vector<int>p(N);
	for(int i=0;i<N;i++)p[i]=i;
	for(int i=0;i<M;i++){
		int num;
		cin>>num;
		int l;
		cin>>l;
		for(int j=1;j<num;j++){
			int a;
			cin>>a;
			fa(l,a);
		}
	}
	int max =1;
	vector<int>pp(M);
	int Max=0;
	for(int i=1; i<=n; i++){
		
	}
	return 0;
}
