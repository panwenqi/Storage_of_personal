#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
/*
char *strstr(char *str1, const char *str2);
str1: 被查找目标　string expression to search.
str2: 要查找对象　The string expression to find.
返回值：若str2是str1的子串，则先确定str2在str1的第一次出现的位置，
并返回此位置到str1末尾的所有字符；如果str2不是str1的子串，则返回NULL。
注：若想返回str2在str1第一次出现的位置，不是这个函数

下面自己实现这个函数:my_strstr();
*/

char* my_strstr(char* str1, char* str2)
{
	char* temp_str1 = str1;
	char* temp_str2 = str2;
	int i = 0; //这是记录str1的偏移量，也就是记录返回的位置
	//断言str1和str2都不为空
	assert((temp_str1 != NULL) && (temp_str2 != NULL));

	//若str2是空，直接返回str1，此处也可以不加，下面会处理
	if(strlen(temp_str2) == 0)
	{
		return temp_str1;
	}

	//如果str1的长度小于str2的长度，那么返回空
	if(strlen(temp_str1) < strlen(temp_str2))
	{
		return NULL;
	}

	//如果str2的长度为1也就是一个单字符，在这里特定处理，把一个复杂的功能分的越多越好
	if(strlen(temp_str2) == 1)
	{
		while(*temp_str1++ != '\0') 
		{
			if(*temp_str1 == *temp_str2)
			{
				return temp_str1; 		
			}
		}
	}

	//上面已经排除了str2的长度大于str1、str2为空、为单字符的特殊情况
	while(*temp_str1 != '\0')
	{
		while(*temp_str2 != '\0')
		{
			if(*temp_str1++ == *temp_str2++)
			{
				i++; //记录str1的偏移量
			}else{
				break; //若不执行break，str2要对比完，效率低
			}
			
		}
		if(*temp_str2 == '\0') //注意，这里才是控制返回值的地方,如果对比完就返回，没有完就进行下面的复位
		{
			return temp_str1 - i;
		}else{  //此处是str2的当前位置既不到结束也不和str1的当前位置相等,那就复位temp_str2和i
			temp_str2 = str2;
			i = 0;
		}
	}
}
int main()
{
	char* str1 = "abcdefg";

	//测试
	char* str2 = "ef";
	cout << my_strstr(str1, str2) << endl;

	//测试str2为空
	str2 = "";
	cout << my_strstr(str1, str2) << endl;
	
	//测试str2为单个字符
	str2 = "d";
	cout << my_strstr(str1, str2) << endl;

	//测试str2的长度大于str1
	str2 = "hdkjddsdjs";
	if(my_strstr(str1, str2) == NULL)
	{
		cout << "NULL" << endl;
	}
	system("pause");
	return 0;
}