#include<iostream>

using namespace std;
int flag=0;
void print(){
	if(flag){
		cout<<" ";
	}flag=1;
}
int main(){
	string s;
	cin>>s;
	char stack[50];
	int top=0;
	for(int i=0;i<s.length();i++){
		//������������� 
		if((s[i]=='+'||s[i]=='-')&&(i==0||s[i-1]=='(')||(s[i]>='0'&&s[i]<='9')){
			print();
			if(s[i]!='+'){
				cout<<s[i];
			}
			while(s[i+1]=='.'||(s[i+1]>='0'&&s[i+1]<='9')){
				cout<<s[++i];
			}
		}else{//������Ų��� 
			if(s[i]==')'){
				while(top && stack[top-1] != '('){
                    print();
                    putchar(stack[--top]);
                }
                //���ջ��Ϊ��
                if(top)  --top;  //������ֻ��ջ�������
				
			}
			else{
		
			if(!top){//�վͽ�ȥ 
				stack[top++] = s[i];
				continue;
			}
			while(top && stack[top-1] != '('){
				if(s[i] =='('|| (s[i]=='*'||s[i]=='/')&&(stack[top-1]=='-'||stack[top-1]=='+')){
					break;
				}
				print();
				cout<<stack[--top];
			}
			stack[top++]=s[i];
		}
	}
	}
	while(top){
		print();
		if(stack[top-1]!='('){
			cout<<stack[--top];
		}
		else{
			top--;
		}
	}
	return 0;
} 
