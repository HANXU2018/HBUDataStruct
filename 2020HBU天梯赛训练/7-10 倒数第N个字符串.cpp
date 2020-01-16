#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    int m;
    cin>>m;
    while(n>0){
        num[--n]=m%26;
        char c= 'z'-m%26;
        cout<<c;
		m=m/26;
         
    }
    return 0;
}
