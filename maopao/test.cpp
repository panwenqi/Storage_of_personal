#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

void maopao(int ay[], int len)
{
 	int temp = 0;
	/*�ⲿ��i���������е�ÿ��ȥ�Աȵ��Ǹ�Ԫ��
	j���Ƶ��ǣ�����ay[i]���Ԫ��ȥ��ÿ��Ԫ�ضԱȵĴ���
	Ҫע����� j<len-i-1 �������Ҫ��һ�������Ǵ�0��ʼ�ģ������һ����6������ay[j+1]�ͻ����Խ��
	*/
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len - i - 1; j++) 
		{
			if(ay[j] > ay[j + 1])
			{
				temp = ay[j];
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