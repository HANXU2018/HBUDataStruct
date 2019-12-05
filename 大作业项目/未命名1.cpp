#include<iostream>
using namespace std;
int main(){
	char a[2][2][3] = {{{1, 6, 3}, {5, 4, 15}}, {{3, 5, 33}, {23, 13, 7}}};
for (int i = 0; i < 12; i++)
    printf("%d",a[i%2][i%2][i%3]);
	return 0;
} 
