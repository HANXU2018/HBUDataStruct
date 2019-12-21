#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
struct Country{
	int id;				//��¼���ҵı�� 
	int gold;
	int medal;
	int pnum;
	double avgold;
	double avgmedal;
	void cal()
	{
		avgold = (double)gold / pnum;
		avgmedal = (double)medal / pnum;
	}
};
const int maxn = 226;
Country a[maxn];

bool cmp1(Country b, Country c){
	return b.gold > c.gold;
}

bool cmp2(Country b, Country c){
	return b.medal > c.medal;
}

bool cmp3(Country b, Country c){
	return b.avgold > c.avgold;
}

bool cmp4(Country b, Country c){
	return b.avgmedal > c.avgmedal;
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i].gold >> a[i].medal >> a[i].pnum;
		a[i].id = i;					//���ұ�� 
		a[i].cal();
	}
	//rank��¼����������way��¼������������������ 
	int id, rank, way;					
	for(int i = 0;i < m;i++)
	{
		rank = 0x3f3f3f3f;
		way = 0;
		
		cin >> id;						//Ҫ���ҵĹ��ұ��
		sort(a, a + n, cmp1);
		for(int j = 0;j < n;j++)
		{
			//�����������ң��и��õ�rank 
			if(a[j].id == id){
				//����ҵ����β��ǵ�һ����ô��Ҫ��ǰ��ı�һ�ȣ������Ƿ��ǰһ������ 
				while(j != 0 && a[j].gold == a[j - 1].gold){j--;}
				if(j < rank){rank = j;way = 1;}
				break;
			}
		}
		//�ٰ��ڶ��ַ�ʽ���� 
		sort(a, a + n, cmp2);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].medal == a[j - 1].medal){j--;}
				if(j < rank){rank = j;way = 2;}
				break;
			}
		}
		//�����ַ�ʽ����
		sort(a, a + n, cmp3);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].avgold == a[j - 1].avgold){j--;}
				if(j < rank){rank = j;way = 3;}
				break;
			}
		}
		//�����ַ�ʽ����
		sort(a, a + n, cmp4);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].avgmedal == a[j - 1].avgmedal){j--;}
				if(j < rank){rank = j;way = 4;}
				break;
			}
		}
		//�����ʱ��rank + 1,��Ϊ���Ǵ�0��ʼ��� 
		if(i != m - 1)
			cout << rank + 1 << ":" << way << " ";
		else
			cout << rank + 1 << ":" << way << endl; 
	}
	return 0;
}

