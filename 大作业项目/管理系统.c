#include<stdio.h>
struct stu{
	char name[10];
	char sex;
	int birthday;
	int score[4];//�ɼ��洢 
}; 
 void showTable();
 void addstu(){
 	printf("����ѧ������"); 
 }
 void delstu(){
 	printf("ɾ��ѧ������"); 
 } 
 void fixstu(){
 	printf("�޸�ѧ������"); 
 } 
 void searchstu(){
 	printf("��ѯѧ������"); 
 } 
int main(){
	showTable();
	int n;
	while(1){
	scanf("%d",&n);
	
	if(n==1){
		addstu();
	} else if (n==2){
		searchstu();
	} else if (n==3){
		fixstu();
	}else if(n==4){
		delstu();
	}else{
		printf("��������"); 
	} 
	}
	
} 
 void showTable(){
 	printf("------------------------------------------------\n");
 	printf("1.����ѧ����Ϣ---------------------------------\n");
 	printf("2.��ѯѧ����Ϣ----------------------------------\n");
 	printf("3.�޸�ѧ����Ϣ----------------------------------\n");
 	printf("4.ɾ��ѧ����Ϣ----------------------------------\n");
 	printf("------------------------------------------------\n");
 	printf("-��������Ҫʹ�õĹ���------------------------\n");
 	printf("------------------------------------------------\n");
 }
