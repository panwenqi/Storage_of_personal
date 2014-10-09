#include <iostream>
#include "test.h"
using namespace std;

int main()
{
	
	int ay[] = {1, 9, 6, 5, 2, 7};
	cout << ay[3] << endl;
	int len = sizeof(ay)/sizeof(int);
	maopao(ay, len);
	printf_ay(ay, len);
	system("pause");
	return 0;
   
}