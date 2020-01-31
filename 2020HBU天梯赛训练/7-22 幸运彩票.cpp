#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    getchar();
    while(n--){
        char c[6];
        for(int i=0;i<6;i++)c[i]=getchar();
        getchar();
        if((c[0]+c[1]+c[2])==(c[3]+c[4]+c[5]))cout<<"You are lucky!"<<endl;
        else cout<<"Wish you good luck."<<endl;
    }
    return 0;
}
