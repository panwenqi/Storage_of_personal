#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <iostream>
typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(LPVOID lpThreadParameter);
typedef unsigned *PBEGINTHREADEX_THREADID;
DWORD WINAPI ThreadFunc(LPVOID);
//

//ubuntun
using namespace std;
int main()
{
	HANDLE hThread;
	DWORD dwThreadId;
	int i = 0;
	hThread = (HANDLE)_beginthreadex(NULL, 0, (PBEGINTHREADEX_THREADFUNC)ThreadFunc, (LPVOID)i, 0, (PBEGINTHREADEX_THREADID)&dwThreadId);

	if (hThread)
	{
		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
	}
	system("pause");
	return EXIT_SUCCESS;
}




DWORD WINAPI ThreadFunc(LPVOID n)
{
	cout << "this is new thread" << endl;
	return 0;
}
