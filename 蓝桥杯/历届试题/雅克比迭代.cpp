#include<stdio.h>
#include<math.h>
#include<vector> 
using namespace std;
int main(void)
{
    int n,b,c,i,j,k,m;//n------δ֪������
    printf("����δ֪������");
    printf("\n");
    scanf("%d",&n);
    //float A[n][n+1];//ϵ��������������
    vector<vector<float>>A(n,vector<float>(n+1));
	printf("input the array:");
    printf("\n");
    for(i=0;i<n;i++)//ע���ʱ���Ϊ0Ϊ��һ��
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    //����B����
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=A[i][j]/A[i][i];
            if(j!=n) A[i][j]=-A[i][j];
        }
    }
    for(i=0;i<n;i++)//�Խ���Ԫ��Ϊ0
    {
        A[i][i]=0;
    }
     //�����õ�B
      for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            printf("%f   ",A[i][j]);
        }
        printf("\n");//������
    }
    printf("�����ʼֵ");
    scanf("%d",&b);
    printf("��������Ĵ�����");
    scanf("%d",&c);
    //float x[c][n];
    vector<vector<float>>x(c,vector<float>(n));
    for(i=0;i<n;i++)//��ֵ�������ֵ
    {
        x[0][i]=b;
    }
    for(i=1;i<c;c++)
    {
        for(k=0;k<n;k++)
        {
            x[i][k]=0;//���븳ֵ����������
            for(j=0;j<n;j++)
                x[i][k]=x[i][k]+A[k][j]*x[i-1][j];//ע��k��j������
        }
        x[i][k]=x[i][k]+A[k][n];//���ϳ�����
        for(m=0;m<n;m++)
    {
        printf("%6.4f  ", x[i][m]);
    }
    }
    return 0;
}

