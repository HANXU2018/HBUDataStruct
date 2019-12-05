#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char zhong[10000];
char qian[10000];
struct Tree{
	char data;
	struct Tree *left,*right;
};
struct Tree*creat(int q,int z, int n){
	struct Tree *T;
	int i;
	if(n<=0) T=NULL;
	else{
		T=(struct Tree*)malloc(sizeof(struct Tree)); 
		T->data=qian[q];
	for(i=0;qian[q]!=zhong[z+i];i++);
	T->left=creat(q+1,z,i);
	T->right=creat(q+i+1,z+i+1,n-i-1);
	}
	return T;
}

int getHight(struct Tree *T){
	int m=0,n=0;
	if(T){
	 m=getHight(T->left);
	 n=getHight(T->right);
	 if(n<m)
	 return m+1;
	 else return n+1;
	}else return 0;
}
int main(){
	struct Tree *T;
    int n,i,p;	
    cin>>n;
    for(i=0;i<n;i++)	cin>>qian[i];
    for(i=0;i<n;i++)cin>>zhong[i];
    T=creat(0,0,n);
    p=getHight(T);
    cout<<p<<endl;
}