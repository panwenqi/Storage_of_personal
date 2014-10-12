#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

void maopao(int ay[], int len)
{
 	int temp = 0;
	/*外部的i控制数组中的每次去对比的那个元素
	j控制的是，上面ay[i]这个元素去和每个元素对比的次数
	要注意的是 j<len-i-1 这里必须要减一，数组是从0开始的，比如第一次是6，下面ay[j+1]就会产生越界
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