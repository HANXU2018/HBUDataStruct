#include<iostream>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	getchar();
	while(n--){
		getline(cin,s);
		cout<<s<<endl<<"AI: ";
		string t;
		for(int i=0;i<s.size();i++){
			if(s[i]>='a'&&s[i]<='z'||s[i]=='I'||s[i]>='0'&&s[i]<='9')t+=s[i];
			else if(s[i]>='A'&&s[i]<='Z')t+=s[i]-'A'+'a';
			else if(s[i]==' '&&t[t.size()-1]!=' '&&t.size()>0)t+=' ';
			else if(s[i]==','&&t[t.size()-1]==' ')t[t.size()-1]=',';
			else if(s[i]!=' '){
				if(t[t.size()-1]==' ')t[t.size()-1]=s[i];
				else t+=s[i];
				if(s[i]=='?')t[t.size()-1]='!';
			}//cout<<t<<endl;
		}
		//cout<<t<<"****"<<endl;
		string str;
		for(int i=0;i<t.size();i++){
			int flag=0;
			/*
				把原文中所有独立的 can you、could you 对应地换成 I can、I could
				 这里“独立”是指被空格或标点符号分隔开的单词；
				把原文中所有独立的 I 和 me 换成 you
			*/
			if(i==0||t[i-1]==' '||t[i-1]==','){
				string ss=t.substr(i,7);
				//cout<<"((((("<<ss<<"))))))))"<<endl;
				if(ss=="can you"&&(t[i+7]==' '||t[i+7]==',')){
					str+="I can ";
					if(t[i+7]==',')str[str.size()-1]=',';
					i+=7;
					flag=1;
				}
				ss=t.substr(i,9);
				//cout<<"((((("<<ss<<"))))))))"<<endl;
				if(ss=="could you"&&(t[i+9]==' '||t[i+9]==',')&&!flag){
					str+="I could ";
					if(t[i+9]==',')str[str.size()-1]=',';
					i+=9;
					flag=1;
					//cout<<"**********"<<endl;
				}
				ss=t.substr(i,2);
				//cout<<"((((("<<ss<<"))))))))"<<endl;
				if(ss=="me"&&(t[i+2]==' '||t[i+2]==',')&&!flag){
					str+="you ";
					if(t[i+2]==',')str[str.size()-1]=',';
					i+=2;
					flag=1;
					//cout<<"**********"<<endl;
				}
				ss=t.substr(i,1);
				//cout<<"((((("<<ss<<"))))))))"<<endl;
				if(ss=="I"&&(t[i+1]==' '||t[i+1]==',')&&!flag){
					str+="you ";
					if(t[i+1]==',')str[str.size()-1]=',';
					i+=1;
					flag=1;
					//cout<<"**********"<<endl;
				}
				
			}
			if(!flag){
				str+=t[i];
			}
		}
		cout<<str<<endl;
	}
	return 0;
}
