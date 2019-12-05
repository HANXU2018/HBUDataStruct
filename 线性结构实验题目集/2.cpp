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
struct Tree*creat(int q,int z, int n){// z是起点，n是长度
	struct Tree *T;//树的根节点
	int i;
	if(n<=0) T=NULL;
	else{
		T=(struct Tree*)malloc(sizeof(struct Tree)); 
		T->data=qian[q];
	for(i=0;qian[q]!=zhong[z+i];i++);//找到对付的
	T->left=creat(q+1,z,i);//拆成两部分 Z还是那个 z，i是更新的i  //i应该是树的长度
	T->right=creat(q+i+1,z+i+1,n-i-1);// 参数分别是子树的 根节点位置//  z+i是根节点在中序遍历的位置，
	}
	return T;
}

int getHight(struct Tree *T){
	int m=0,n=0;
	if(T){
	 m=getHight(T->left);
	 n=getHight(T->right);//递归找呗
	 if(n<m)
	 return m+1;
	 else return n+1;//返回那个大的数儿
	}else return 0;//叶子节点是 0；
}
int main(){
	struct Tree *T;
    int n,i,p;	
    cin>>n;
    for(i=0;i<n;i++)	cin>>qian[i];
    for(i=0;i<n;i++)cin>>zhong[i];
    T=creat(0,0,n);//根   个数
    p=getHight(T);
    cout<<p<<endl;
}