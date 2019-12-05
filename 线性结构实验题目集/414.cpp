#include<iostream>
using namespace std;
struct Tree{
    char data;
    struct Tree *left,*right;
};
char v1[100000];
char v2[100000];
Tree* creat(int root,int beg ,int len){
    Tree * T;
    int i;
    if(len<=0) T=NULL;
    else{
        T=(struct Tree*)malloc(sizeof(Tree));
        T->data=v1[root];
    for(i=0;v1[root]!=v2[beg+i];i++);
    T->left=creat(root+1,beg,i);
    T->right=creat(root+i+1,beg+i+1,len-i-1);
    }return T;
}
int getHight(Tree* T){
    int m=0,n=0;
    if(T){
        m=getHight(T->left);
        n=getHight(T->right);
        if(m<n){
            return n+1;
        }return m+1;
    }return 0;
}
int main(){
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)cin>>v1[i];
    for(i=0;i<n;i++)cin>>v2[i];
    Tree * T=creat(0,0,n);
    cout<<getHight(T);
    return 0;
}
