#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    map<int,set<string>> mp;
    for(int i=0;i<a;i++){
        char s[5];
        int k;
        int n;
        //s.resize(5);
        scanf("%s",s);
        scanf("%d",&k);
        while(k-->0){
            scanf("%d",&n);
            mp[n].insert(s);
        }
    }
    for(int i=1;i<=b;i++){
        if(mp[i].size()>0){
            printf("%d %d\n",i,mp[i].size());
            for(auto it = mp[i].begin();it != mp[i].end(); it++){
                //cout<<*it<<endl;
                printf("%s\n",it->c_str());
            }
        }
    }
    return 0;
}
