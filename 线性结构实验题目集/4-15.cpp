#include<iostream>
using namespace std;
int hou[33];
int zhong[33];
int flag=0;
struct tree{
	int data;
	tree *left,*right;
};

tree* creat(int root,int begin,int end){//end =length+begin 
	if(end<begin)return NULL;
	tree *t=(tree*)malloc(sizeof(tree));
	t->data=hou[root];
	//cout<<hou[root] <<" "<<root <<" "<< begin<<" " <<end<<endl;
	int i;
	for(i=begin;hou[root]!=zhong[i];i++);
	
	t->left=creat(root-1-(end-i),begin,i-1);
	t->right=creat(root-1,i+1,end);
	return t;
}
void mlr(tree * t){
	if(t==NULL){
		return ;
	}	if(flag)cout<<" ";
	cout<<t->data;

	flag=1;
	mlr(t->left);
	mlr(t->right);
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>hou[i];
	}
	for(int i=0;i<n;i++){
		cin>>zhong[i];
	}
	tree *t=creat(n-1,0,n-1);
	cout<<"Preorder: ";
	mlr(t);
	return 0;
}
