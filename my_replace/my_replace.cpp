/*
char* my_replace(char* src, char* des, char* model);
�ַ����滻���������磺
src: panwenqipan
des: pan
model: w
��src�г���des�ĵط����滻��model,�滻���ɣ�wwenqiw


char* str_replce_move(char* src, char* des, char* result)
�ַ����滻
src: ���������ַ��������Ѿ�ȷ��des�����е��ַ�������������des��ͷ���ַ���
des: ���滻���ַ���
result�� �滻����ַ���

*/
#include <iostream>
using namespace std;

//���������Ҫ�޸ģ�Ҫ�����������һ�����滻���ַ������ڱ��滻���ַ�����һ�����滻���ַ���С�ڱ��滻���ַ���

char* str_replce_move(char* src, char* des, char* result)
{
	char* temp_src = src;
	char* temp_des = des;
	int des_len = strlen(des);
	int result_len = strlen(result);
	int n = 0;

	while(n < result_len)  //��Ҫ�滻����ַ����滻��
	{
		*temp_src++ = *result++;
		n++;
	}
	n = 0;

	char* new_src = temp_src; //�滻���λ��
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
				temp_des = des;  //��λ��û����ȫƥ�䣬����temp_desָ��ԭ���Ŀ�ʼ��
				flag = 0;
				break;
			}
		}
		
		if (*temp_des == '\0')  //�ж�des�Ƿ񵽽�β�����������β��������ȫƥ���ˣ�û�еĻ�����û����ȫƥ��
		{
			flag = 1;
			temp_des = des;
		}else{
			flag = 0;
		}
		if (flag == 1)  //�����־λ��1���Ǿ�����ȫƥ����
		{
			temp_src = temp_src - des_len;  //��srcָ��ƥ��ĵ�һ���ַ���
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
