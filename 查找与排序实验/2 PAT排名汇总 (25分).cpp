#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct stu{
	string id;
	int score;
	int kc;
	int kcpm;
	int zpm;
};
bool cmp0(stu s1,stu s2){
	if(s1.kc==s2.kc){
		return s1.score>s2.score;
	}else return s1.kc<s2.kc;
}
bool cmp1(stu s1,stu s2){
	if(s1.score!=s2.score){
		return s1.score>s2.score;
	}return s1.id<s2.id;
}
vector<stu>st;
int main(){
	long long int n;
	cin>>n; 
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		for(int j=0;j<p;j++){
			string a;
			int b;
			cin>>a>>b;
			stu s;
			s.id=a;
			s.score=b;
			s.kc=i+1;
			st.push_back(s);
		}
	}
	sort(st.begin(),st.end(),cmp0);
	int count=1;
	for(int i=0;i<st.size();i++){
		if(i>0&&st[i].kc!=st[i-1].kc){
			count=1;
		}
		st[i].kcpm=count++;
		if(i>0&&st[i].kc==st[i-1].kc&&st[i].score==st[i-1].score){
			st[i].kcpm=st[i-1].kcpm;
		}
	}
	sort(st.begin(),st.end(),cmp1);
	cout<<st.size()<<endl;
	count=1;
	for(int i=0;i<st.size();i++){
		st[i].zpm=count++;
		if(i>0&&st[i].score==st[i-1].score){
			st[i].zpm=st[i-1].zpm;
		}
		cout<<st[i].id<<" "<<st[i].zpm<<" "<<st[i].kc<<" "<<st[i].kcpm<<endl;
	}
	return 0;
}
