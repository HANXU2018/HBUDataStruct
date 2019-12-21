#include<stdio.h>
int main(){
	int p[100];
	int n=1;
	input(p,n);
	printf("输出第N个位置的数");
	printf("%d",p[n]);
	return 0;
} 
void input(int* p,int n){
	printf("输出一个数存正数组第N个位置\n");
	scanf("%d",(p+n));
	//scanf("%d",&p[n]);
	printf("你输入的是");
	printf("%d",p[n]);
	return ;
	
}
