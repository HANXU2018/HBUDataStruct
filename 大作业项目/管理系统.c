#include<stdio.h>
struct stu{
	char name[10];
	char sex;
	int birthday;
	int score[4];//成绩存储 
}; 
 void showTable();
 void addstu(){
 	printf("增加学生功能"); 
 }
 void delstu(){
 	printf("删除学生功能"); 
 } 
 void fixstu(){
 	printf("修改学生功能"); 
 } 
 void searchstu(){
 	printf("查询学生功能"); 
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
		printf("输入有误"); 
	} 
	}
	
} 
 void showTable(){
 	printf("------------------------------------------------\n");
 	printf("1.增加学生信息---------------------------------\n");
 	printf("2.查询学生信息----------------------------------\n");
 	printf("3.修改学生信息----------------------------------\n");
 	printf("4.删除学生信息----------------------------------\n");
 	printf("------------------------------------------------\n");
 	printf("-输入您想要使用的功能------------------------\n");
 	printf("------------------------------------------------\n");
 }
