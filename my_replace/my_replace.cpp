/*
char* my_replace(char* src, char* des, char* model);
�ַ����滻���������磺
src: panwenqipan
des: pan
model: w
��src�г���des�ĵط����滻��model,�滻���ɣ�wwenqiw



*/
#include <iostream>
using namespace std;

/*char* my_replace(char* src, char* des, char* model)
{
	char* temp_src = src;
	char* temp_des = des;
	
}*/

void test(char* str)
{
//	*(str++) = 'a';
	cout << str << endl;
	cout << "sizeof = " << sizeof(str) << endl;
	cout << "strlen = " << strlen(str) << endl;
}
int main()
{
	char str[] = "panwenqi";
	test(str);
	char* new_str = "panwenqi";
	test(new_str);
	system("pause");
	return 0;

}
