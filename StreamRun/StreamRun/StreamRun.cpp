#include <windows.h>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct ThreadParam
{
	size_t number;
};

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
	ThreadParam* value = (ThreadParam*)lpParam;
	printf("Stream #%i completed its job \n", value->number);
	ExitThread(0); // установка кода завершения потока в 0
}

int main(int argc, char* argv[])
{
	size_t threadCount = stoul(argv[1]);
	HANDLE* handles = new HANDLE[threadCount]; //

	for (size_t i = 0; i < threadCount; i++)
	{
		ThreadParam* value = new ThreadParam();
		value->number = i + 1;
		handles[i] = CreateThread(NULL, 0, &ThreadProc, (LPVOID)value, CREATE_SUSPENDED, NULL); //создание потоков
	}

	for (size_t i = 0; i < threadCount; i++)
	{
		ResumeThread(handles[i]);
	}

	WaitForMultipleObjects(threadCount, handles, true, INFINITE);
	return 0;
}