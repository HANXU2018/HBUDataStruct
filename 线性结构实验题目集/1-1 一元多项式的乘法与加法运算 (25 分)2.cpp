#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coef;       //系数
    int expon;      //指数
    struct Node *link;     //指向下一个节点的指针
}PolyNode;

typedef PolyNode *PtrToNode;	//指向节点的指针
typedef PolyNode *Polynomial;		//多项式

//增加一个尾节点
void Attach(int c, int e, PtrToNode *pRear);        //第三个参数传入的应该是节点指针的地址
//从标准输入中获得多项式
Polynomial GetPoly();
//输出
void DisplayPoly(Polynomial p);
//多项式加法
Polynomial PolyAdd(Polynomial p1, Polynomial p2);
//多项式乘法
Polynomial PolyMulti(Polynomial p1,Polynomial p2);
//销毁存储多项式的链表空间
void DestroyList(Polynomial p);

int main()
{
    Polynomial p1 = GetPoly();
    Polynomial p2 = GetPoly();
    Polynomial pm = PolyMulti(p1, p2);
    DisplayPoly(pm);
    putchar('\n');
    Polynomial pa = PolyAdd(p1, p2);
    DisplayPoly(pa);

    DestroyList(p1);
    DestroyList(p2);
    DestroyList(pm);
    DestroyList(pa);

    return 0;
}

Polynomial GetPoly(){
    int n;
    scanf("%d",&n);
    //先申请头节点，最后释放，易于插入操作
    PolyNode *front, *rear, *temp;  //三个标识符都要带*，注意temp
    rear = (PolyNode *)malloc(sizeof (PolyNode));
    front = rear;
    for(int i = 0; i < n; i ++){
        rear->link = (PolyNode *)malloc(sizeof(PolyNode));
        rear = rear->link;
        scanf("%d",&(rear->coef));
        scanf("%d",&(rear->expon));
    }
    rear->link = NULL;
    temp = front;
    front = front->link;		//front指向第一个存储多项式的节点
    free(temp);		//释放头节点
    return front;
}

void DisplayPoly(Polynomial p){
    if(p == NULL){
        printf("0 0");
        return;
    }
    else
        printf("%d %d",p->coef,p->expon);
    p = p->link;
    for(; p; p = p->link)
        printf(" %d %d",p->coef,p->expon);
}

void Attach(int c, int e, PtrToNode *pRear){
	//初始化节点
    PolyNode *p = (PolyNode *)malloc(sizeof(PolyNode));
    p->coef = c;
    p->expon = e;
    p->link = NULL;
    
    //插入尾部
    (*pRear)->link = p;
    //移动尾节点
    *pRear = p;
}

Polynomial PolyAdd(Polynomial p1, Polynomial p2){
    PolyNode *front, *rear, *temp;
    int sum;
    rear = (PolyNode *)malloc(sizeof(PolyNode));
    front = rear;
    while(p1 && p2){
        if(p1->expon > p2->expon){		//如果p1节点的指数大，先连到尾节点后面
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->link;
        }else if(p1->expon < p2->expon){		
            Attach(p2->coef, p2->expon,&rear);
            p2 = p2->link;
        }else{								//如果指数相同
            sum = p1->coef + p2->coef;		//系数相加
            if(sum)
                Attach(sum, p1->expon, &rear);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    
	//将剩下的节点插入尾部
    for(; p1; p1 = p1->link)
        Attach(p1->coef, p1->expon, &rear);
    for(; p2; p2 = p2->link)
        Attach(p2->coef, p2->expon, &rear);
    rear->link = NULL;      //p1,p2都为空时需要
    temp = front;
    front = front->link;
    free(temp);
    return front;
}


Polynomial PolyMulti(Polynomial p1,Polynomial p2){
    Polynomial p = NULL;
    Polynomial t1;
    Polynomial t2;
    for(t1 = p1; t1; t1 = t1->link){
        PtrToNode front, rear, temp;
        rear = (PolyNode *)malloc(sizeof(PolyNode));
        front = rear;
        for(t2 = p2; t2; t2 = t2->link)
            Attach(t1->coef * t2->coef,t1->expon + t2->expon,&rear);
        rear->link = NULL;
        temp = p;
        p = PolyAdd(p,front->link);
        DestroyList(temp);      //记得释放中间申请的内存
        free(front);
    }
    return p;
}

void DestroyList(Polynomial p){
    PtrToNode temp;
    while(p){		//p不为NULL
        temp = p;
        p = p->link;
        free(temp);
    }
}


