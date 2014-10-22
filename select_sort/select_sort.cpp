#include <iostream>
using namespace std;

/*void select_sort(int*a,int n)
{
	register int i,j,min,t;

	for(i=0;i<n-1;i++)
	{
		min=i;//查找最小值
		for(j=i+1;j<n;j++)
			if(a[min]>a[j])min=j;//交换
		if(min!=i)
		{
			t=a[min];a[min]=a[i];a[i]=t;
		}
	}

}*/
void select_sort(int ay[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int t = i - 1;
		int temp = 0;
		for (int j = i; j < len; j++)
		{
			if (ay[j] < ay[t])
			{
				t = j;
			}
		}
		if (t != (i-1))
		{
			temp = ay[i-1];
			ay[i-1] = ay[t];
			ay[t] = temp;
		}
	}
}
int main()
{
/*	int m = 0;
	while (m < 3)
	{
		int a = 1;
		cout << a++ << endl;
		m++;
	}*/
	int ay[] = {1, 3, 2, 6, 3, 4};
	select_sort(ay, 6);
	for(int i = 0; i < 6; i++)
	{
		cout << ay[i] << " ";
	}
	system("pause");
	return 0;
}