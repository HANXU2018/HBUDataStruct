#include<iostream>
using namespace std;
class Derived : public Base{
public:
    void print() //ͬ�������������޸Ļ�����ͬ���ĺ����Ĺ���
    {
    	cout << "Derived" << endl;
    }
};

int main(){
	return 0;
} 
