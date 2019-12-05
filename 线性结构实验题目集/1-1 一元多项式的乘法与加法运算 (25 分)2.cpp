#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coef;       //ϵ��
    int expon;      //ָ��
    struct Node *link;     //ָ����һ���ڵ��ָ��
}PolyNode;

typedef PolyNode *PtrToNode;	//ָ��ڵ��ָ��
typedef PolyNode *Polynomial;		//����ʽ

//����һ��β�ڵ�
void Attach(int c, int e, PtrToNode *pRear);        //���������������Ӧ���ǽڵ�ָ��ĵ�ַ
//�ӱ�׼�����л�ö���ʽ
Polynomial GetPoly();
//���
void DisplayPoly(Polynomial p);
//����ʽ�ӷ�
Polynomial PolyAdd(Polynomial p1, Polynomial p2);
//����ʽ�˷�
Polynomial PolyMulti(Polynomial p1,Polynomial p2);
//���ٴ洢����ʽ������ռ�
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
    //������ͷ�ڵ㣬����ͷţ����ڲ������
    PolyNode *front, *rear, *temp;  //������ʶ����Ҫ��*��ע��temp
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
    front = front->link;		//frontָ���һ���洢����ʽ�Ľڵ�
    free(temp);		//�ͷ�ͷ�ڵ�
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
	//��ʼ���ڵ�
    PolyNode *p = (PolyNode *)malloc(sizeof(PolyNode));
    p->coef = c;
    p->expon = e;
    p->link = NULL;
    
    //����β��
    (*pRear)->link = p;
    //�ƶ�β�ڵ�
    *pRear = p;
}

Polynomial PolyAdd(Polynomial p1, Polynomial p2){
    PolyNode *front, *rear, *temp;
    int sum;
    rear = (PolyNode *)malloc(sizeof(PolyNode));
    front = rear;
    while(p1 && p2){
        if(p1->expon > p2->expon){		//���p1�ڵ��ָ����������β�ڵ����
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->link;
        }else if(p1->expon < p2->expon){		
            Attach(p2->coef, p2->expon,&rear);
            p2 = p2->link;
        }else{								//���ָ����ͬ
            sum = p1->coef + p2->coef;		//ϵ�����
            if(sum)
                Attach(sum, p1->expon, &rear);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    
	//��ʣ�µĽڵ����β��
    for(; p1; p1 = p1->link)
        Attach(p1->coef, p1->expon, &rear);
    for(; p2; p2 = p2->link)
        Attach(p2->coef, p2->expon, &rear);
    rear->link = NULL;      //p1,p2��Ϊ��ʱ��Ҫ
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
        DestroyList(temp);      //�ǵ��ͷ��м�������ڴ�
        free(front);
    }
    return p;
}

void DestroyList(Polynomial p){
    PtrToNode temp;
    while(p){		//p��ΪNULL
        temp = p;
        p = p->link;
        free(temp);
    }
}


