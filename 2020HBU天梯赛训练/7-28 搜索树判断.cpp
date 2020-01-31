#include<iostream>
#include<vector>
using namespace std;
vector<int>num;
vector<int>nn;
bool isMirror = false;
void getpose(int root,int tail){
	if(root > tail)return;
	int i = root+1, j = tail;
	if(!isMirror){
		while(i <= tail && num[root] > num[i]) i++;
        while(j > root && num[root] <= num[j]) j--;
	}else{
        while(i <= tail && num[root] <= num[i]) i++;
        while(j > root && num[root] > num[j]) j--;
	}if(i-j != 1)return;
	getpose(root+1,j);
	getpose(i,tail);
	nn.push_back(num[root]);
	
}
int main(){
	int n;
	cin>>n;
	num.resize(n);
	for(int i=0;i<n;i++)cin>>num[i];
	getpose(0,n-1);
	if(nn.size()!=n){
		isMirror = true;
		nn.clear();
        getpose(0, n-1);
	}
	if(nn.size() == n){
		printf("YES\n%d",nn[0]);
		for(int i=1;i<n;i++)cout<<" "<<nn[i];
	}else cout<<"NO";
	return 0;
}
