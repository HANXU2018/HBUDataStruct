#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
struct Country{
	int id;				//记录国家的编号 
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
		a[i].id = i;					//国家编号 
		a[i].cal();
	}
	//rank记录最优排名，way记录最优排名的排名方法 
	int id, rank, way;					
	for(int i = 0;i < m;i++)
	{
		rank = 0x3f3f3f3f;
		way = 0;
		
		cin >> id;						//要查找的国家编号
		sort(a, a + n, cmp1);
		for(int j = 0;j < n;j++)
		{
			//如果是这个国家，有更好的rank 
			if(a[j].id == id){
				//如果我的名次不是第一，那么我要跟前面的比一比，看看是否跟前一名并列 
				while(j != 0 && a[j].gold == a[j - 1].gold){j--;}
				if(j < rank){rank = j;way = 1;}
				break;
			}
		}
		//再按第二种方式排序 
		sort(a, a + n, cmp2);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].medal == a[j - 1].medal){j--;}
				if(j < rank){rank = j;way = 2;}
				break;
			}
		}
		//第三种方式排序
		sort(a, a + n, cmp3);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].avgold == a[j - 1].avgold){j--;}
				if(j < rank){rank = j;way = 3;}
				break;
			}
		}
		//第四种方式排序
		sort(a, a + n, cmp4);
		for(int j = 0;j < n;j++)
		{
			if(a[j].id == id){
				while(j != 0 && a[j].avgmedal == a[j - 1].avgmedal){j--;}
				if(j < rank){rank = j;way = 4;}
				break;
			}
		}
		//输出的时候rank + 1,因为我是从0开始算的 
		if(i != m - 1)
			cout << rank + 1 << ":" << way << " ";
		else
			cout << rank + 1 << ":" << way << endl; 
	}
	return 0;
}

