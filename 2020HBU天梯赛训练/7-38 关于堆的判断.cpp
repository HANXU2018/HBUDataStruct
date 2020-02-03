#include<iostream>
#include<vector> 
using namespace std;
vector<int>v;
int n,b;

void judge1(int a) {
    if(v[1] == a) printf("T\n");
    else printf("F\n");
}
void judge2(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa > indexb) swap(indexa, indexb);
    if(indexa % 2 == 0 && indexb - indexa == 1) printf("T\n");
    else printf("F\n");
}
void judge3(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if((2 * indexa) == indexb || (2 * indexa) + 1 == indexb) printf("T\n");
    else printf("F\n");
}
void judge4(int a, int b) {
    int indexa = 0, indexb = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i] == a) indexa = i;
        if(v[i] == b) indexb = i;
    }
    if(indexa == indexb * 2 || indexa == 2 * indexb + 1) printf("T\n");
    else printf("F\n");
}
int main(){
	
	cin>>n>>b;
	v.resize(n+1);
	for(int d=1;d<=n;d++){
        int i=d;
		cin>>v[i];
     	while(i != 1&&v[i] < v[i / 2]) {
           	swap(v[i], v[i / 2]);
           	i = i / 2;
     	}

    }
	//for(int i=1;i<=a;i++)cout<<v[i]<<" ";
	for(int i=0;i<b;i++){
		int c,d,j;
		string s;
		cin>>c>>s;
		if(s=="and"){
			cin>>d>>s>>s;
//			if(c>d){
//				swap(c,d);
//                int l;
//				for(j=0;v[j]!=c;j++);
//                for(l=0;v[l]!=d;l++);
//				if(j%2==0&&l-j==1)cout<<"T"<<endl;
//				else cout<<"F"<<endl;
//			}
			judge2(c,d);
		}else{
			cin>>s;
			if(s=="a"){
				cin>>s>>s>>d;
				for(j=0;v[j]!=c;j++);
				if(v[j/2]==d)cout<<"T"<<endl;
				else cout<<"F"<<endl;
			}else{
				cin>>s;
				if(s=="root"){
					if(v[1]==c)cout<<"T"<<endl;
					else cout<<"F"<<endl;
				}else{
					cin>>s>>d;
					for(j=0;v[j]!=d;j++);
					if(v[j/2]==c)cout<<"T"<<endl;
					else cout<<"F"<<endl;
				}
			}
		}
	}
	return 0;
} 
