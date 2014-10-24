/*
char* my_replace(char* src, char* des, char* model);
字符串替换函数，比如：
src: panwenqipan
des: pan
model: w
把src中出现des的地方都替换成model,替换后变成：wwenqiw


char* str_replce_move(char* src, char* des, char* result)
字符串替换
src: 传进来的字符串就是已经确定des在其中的字符串，并且是以des开头的字符串
des: 被替换的字符串
result： 替换后的字符串

*/
#include <iostream>
using namespace std;

//这个函数需要修改，要分两种情况，一个是替换的字符串大于被替换的字符串，一个是替换的字符串小于被替换的字符串

char* str_replce_move(char* src, char* des, char* result)
{
	char* temp_src = src;
	char* temp_des = des;
	int des_len = strlen(des);
	int result_len = strlen(result);
	int n = 0;

	while(n < result_len)  //把要替换后的字符串替换掉
	{
		*temp_src++ = *result++;
		n++;
	}
	n = 0;

	char* new_src = temp_src; //替换后的位置
	temp_src = src + des_len; //

	while(*new_src != '\0')
	{
		*new_src = *temp_src;
		new_src++;
		temp_src++;
	}
	return src;
}

void my_replace(char* src, char* des, char* model)
{
	int flag = 0;
	char* temp_src = src;
	char* temp_des = des;
	int des_len = strlen(des);
	while(*temp_src++ != '\0')
	{
		while(*temp_des != '\0')
		{
			if (*temp_des == *temp_src)
			{
				flag = 1;
				temp_des++;
				temp_src++;
			}else{
				temp_des = des;  //复位，没有完全匹配，就让temp_des指向原来的开始处
				flag = 0;
				break;
			}
		}
		
		if (*temp_des == '\0')  //判断des是否到结尾处，如果到结尾，就是完全匹配了，没有的话，就没有完全匹配
		{
			flag = 1;
			temp_des = des;
		}else{
			flag = 0;
		}
		if (flag == 1)  //如果标志位是1，那就是完全匹配了
		{
			temp_src = temp_src - des_len;  //让src指向匹配的第一个字符处
//			cout << temp_src << endl;
			temp_src = str_replce_move(temp_src, temp_des, model);
		}
	}
}

int main()
{
	char str[] = "panwenqiwenqiwwwen";
//	test(str);
	char* new_str = "panwenqi";
	my_replace(str, "wen", "woshini");
	cout << str << endl;
	system("pause");
	return 0;

}
