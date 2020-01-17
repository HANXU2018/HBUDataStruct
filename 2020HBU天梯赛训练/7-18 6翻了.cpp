#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i=0;
    int count6=0;
    while(i<s.size()){
        if(s[i]!='6')cout<<s[i++];
        else {
            for(count6=0;s[i]=='6'&&i<s.size();i++,count6++);
            //cout<<count6<<"*** ";
            if(count6>9)cout<<27;
            else if(count6>3)cout<<9;
            else {
            	while(count6-->0)cout<<6;
            }
        }
    }
    return 0;
}
