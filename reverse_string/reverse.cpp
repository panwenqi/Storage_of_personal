#include <iostream>
using namespace std;
/*
my_resever_str(char str[], int len)
ʵ���ַ����ķ�ת��ע�����������char* str,��Ϊ������char* ��c/c++��Ĭ�ϵ�����const char*
����ֻ��ʹ������,��������Ϊ����������Ҳ�൱����ָ�룬��������׵�ַ�����˺���
*/
void my_resever_str(char str[], int len)
{
	int mid = len / 2;  //������м��
	cout << "mid = " << mid << endl;

	int n = 0;
	char temp = '/0';
	while (n < mid)
	{
		temp = str[n];
		str[n] = str[len - n - 1]; //ע��Ҫ��һ
		str[len - n - 1] = temp;
		n++;
	}
}

int main()
{
	char str[] = "abcdefghijklmn";
	int len = strlen(str);

	cout << str << endl;
	my_resever_str(str, len);
	cout << str << endl;
	system("pause");
	return 0;
}