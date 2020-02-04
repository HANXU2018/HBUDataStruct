#include<iostream>
using namespace std;
int path[510][510];
bool visit[510];
int n,m;
void dfs(int node) {
    visit[node] = true;
    for(int i = 0; i < 510; i++) {
        if(visit[i] == false && path[node][i] == 1)dfs(i);
    }
}
int countpart() {
    int cnt = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < 510; i++) {
        if(visit[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		path[a][b]=1;
		path[b][a]=1;
	}int k;
	cin>>k;
	int count=countpart();
	for(int i=0;i<k;i++){
		cin>>m;
		for(int j=0;j<n;j++){
			path[j][m]=0;
			path[m][j]=0;
		}
		int t=countpart();
		if(t>count+1)printf("Red Alert: City %d is lost!\n", m);
        else printf("City %d is lost.\n", m);
        count = t;
        if(i == n - 1) printf("Game Over.\n");
	}
	return 0;
}
