#include<stdio.h>
int main(){
	int p[100];
	int n=1;
	input(p,n);
	printf("�����N��λ�õ���");
	printf("%d",p[n]);
	return 0;
} 
void input(int* p,int n){
	printf("���һ�������������N��λ��\n");
	scanf("%d",(p+n));
	//scanf("%d",&p[n]);
	printf("���������");
	printf("%d",p[n]);
	return ;
	
}
