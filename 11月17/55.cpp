#include<iostream>
using namespace std;
class Derived : public Base{
public:
    void print() //同名函数，可以修改基类中同名的函数的功能
    {
    	cout << "Derived" << endl;
    }
};

int main(){
	return 0;
} 
