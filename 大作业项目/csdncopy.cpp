//
//  HBUУ԰����.c
//  HBUУ԰����
//
//  Created by ���Ӽ� 20181101200 on 2019/11/16.
//  Copyright ? 2019 ���Ӽ�. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxVerNum 100
#define PASSWORD "1234567"
#define INFINITY 1000000
#define DELAY 982337369
#define CONFIRMATION "QUEREN"
void showInfo(void);//������о���
void Visiter(void);//�ο�ϵͳ
void Administrator(void);//����Աϵͳ
void introduct(void);//�������
void Dijkstra(void);//�����ο����ھ�������������ľ���
void Floyd(void);//�����ο�ָ�����������������·������
void modifyInfo(void);//�޸ľ�����Ϣ
void addInfo(void);//��Ӿ���
void delInfo(void);//ɾ������
void addPath(void);//��ӵ�·
void delPath(void);//ɾ����·
typedef struct {
    int num;
    char name[100];
    char features[1000];
}VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MaxVerNum];
    EdgeType edges[MaxVerNum][MaxVerNum];
    int n;
    int e;
}MGraph;
MGraph HBUmap;
int flag = 1;
void showInfo(void)
{
    printf("��ǰϵͳ���Ѿ�¼��ľ������£�\n");
    for(int i = 0;i<HBUmap.n;i++)
        printf("%d : %s\n",i+1,HBUmap.vexs[i].name);
}
void create(void)
{
    HBUmap.n = 12;
    HBUmap.e = 20;
    for(int i = 0;i<MaxVerNum;i++)
    {
        HBUmap.vexs[i].num = i+1;
    }
    for(int i = 0;i<MaxVerNum;i++)
        for(int j = 0;j<MaxVerNum;j++)
            HBUmap.edges[i][j] = INFINITY;
    strcpy(HBUmap.vexs[0].name, "�ٳ�");
    strcpy(HBUmap.vexs[0].features, "�ӱ���ѧ������λ�ڱ�������������һ��·�ӱ���ѧ��У���ڣ��Ǳ����ݴ�����ӱ��������أ�Ҳ�����ӱ���ѧ��ѧ�������2016��11����Ѯ��ʼ��Ԥ��2017��3�µ��깤�����¿�ʼͶ��ʹ�á��ɱ������������ӱ���ѧ���ݴ������Ϲ�����");
    strcpy(HBUmap.vexs[1].name, "ͼ���");
    strcpy(HBUmap.vexs[1].features, "�ӱ���ѧͼ�����λ�ڱ����кӱ���ѧ��У���ڣ�ԭ�ӱ���ѧͼ��ݡ������������ʼ����1921�꣬�Ƿ��������̻�����򴴰�Ĺ��̴�ѧ�����ͼ��ݡ��������32846ƽ���ף��ݲ�ͼ��390����ᣬ�ǹ���Ժ��׼�Ļ���ȷ����ȫ���ż��ص㱣����λ֮һ���ھ���ȫ�򻯡����֪ʶ������Ϣ���ֻ���ʱ������Ϣ��Դ����Ĵ�͸�����Ѿ���Ϊ�ִ���ѧ��ѧ���еĺ���֧����������һ���ߵ�ԺУ��˵��û�и�Ч�걸���ִ���ͼ��ݺ�ͼ���鱨��Ϣ���񣬾Ͳ����ܽ���������ʵ����г��չ���ִ�����ѧ�����źӱ���ѧ�Ŀ��ٷ�չ���ӱ���ѧͼ����������о��͡��߲�λ���ִ���ͼ���Ŀ��������");
    strcpy(HBUmap.vexs[2].name, "�������");
    strcpy(HBUmap.vexs[2].features, "�ӱ���ѧ����������ɺӱ�ʡ�������ܲ�����׼�Ĵ���רҵ����������������Ͷ��4000��Ԫ�����ṩ������졢������ѯ��ҽ�Ʒ���Ϊ��ּ���Ƚ��ļ����豸�������ҽ��ר�Ҷ���ʹ�����ĵ����ˮ׼����ʡ��ͬ��ҵǰ�С�");
    strcpy(HBUmap.vexs[3].name, "У�ű���");
    strcpy(HBUmap.vexs[3].features, "�ӱ���ѧ��У��У�ű��ڸ����Ƿḻ��ʵ�У԰�Ļ�����������ʳ�������������Ϊһ�壬�ḻ���ʦ�����ܱ߾����ҵ�����");
    strcpy(HBUmap.vexs[4].name, "���Ӿ���");
    strcpy(HBUmap.vexs[4].features, "���������Ҷ����һ�ֱ�������������������������ȵĹ���������һ�����ţ�ӡȾ����ա�ӡȾ��ÿһ���Ӵ�ѧ�ӵ��ġ����۴���������ص������ѳ�Ϊһ�ֱ�־���Ӵ�����ר���ı�־��������һ�������������Ŵ󱣶��ĵ�һ��ѩ�������٣�Ҳ������һ�����ȵ��ֻء�");
    strcpy(HBUmap.vexs[5].name, "����������");
    strcpy(HBUmap.vexs[5].features, "�����������Ǻӱ���ѧ�ٰ����ֻ�ĳ��������ݿ�����1500��ѧ���������ڻ��д����ݳ��ᡣ");
    strcpy(HBUmap.vexs[6].name, "����");
    strcpy(HBUmap.vexs[6].features, "ѧУʳ��������һ�������²ۡ�������������ҵ������ĵط����ںӱ���ѧ������ѧ����¥����������ʱ��Ԫ�صľͲ������и�����ɫ���Ⱥ�С�ԣ��ϰ������͡����Ϻ���㡣����ʳ��ɢ����Ũ��������С����飬��������װ������ɫ�������Ӧ���컨���ϵ����ε��ι�ҵ��ʮ�㡣");
    strcpy(HBUmap.vexs[7].name, "��԰����");
    strcpy(HBUmap.vexs[7].features, "��Ҳ��֪�����������ɶ�ɽ��ܵ�");
    strcpy(HBUmap.vexs[8].name, "У�Ŷ���");
    strcpy(HBUmap.vexs[8].features, "У�Ŷ��ڽ����Ͻ֣����������С�ԡ�");
    strcpy(HBUmap.vexs[9].name, "��Ϣѧ��");
    strcpy(HBUmap.vexs[9].features, "��Ϣ��ѧ�빤��ѧ���Ǻӱ���ѧ����ѧԺΨһ������ѧ����������2001�꣬��������������14�죬�б�ҵ��10�죬Ŀǰ����15��רҵ������9������ѧ���࣬������У��4100���ˣ�58�������ࡣ");
    strcpy(HBUmap.vexs[10].name, "����ѧԺ");
    strcpy(HBUmap.vexs[10].features, "�ӱ���ѧ�������ѧ�뼼��ѧԺ��2017��9����ʽ����Ϊ�ӱ���ѧ����ռ䰲ȫ������ѧԺ��ѧԺǰ���׷�ݵ�ʼ����1982��ļ������Ӧ�ñ���רҵ���Ǻӱ�ʡ��������ļ����רҵ������20����50������ӱ���ѧ�ͳɹ����Ƴ��ҹ���һ̨ģ����Ӽ������1979�꣬�ֳɹ����Ƴ���ʡΨһһ̨���͵��Ӽ������1993���ӱ�ʡ��һ���������Ӧ�ü�����˶ʿѧλ��Ȩ��.");
    strcpy(HBUmap.vexs[11].name, "У���Ͽ�");
    strcpy(HBUmap.vexs[11].features, "�ӱ���ѧУ�Ŷ������й���վ�㣬����ʡ��������ʦ���ĳ���");
    HBUmap.edges[0][2] = HBUmap.edges[2][0] = 350;
    HBUmap.edges[0][5] = HBUmap.edges[5][0] = 480;
    HBUmap.edges[0][1] = HBUmap.edges[1][0] = 280;
    HBUmap.edges[0][3] = HBUmap.edges[3][0] = 200;
    HBUmap.edges[3][4] = HBUmap.edges[4][3] = 100;
    HBUmap.edges[3][6] = HBUmap.edges[6][3] = 100;
    HBUmap.edges[4][6] = HBUmap.edges[6][4] = 100;
    HBUmap.edges[2][5] = HBUmap.edges[5][2] = 200;
    HBUmap.edges[1][5] = HBUmap.edges[5][1] = 400;
    HBUmap.edges[1][7] = HBUmap.edges[7][1] = 160;
    HBUmap.edges[1][8] = HBUmap.edges[8][1] = 300;
    HBUmap.edges[6][8] = HBUmap.edges[8][6] = 100;
    HBUmap.edges[5][9] = HBUmap.edges[9][5] = 500;
    HBUmap.edges[11][10] = HBUmap.edges[10][11] = 400;
    HBUmap.edges[11][9] = HBUmap.edges[9][11] = 400;
    HBUmap.edges[11][7] = HBUmap.edges[7][11] = 500;
    HBUmap.edges[11][8] = HBUmap.edges[8][11] = 600;
    HBUmap.edges[10][5] = HBUmap.edges[5][10] = 500;
    HBUmap.edges[9][7] = HBUmap.edges[7][9] = 150;
    HBUmap.edges[8][7] = HBUmap.edges[7][8] = 200;
}
void modifyInfo(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    showInfo();
    int a;
    printf("��������Ҫ�޸���Ϣ�ľ����ţ�\n");
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d",&a);
    }
    char newName[100];
    char newFeatures[1000];
    printf("�þ��㵱ǰ������Ϊ%s,������˾�����ĺ�����֣�\n",HBUmap.vexs[a-1].name);
    scanf("%s",newName);getchar();
    printf("�þ��㵱ǰ����Ϣ���Ϊ��\n%s\n������˾�����ĺ����Ϣ��飺\n",HBUmap.vexs[a-1].features);
    scanf("%s",newFeatures);getchar();
    printf("�����޸ľ�����Ϣ...\n");
    strcpy(HBUmap.vexs[a-1].name, newName);
    strcpy(HBUmap.vexs[a-1].features, newFeatures);
    for(long long i = 0;i<DELAY ;i++);
    printf("������Ϣ�޸ĳɹ���\n");
    printf("�����Ƿ������������������Ϣ����������1�������������ּ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        modifyInfo();
}
void addInfo(void)
{
    //system("clear");
    if(HBUmap.n >= MaxVerNum)
    {
        printf("�����������޷�����ӣ�\n");
        return;
    }
    showInfo();
    char newName[100];char newFeatures[500];
    printf("��������Ҫ���ӵľ������ƣ�\n");
    scanf("%s",newName);getchar();
    printf("������%s�ľ�����Ϣ��飬���ɶ���200�֣�\n",newName);
    scanf("%s",newFeatures);getchar();
    showInfo();
    int m;
    printf("������������������ھ��������\n");
    scanf("%d",&m);
    for(int i = 0;i<m;i++)
    {
        int a,distance;
        printf("������%s�ĵ�%d�����ھ���ı��:\n",newName,i+1);
        scanf("%d",&a);
        while(a<1 || a>HBUmap.n || HBUmap.edges[a-1][HBUmap.n] != INFINITY)
        {
            if(a<1 || a>HBUmap.n)
            {
                printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
                scanf("%d",&a);
            }
            if(HBUmap.edges[a-1][HBUmap.n] != INFINITY)
            {
                printf("���ظ��������ھ��㣬�������룡\n");
                scanf("%d",&a);
            }
        }
        printf("������%s��%s֮��ľ���:\n",newName,HBUmap.vexs[a-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance>INFINITY)
        {
            printf("���������������������룡\n");
            scanf("%d",&distance);
        }
        HBUmap.edges[a-1][HBUmap.n] = HBUmap.edges[HBUmap.n][a-1] = distance;
    }
    printf("������Ӿ���...\n");
    strcpy(HBUmap.vexs[HBUmap.n++].name,newName);
    strcpy(HBUmap.vexs[HBUmap.n-1].features,newFeatures);
    HBUmap.e += m;
    for(long long i = 0;i<DELAY ;i++);
    printf("������ӳɹ���\n");
    printf("�����Ƿ���������������㣿��������1�������������ּ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        addInfo();
}
void delInfo(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬�޷�ɾ����\n");
        return;
    }
    showInfo();
    printf("��������Ҫɾ���ľ����ţ�\n");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("��Ҫɾ���ľ�������Ϊ��%s���Ƿ�ȷ��ɾ���þ��㣿ȷ��������1 \n",HBUmap.vexs[a-1].name);
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
    {
        printf("����ɾ������...\n");
        int i,j;
        int count = 0;
        for(i = 0;i<HBUmap.n;i++)
            if(HBUmap.edges[a-1][i] != INFINITY)
                count++;
        for(i = a-1;i<HBUmap.n;i++)
            HBUmap.vexs[i] = HBUmap.vexs[i+1];
        for(i = 0;i<HBUmap.n;i++)
            for(int j = a-1;j<HBUmap.n;j++)
                HBUmap.edges[i][j] = HBUmap.edges[i][j+1];
        for(i = 0;i<HBUmap.n;i++)
            for(j = a-1;j<HBUmap.n;j++)
                HBUmap.edges[j][i] = HBUmap.edges[j+1][i];
        HBUmap.n--;
        HBUmap.e -= count;
    }
    else
        return;
    for(long long i = 0;i<DELAY ;i++);
    printf("����ɾ���ɹ���\n");
    printf("�����Ƿ����ɾ���������㣿��������1�������������ּ����˳�\n");
    int f;
    scanf("%d",&f);
    if(f == 1)
        delInfo();
}
void addPath(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    showInfo();
    if(HBUmap.e == 0)
        printf("��ǰ��ͼ���޵�·\n");
    else
        printf("Ŀǰ�ܹ���%d����·\n",HBUmap.e);
    printf("������Ҫ���ӵ�·�����������ţ�\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("��������������ͬ��ţ��������룡\n");
        else
            printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] != INFINITY){
        printf("%s��%s֮���Ѿ����е�·���޷�����ӣ�\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        int distance;
        printf("������%s��%s֮���·�ĳ��ȣ�\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance >= INFINITY)
        {
            printf("���������������������룡\n");
            scanf("%d",&distance);
        }
        printf("������ӵ�·...\n");
        HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = distance;
        HBUmap.e++;
        for(long long i = 0;i<DELAY ;i++);
        printf("��·��ӳɹ���\n");
    }
    printf("�����Ƿ��������������·����������1�������������ּ����˳�\n");
    int f;
    scanf("%d",&f);
    if(f == 1)
        addPath();
}
void delPath(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    if(HBUmap.e <= 0)
    {
        printf("��ͼ�����κε�·��������ӵ�·��\n");
        return;
    }
    showInfo();
    printf("Ŀǰ�ܹ���%d����·\n",HBUmap.e);
    printf("������Ҫɾ����·�����������ţ��м��ÿո������\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("��������������ͬ��ţ��������룡\n");
        else
            printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] == INFINITY)
    {
        printf("%s��%s֮���޵�·��\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        printf("��Ҫɾ������%s��%s֮��ĵ�·���Ƿ�ȷ��ɾ��������·��ȷ��������1 \n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        int flag;
        scanf("%d",&flag);
        if(flag == 1)
        {
            printf("����ɾ����·...\n");
            HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = INFINITY;
            HBUmap.e--;
            for(long long i = 0;i<DELAY ;i++);
            printf("��·ɾ���ɹ���\n");
        }
        else
            return;
    }
    printf("�����Ƿ����ɾ��������·����������1�������������ּ����˳�\n");
    int f;
    scanf("%d",&f);
    if(f == 1)
        delPath();
}
void introduct(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    showInfo();
    printf("����������Ҫ�˽�ľ�����:");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("%s\n",HBUmap.vexs[a-1].features);
    printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        introduct();
}
void Dijkstra(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    showInfo();
    printf("�����������ڵľ�����:");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d",&a);
    }
    int final[MaxVerNum];
    int P[MaxVerNum];
    int D[MaxVerNum];
    int i,j = 0,k,min,pre;
    final[a-1] = 1;
    for(int i = 0;i<HBUmap.n;i++)
    {
        D[i] = HBUmap.edges[a-1][i];
        P[i] = a-1;
    }
    D[a-1] = 0;final[a-1] = 1;P[a-1] = -1;
    for(i = 1;i<HBUmap.n;i++)
    {
        min = INFINITY+1;
        for(k = 0;k<HBUmap.n;k++)
            if(final[k] == 0 && D[k]<min)
            {
                j = k;
                min = D[k];
            }
        final[j] = 1;
        for(k = 0;k<HBUmap.n;k++)
            if(final[k] == 0 && (D[j]+HBUmap.edges[j][k] < D[k]))
            {
                D[k] = D[j]+HBUmap.edges[j][k];
                P[k] = j;
            }
    }
    for(i = 0;i<HBUmap.n;i++)
    {
        if(i!=a-1)
        {
            if(D[i] != INFINITY)
            {
                printf("%d�� : %s",D[i],HBUmap.vexs[i].name);
                pre = P[i];
                while (pre >= 0)
                {
                    printf("<-%s",HBUmap.vexs[pre].name);
                    pre = P[pre];
                }
                printf("\n");
            }
        }
    }
    printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        Dijkstra();
}
void Floyd(void)
{
    //system("clear");
    if(HBUmap.n <= 0)
    {
        printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
        return;
    }
    showInfo();
    int path[MaxVerNum][MaxVerNum];
    int dist[MaxVerNum][MaxVerNum];
    int i,j,k;
    int temp;
    for(int i = 0;i<HBUmap.n;i++)
        for(j=0;j<HBUmap.n;j++)
        {
            dist[i][j] = HBUmap.edges[i][j];
            path[i][j] = j;
        }
    for(k=0;k<HBUmap.n;k++)
        for(i=0;i<HBUmap.n;i++)
            for(j=0;j<HBUmap.n;j++)
            {
                temp = (dist[i][k] == INFINITY || dist[k][j] == INFINITY) ? INFINITY : (dist[i][k] + dist[k][j]);
                if(dist[i][j] > temp)
                {
                    dist[i][j] = temp;
                    path[i][j] = k;
                }
            }
    int a,b;
    printf("��������Ҫ��ѯ֮���������������ţ��м��ÿո������\n");
    scanf("%d %d",&b,&a);
    while(a<1 || a>HBUmap.n|| b<1 || b>HBUmap.n || a == b)
    {
         if(a == b)
            printf("��������������ͬ��ţ��������룡\n");
         else
            printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
         scanf("%d %d",&b,&a);
    }
    if(dist[a-1][b-1] == INFINITY)
    {
        printf("%s��%s֮����·����\n",HBUmap.vexs[b-1].name,HBUmap.vexs[a-1].name);
        return;
    }
    else
    {
    	printf("%s��%s�����·������Ϊ��%d��\n",HBUmap.vexs[b-1].name,HBUmap.vexs[a-1].name,dist[a-1][b-1]);
        printf("·��Ϊ��%s",HBUmap.vexs[b-1].name);
        if(path[a][b] == b) printf("->%s\n",HBUmap.vexs[a-1].name);
        else
        {
            k = b-1;
            while(path[a-1][k] != k)
            {
                k = path[a-1][k];
                printf("->%s",HBUmap.vexs[k].name);
            }
            printf("->%s",HBUmap.vexs[a-1].name);
        }
        printf("\n");
    }
    printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        Floyd();
}
void Visiter(void)
{
    //system("clear");
    while(1)
    {
        int a;
        printf("��ӭ�����ο�ϵͳ����������Ҫ���еĲ���:\n");
        printf("1.������� 2.���������ڵľ��㵽������������·�� 3.����������������֮������·�� 4.�˳��ο�ϵͳ\n");
        scanf("%d",&a);
        switch (a) {
            case 1:
                introduct();
                break;
            case 2:
                Dijkstra();
                break;
            case 3:
                Floyd();
                break;
            case 4:
                return;
            default:
                printf("�����������������룡\n");
                break;
        }
    }
}
void Administrator(void)
{
    //system("clear");
    while(1)
    {
        int a;
        printf("��ӭ�������ϵͳ����������Ҫ���еĲ���:\n");
        printf("1.������� 2.���������ڵľ��㵽������������·�� 3.����������������֮������·�� 4.�޸ľ�����Ϣ 5.���Ӿ�����Ϣ 6.ɾ��������Ϣ 7.���ӵ�· 8.ɾ����· 9.�˳�����ϵͳ 0.�ָ���ʼ����\n");
        scanf("%d",&a);
        switch (a) {
            case 0:
                printf("ȷ��Ҫ�ָ���ʼ������ȷ��������1�������������ּ��ɷ��ء�\n");
                int flag;
                scanf("%d",&flag);
                if(flag == 1)
                {
                    printf("���ڻָ�...\n");
                    for(long long i = 0;i < DELAY;i++);
                    create();
                    printf("���ݻָ���ϣ�\n");
                    break;
                }
                else
                    Administrator();
                    break;
            case 1:
                introduct();
                break;
            case 2:
                Dijkstra();
                break;
            case 3:
                Floyd();
                break;
            case 4:
                modifyInfo();
                break;
            case 5:
                addInfo();
                break;
            case 6:
                delInfo();
                break;
            case 7:
                addPath();
                break;
            case 8:
                delPath();
                break;
            case 9:
                return;
            default:
                printf("�����������������룡\n");
                break;
        }
    }
}
int main()
{
    create();
    //system("clear");
    int a;
    printf("�ӱ���ѧ�ǽ�������ӱ�ʡ������������ʡ�Ͻ�����У��Ҳ�Ǻӱ�ʡ�ص�֧�ֵĹ���һ����ѧ����һ��θ�У��\n***        ��ӭ�����ٺӱ���ѧ��У����       ***\n");
    while(1){
    printf("***           �������������            ***\n1.�ο� 2.����Ա 0.�˳�ϵͳ\n");
    scanf("%d",&a);
    switch (a) {
        case 1:
            Visiter();
            break;
        case 2:
            if(flag)
            {
            printf("���������Ա���룬���������ο�ϵͳ��ֱ������1��\n");
            char password[20];
            scanf("%s",password);getchar();
            if(strcmp(password, "1") == 0)
            {
                Visiter();
                break;
            }
            int count = 0;
            while(strcmp(password, PASSWORD) != 0)
            {
                count++;
                if(count >= 3)
                {
                    flag = 0;
                    printf("�����������ﵽ���Σ�����Ա�˻��ѱ�����������ϵѧУ���н���!\n");
                    break;
                }
                printf("��������������������룬���������������������룬����Ա�˻�����������\n");
                scanf("%s",password);
            }
            }
            else
                 printf("�����������ﵽ���Σ�����Ա�˻��ѱ�����������ϵѧУ���н���!\n");
            if(flag)
                Administrator();
            break;
        case 0:
            printf("�˳����������ݽ��ָ�ԭʼ״̬���༭������ݻᶪʧ���Ƿ�ȷ�ϣ����ȷ�ϣ������·����롰QUEREN������д���������ȷ�ϣ����������������ݼ��ɷ��ء�\n");
            char code[100];
            scanf("%s",code);getchar();
            if(strcmp(code, CONFIRMATION) == 0)
            {
                printf("��лʹ�ã��´��ټ���\nCreated by ���Ӽ� ѧ�ţ�20181101200 2019��11��16�� All rights reserved.\n");
                return 0;
            }
            else
                continue;
        default:
            printf("�����������������룡\n");
            continue;
        }
    }
    return 0;
}


