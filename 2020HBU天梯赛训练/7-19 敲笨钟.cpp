#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    getchar(); 
    while(n--){
        getline(cin,s);
        int i=0,j=0,flag=0;
        for(i=0;i<s.size()&&s[i]!=',';i++);
        if(s[i-1]=='g'&&s[i-2]=='n'&&s[i-3]=='o')flag=1;
        if(flag&&s[s.size()-2]=='g'&&s[s.size()-3]=='n'&&s[s.size()-4]=='o'){
        	int count=0;
			for(j=s.size()-1;count!=3;j--)if(s[j]==' ')count++;
            s=s.substr(0,j+1);//有bug的比如zhong。
            cout<<s<<" qiao ben zhong.\n";
        }else cout<<"Skipped"<<endl;
    }
    return 0;
}
