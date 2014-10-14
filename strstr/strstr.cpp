#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
/*
char *strstr(char *str1, const char *str2);
str1: ������Ŀ�ꡡstring expression to search.
str2: Ҫ���Ҷ���The string expression to find.
����ֵ����str2��str1���Ӵ�������ȷ��str2��str1�ĵ�һ�γ��ֵ�λ�ã�
�����ش�λ�õ�str1ĩβ�������ַ������str2����str1���Ӵ����򷵻�NULL��
ע�����뷵��str2��str1��һ�γ��ֵ�λ�ã������������

�����Լ�ʵ���������:my_strstr();
*/

char* my_strstr(char* str1, char* str2)
{
	char* temp_str1 = str1;
	char* temp_str2 = str2;
	int i = 0; //���Ǽ�¼str1��ƫ������Ҳ���Ǽ�¼���ص�λ��
	//����str1��str2����Ϊ��
	assert((temp_str1 != NULL) && (temp_str2 != NULL));

	//��str2�ǿգ�ֱ�ӷ���str1���˴�Ҳ���Բ��ӣ�����ᴦ��
	if(strlen(temp_str2) == 0)
	{
		return temp_str1;
	}

	//���str1�ĳ���С��str2�ĳ��ȣ���ô���ؿ�
	if(strlen(temp_str1) < strlen(temp_str2))
	{
		return NULL;
	}

	//���str2�ĳ���Ϊ1Ҳ����һ�����ַ����������ض�������һ�����ӵĹ��ֵܷ�Խ��Խ��
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

	//�����Ѿ��ų���str2�ĳ��ȴ���str1��str2Ϊ�ա�Ϊ���ַ����������
	while(*temp_str1 != '\0')
	{
		while(*temp_str2 != '\0')
		{
			if(*temp_str1++ == *temp_str2++)
			{
				i++; //��¼str1��ƫ����
			}else{
				break; //����ִ��break��str2Ҫ�Ա��꣬Ч�ʵ�
			}
			
		}
		if(*temp_str2 == '\0') //ע�⣬������ǿ��Ʒ���ֵ�ĵط�,����Ա���ͷ��أ�û����ͽ�������ĸ�λ
		{
			return temp_str1 - i;
		}else{  //�˴���str2�ĵ�ǰλ�üȲ�������Ҳ����str1�ĵ�ǰλ�����,�Ǿ͸�λtemp_str2��i
			temp_str2 = str2;
			i = 0;
		}
	}
}
int main()
{
	char* str1 = "abcdefg";

	//����
	char* str2 = "ef";
	cout << my_strstr(str1, str2) << endl;

	//����str2Ϊ��
	str2 = "";
	cout << my_strstr(str1, str2) << endl;
	
	//����str2Ϊ�����ַ�
	str2 = "d";
	cout << my_strstr(str1, str2) << endl;

	//����str2�ĳ��ȴ���str1
	str2 = "hdkjddsdjs";
	if(my_strstr(str1, str2) == NULL)
	{
		cout << "NULL" << endl;
	}
	system("pause");
	return 0;
}