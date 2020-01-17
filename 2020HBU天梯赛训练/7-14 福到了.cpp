#include <iostream>
#include <vector>
using namespace std;
int main() {
    int flag=0;
    char c;
    int n;
    cin>>c>>n;
    getchar();
    vector<string> v;
    string s;
    for(int i=0;i<n;i++){
        getline(cin,s);
        v.push_back(s);
    }for(int i=0;i<n&&flag==0;i++){
        for(int j=0;j<v[i].size();j++) if(v[i][j]!=v[n-1-i][n-1-j])flag =1;
    }if(!flag)cout<<"bu yong dao le"<<endl;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(v[i][n-1-j]!=' ')cout<<c;
			else cout<<' ';
        }if (i>0) cout<<endl;
    }
    return 0;
}
 
