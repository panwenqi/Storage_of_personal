#include <iostream>
using namespace std;
/*
my_resever_str(char str[], int len)
实现字符串的反转，注意参数不能是char* str,因为参数是char* ，c/c++会默认当成是const char*
所以只能使用数组,数组名作为函数参数，也相当于是指针，把数组的首地址传给了函数
*/
void my_resever_str(char str[], int len)
{
	int mid = len / 2;  //计算出中间点
	cout << "mid = " << mid << endl;

	int n = 0;
	char temp = '/0';
	while (n < mid)
	{
		temp = str[n];
		str[n] = str[len - n - 1]; //注意要减一
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