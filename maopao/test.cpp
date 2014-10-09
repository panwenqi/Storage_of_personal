#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

void maopao(int ay[], int len)
{
	int temp;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len - i; j++)
		{
			if(ay[j] > ay[j + 1])
			{
				temp = ay[j + 1];
				ay[j] = ay[j + 1];
				ay[j + 1] = temp;
			}
		}
	}
}
void printf_ay(int ay[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << ay[i] << " ";
	}
	cout << endl;
}