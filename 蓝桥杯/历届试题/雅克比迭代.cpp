#include<stdio.h>
#include<math.h>
#include<vector> 
using namespace std;
int main(void)
{
    int n,b,c,i,j,k,m;//n------未知数个数
    printf("输入未知数个数");
    printf("\n");
    scanf("%d",&n);
    //float A[n][n+1];//系数矩阵的增广矩阵
    vector<vector<float>>A(n,vector<float>(n+1));
	printf("input the array:");
    printf("\n");
    for(i=0;i<n;i++)//注意此时编号为0为第一列
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    //计算B矩阵
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=A[i][j]/A[i][i];
            if(j!=n) A[i][j]=-A[i][j];
        }
    }
    for(i=0;i<n;i++)//对角线元素为0
    {
        A[i][i]=0;
    }
     //输出求得的B
      for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            printf("%f   ",A[i][j]);
        }
        printf("\n");//矩阵换行
    }
    printf("输入初始值");
    scanf("%d",&b);
    printf("输入迭代的次数：");
    scanf("%d",&c);
    //float x[c][n];
    vector<vector<float>>x(c,vector<float>(n));
    for(i=0;i<n;i++)//赋值最初变量值
    {
        x[0][i]=b;
    }
    for(i=1;i<c;c++)
    {
        for(k=0;k<n;k++)
        {
            x[i][k]=0;//必须赋值，否则乱码
            for(j=0;j<n;j++)
                x[i][k]=x[i][k]+A[k][j]*x[i-1][j];//注意k和j的区别
        }
        x[i][k]=x[i][k]+A[k][n];//加上常数项
        for(m=0;m<n;m++)
    {
        printf("%6.4f  ", x[i][m]);
    }
    }
    return 0;
}

