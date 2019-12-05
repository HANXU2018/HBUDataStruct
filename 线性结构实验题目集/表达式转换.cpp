#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(){
    static int flag = 0;
    if(flag)  putchar(' ');
    flag++;
}
int main(){
    char stack[50];
    char str[50];
    scanf("%s", str);
    int len = strlen(str);
    int top = 0;//压栈之后top++，所以每一次top都是栈顶的下一个位置
    for(int i = 0; i<len; i++){
        //处理运算数(此处的+ -表示正负，而非加减
        if((str[i] == '+' || str[i] == '-') && (!i || str[i - 1] == '(') || (str[i] >= '0' && str[i] <= '9')){
            print();
            if(str[i] != '+')   putchar(str[i]);
            while(str[i + 1] == '.' || (str[i + 1] >= '0' && str[i + 1] <= '9'))
                putchar(str[++i]);
        }
        else{
            //处理运算符
            if(str[i] == ')'){//遇到右括号，则需要将左括号前的运算符全部弹栈输出
                while(top && stack[top-1] != '('){
                    print();
                    putchar(stack[--top]);
                }
                //如果栈不为空
                if(top)  --top;  //左括号只弹栈，不输出
            }
            else{
                if(!top){   //栈为空，无须比较，直接压栈
                    stack[top++] = str[i];
                    continue;
                }
                //根据优先级顺序，压栈||(弹栈后压栈)
                while(top && stack[top-1] != '('){
                    //比较优先级，如果str[i]的优先级大于栈顶运算符的优先级，直接压栈
                    if(str[i] == '(' || ((str[i] == '*' || str[i] == '/') && (stack[top-1] == '-' || stack[top-1] == '+')))
                        break;
                    print();
                    //如果str[i]的优先级小于栈顶的优先级，弹栈，之后再把str[i]压栈
                    printf("%c", stack[--top]);
                }
                stack[top++] = str[i];
            }
        }
    }
    while(top){ //所有运算数均已操作完毕，最后将栈中剩余的操作符全部输出
        print();
        //左括号不输出
        if(stack[top-1] != '(')
            putchar(stack[--top]);
        else    top--;
    }
    return 0;
}