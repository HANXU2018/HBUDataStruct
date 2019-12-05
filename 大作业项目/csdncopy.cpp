//
//  HBU校园导航.c
//  HBU校园导航
//
//  Created by 齐子佳 20181101200 on 2019/11/16.
//  Copyright ? 2019 齐子佳. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxVerNum 100
#define PASSWORD "1234567"
#define INFINITY 1000000
#define DELAY 982337369
#define CONFIRMATION "QUEREN"
void showInfo(void);//输出所有景点
void Visiter(void);//游客系统
void Administrator(void);//管理员系统
void introduct(void);//景点介绍
void Dijkstra(void);//查找游客所在景点与其他景点的距离
void Floyd(void);//查找游客指定的两个景点间的最短路径长度
void modifyInfo(void);//修改景点信息
void addInfo(void);//添加景点
void delInfo(void);//删除景点
void addPath(void);//添加道路
void delPath(void);//删除道路
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
    printf("当前系统中已经录入的景点如下：\n");
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
    strcpy(HBUmap.vexs[0].name, "操场");
    strcpy(HBUmap.vexs[0].features, "河北大学体育场位于保定市莲池区七一东路河北大学新校区内，是保定容大足球队比赛主场地，也用作河北大学教学。建设从2016年11月中旬开始，预计2017年3月底完工，四月开始投入使用。由保定市政府、河北大学、容大集团联合共建。");
    strcpy(HBUmap.vexs[1].name, "图书馆");
    strcpy(HBUmap.vexs[1].features, "河北大学图书馆现位于保定市河北大学新校区内，原河北大学图书馆——北疆博物馆始建于1921年，是法国天主教会在天津创办的工商大学附设的图书馆。建筑面积32846平方米，馆藏图书390万余册，是国务院批准文化部确定的全国古籍重点保护单位之一。在经济全球化、社会知识化、信息数字化的时代，信息资源无穷的穿透力，已经成为现代大学教学科研的核心支撑力。对于一所高等院校来说，没有高效完备的现代化图书馆和图书情报信息服务，就不可能建成名副其实、和谐发展的现代化大学，随着河北大学的快速发展，河北大学图书馆正朝着研究型、高层位的现代化图书馆目标迈进。");
    strcpy(HBUmap.vexs[2].name, "体检中心");
    strcpy(HBUmap.vexs[2].features, "河北大学体检中心是由河北省卫生主管部门批准的大型专业健康体检机构，中心投资4000万元，以提供健康体检、保健咨询和医疗服务为宗旨。先进的技术设备和优秀的医疗专家队伍使本中心的体检水准立于省内同行业前列。");
    strcpy(HBUmap.vexs[3].name, "校门北口");
    strcpy(HBUmap.vexs[3].features, "河北大学新校区校门北口附近是丰富多彩的校园文化场所，集美食、购物、健身、娱乐为一体，丰富广大师生及周边居民的业余生活。");
    strcpy(HBUmap.vexs[4].name, "银杏景观");
    strcpy(HBUmap.vexs[4].features, "秋天的银杏叶有着一种饱满成熟的美，积攒了三个季度的功力就在这一刻绽放，印染了天空、印染了每一个河大学子的心。景观大道泛黄满地的银杏已成为一种标志，河大新区专属的标志。它更是一种象征，象征着大保定的第一场雪即将来临，也象征着一个季度的轮回。");
    strcpy(HBUmap.vexs[5].name, "邯郸音乐厅");
    strcpy(HBUmap.vexs[5].features, "邯郸音乐厅是河北大学举办音乐活动的场所，场馆可容纳1500名学生，不定期会有大型演唱会。");
    strcpy(HBUmap.vexs[6].name, "餐厅");
    strcpy(HBUmap.vexs[6].features, "学校食堂向来是一个新生吐槽、老生淡定、毕业生怀念的地方。在河北大学的坤舆学生三楼餐厅，充满时尚元素的就餐区，有各地特色菜肴和小吃，上百种正餐、饮料和甜点。整个食堂散发着浓郁的主题小镇风情，室内蓝白装饰与亮色桌椅相呼应，天花板上的菱形灯饰工业风十足。");
    strcpy(HBUmap.vexs[7].name, "花园景观");
    strcpy(HBUmap.vexs[7].features, "我也不知道这个景点有啥可介绍的");
    strcpy(HBUmap.vexs[8].name, "校门东口");
    strcpy(HBUmap.vexs[8].features, "校门东口紧邻南街，附近有许多小吃。");
    strcpy(HBUmap.vexs[9].name, "信息学部");
    strcpy(HBUmap.vexs[9].features, "信息科学与工程学部是河北大学工商学院唯一的理工科学部，成立于2001年，至今已连续招生14届，有毕业生10届，目前设置15个专业，所属9个二级学科类，现有在校生4100余人，58个行政班。");
    strcpy(HBUmap.vexs[10].name, "网计学院");
    strcpy(HBUmap.vexs[10].features, "河北大学计算机科学与技术学院于2017年9月正式更名为河北大学网络空间安全与计算机学院。学院前身可追溯到始建于1982年的计算机及应用本科专业，是河北省建立最早的计算机专业。早在20世纪50年代，河北大学就成功研制出我国第一台模拟电子计算机；1979年，又成功研制出我省唯一一台中型电子计算机；1993年获河北省第一个“计算机应用技术”硕士学位授权点.");
    strcpy(HBUmap.vexs[11].name, "校门南口");
    strcpy(HBUmap.vexs[11].features, "河北大学校门东口设有公交站点，紧邻省道，方便师生的出行");
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
        printf("地图中无任何景点，请先添加景点！\n");
        return;
    }
    showInfo();
    int a;
    printf("请输入您要修改信息的景点编号：\n");
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("编号输入有误，编号应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d",&a);
    }
    char newName[100];
    char newFeatures[1000];
    printf("该景点当前的名字为%s,请输入此景点更改后的名字：\n",HBUmap.vexs[a-1].name);
    scanf("%s",newName);getchar();
    printf("该景点当前的信息简介为：\n%s\n请输入此景点更改后的信息简介：\n",HBUmap.vexs[a-1].features);
    scanf("%s",newFeatures);getchar();
    printf("正在修改景点信息...\n");
    strcpy(HBUmap.vexs[a-1].name, newName);
    strcpy(HBUmap.vexs[a-1].features, newFeatures);
    for(long long i = 0;i<DELAY ;i++);
    printf("景点信息修改成功！\n");
    printf("请问是否继续更改其他景点信息？是请输入1，输入其他数字即可退出\n");
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
        printf("景点已满，无法再添加！\n");
        return;
    }
    showInfo();
    char newName[100];char newFeatures[500];
    printf("请输入您要增加的景点名称：\n");
    scanf("%s",newName);getchar();
    printf("请输入%s的景点信息简介，不可多于200字：\n",newName);
    scanf("%s",newFeatures);getchar();
    showInfo();
    int m;
    printf("请输入新增景点的相邻景点个数：\n");
    scanf("%d",&m);
    for(int i = 0;i<m;i++)
    {
        int a,distance;
        printf("请输入%s的第%d个相邻景点的编号:\n",newName,i+1);
        scanf("%d",&a);
        while(a<1 || a>HBUmap.n || HBUmap.edges[a-1][HBUmap.n] != INFINITY)
        {
            if(a<1 || a>HBUmap.n)
            {
                printf("编号输入有误，编号应位于1～%d之间，重新输入！\n",HBUmap.n);
                scanf("%d",&a);
            }
            if(HBUmap.edges[a-1][HBUmap.n] != INFINITY)
            {
                printf("勿重复输入相邻景点，重新输入！\n");
                scanf("%d",&a);
            }
        }
        printf("请输入%s与%s之间的距离:\n",newName,HBUmap.vexs[a-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance>INFINITY)
        {
            printf("距离输入有误！请重新输入！\n");
            scanf("%d",&distance);
        }
        HBUmap.edges[a-1][HBUmap.n] = HBUmap.edges[HBUmap.n][a-1] = distance;
    }
    printf("正在添加景点...\n");
    strcpy(HBUmap.vexs[HBUmap.n++].name,newName);
    strcpy(HBUmap.vexs[HBUmap.n-1].features,newFeatures);
    HBUmap.e += m;
    for(long long i = 0;i<DELAY ;i++);
    printf("景点添加成功！\n");
    printf("请问是否继续增加其他景点？是请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，无法删除！\n");
        return;
    }
    showInfo();
    printf("请输入您要删除的景点编号：\n");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("编号输入有误，编号应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("您要删除的景点名称为：%s，是否确认删除该景点？确认请输入1 \n",HBUmap.vexs[a-1].name);
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
    {
        printf("正在删除景点...\n");
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
    printf("景点删除成功！\n");
    printf("请问是否继续删除其他景点？是请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，请先添加景点！\n");
        return;
    }
    showInfo();
    if(HBUmap.e == 0)
        printf("当前地图中无道路\n");
    else
        printf("目前总共有%d条道路\n",HBUmap.e);
    printf("请输入要增加道路的两个景点编号：\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("请勿输入两个相同编号，重新输入！\n");
        else
            printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] != INFINITY){
        printf("%s与%s之间已经含有道路，无法再添加！\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        int distance;
        printf("请输入%s与%s之间道路的长度：\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance >= INFINITY)
        {
            printf("长度输入有误！请重新输入！\n");
            scanf("%d",&distance);
        }
        printf("正在添加道路...\n");
        HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = distance;
        HBUmap.e++;
        for(long long i = 0;i<DELAY ;i++);
        printf("道路添加成功！\n");
    }
    printf("请问是否继续增加其他道路？是请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，请先添加景点！\n");
        return;
    }
    if(HBUmap.e <= 0)
    {
        printf("地图中无任何道路，请先添加道路！\n");
        return;
    }
    showInfo();
    printf("目前总共有%d条道路\n",HBUmap.e);
    printf("请输入要删除道路的两个景点编号，中间用空格隔开：\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("请勿输入两个相同编号，重新输入！\n");
        else
            printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] == INFINITY)
    {
        printf("%s与%s之间无道路！\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        printf("您要删除的是%s与%s之间的道路，是否确认删除这条道路？确认请输入1 \n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        int flag;
        scanf("%d",&flag);
        if(flag == 1)
        {
            printf("正在删除道路...\n");
            HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = INFINITY;
            HBUmap.e--;
            for(long long i = 0;i<DELAY ;i++);
            printf("道路删除成功！\n");
        }
        else
            return;
    }
    printf("请问是否继续删除其他道路？是请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，请先添加景点！\n");
        return;
    }
    showInfo();
    printf("请输入您想要了解的景点编号:");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("编号输入有误，编号应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("%s\n",HBUmap.vexs[a-1].features);
    printf("再次查询请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，请先添加景点！\n");
        return;
    }
    showInfo();
    printf("请输入您所在的景点编号:");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("编号输入有误，编号应位于1～%d之间，重新输入！\n",HBUmap.n);
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
                printf("%d米 : %s",D[i],HBUmap.vexs[i].name);
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
    printf("再次查询请输入1，输入其他数字即可退出\n");
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
        printf("地图中无任何景点，请先添加景点！\n");
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
    printf("请输入您要查询之间距离的两个景点编号，中间用空格隔开：\n");
    scanf("%d %d",&b,&a);
    while(a<1 || a>HBUmap.n|| b<1 || b>HBUmap.n || a == b)
    {
         if(a == b)
            printf("请勿输入两个相同编号，重新输入！\n");
         else
            printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n",HBUmap.n);
         scanf("%d %d",&b,&a);
    }
    if(dist[a-1][b-1] == INFINITY)
    {
        printf("%s与%s之间无路径！\n",HBUmap.vexs[b-1].name,HBUmap.vexs[a-1].name);
        return;
    }
    else
    {
    	printf("%s到%s的最短路径长度为：%d米\n",HBUmap.vexs[b-1].name,HBUmap.vexs[a-1].name,dist[a-1][b-1]);
        printf("路径为：%s",HBUmap.vexs[b-1].name);
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
    printf("再次查询请输入1，输入其他数字即可退出\n");
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
        printf("欢迎进入游客系统，请输入您要进行的操作:\n");
        printf("1.景点介绍 2.查找您所在的景点到其他景点的最短路径 3.查找任意两个景点之间的最短路径 4.退出游客系统\n");
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
                printf("输入有误，请重新输入！\n");
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
        printf("欢迎进入管理系统，请输入您要进行的操作:\n");
        printf("1.景点介绍 2.查找您所在的景点到其他景点的最短路径 3.查找任意两个景点之间的最短路径 4.修改景点信息 5.增加景点信息 6.删除景点信息 7.增加道路 8.删除道路 9.退出管理系统 0.恢复初始数据\n");
        scanf("%d",&a);
        switch (a) {
            case 0:
                printf("确定要恢复初始数据吗？确认请输入1，输入其他数字即可返回。\n");
                int flag;
                scanf("%d",&flag);
                if(flag == 1)
                {
                    printf("正在恢复...\n");
                    for(long long i = 0;i < DELAY;i++);
                    create();
                    printf("数据恢复完毕！\n");
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
                printf("输入有误，请重新输入！\n");
                break;
        }
    }
}
int main()
{
    create();
    //system("clear");
    int a;
    printf("河北大学是教育部与河北省人民政府“部省合建”高校，也是河北省重点支持的国家一流大学建设一层次高校。\n***        欢迎您光临河北大学新校区！       ***\n");
    while(1){
    printf("***           请输入您的身份            ***\n1.游客 2.管理员 0.退出系统\n");
    scanf("%d",&a);
    switch (a) {
        case 1:
            Visiter();
            break;
        case 2:
            if(flag)
            {
            printf("请输入管理员密码，如果想进入游客系统，直接输入1：\n");
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
                    printf("密码错误次数达到三次！管理员账户已被锁定，请联系学校进行解锁!\n");
                    break;
                }
                printf("密码输入错误！请重新输入，如果连续三次输入错误密码，管理员账户将被锁定！\n");
                scanf("%s",password);
            }
            }
            else
                 printf("密码错误次数达到三次！管理员账户已被锁定，请联系学校进行解锁!\n");
            if(flag)
                Administrator();
            break;
        case 0:
            printf("退出后所有数据将恢复原始状态，编辑后的数据会丢失。是否确认？如果确认，请在下方输入“QUEREN”（大写），如果不确认，输入任意其他内容即可返回。\n");
            char code[100];
            scanf("%s",code);getchar();
            if(strcmp(code, CONFIRMATION) == 0)
            {
                printf("感谢使用，下次再见！\nCreated by 齐子佳 学号：20181101200 2019年11月16日 All rights reserved.\n");
                return 0;
            }
            else
                continue;
        default:
            printf("输入有误！请重新输入！\n");
            continue;
        }
    }
    return 0;
}


