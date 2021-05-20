#include "Worker.h"

bool Worker::ExecuteTask(ITask* task)
{
	if (IsBusy())
	{
		return false;
	}
	if (m_thread = CreateThread(NULL, 0, &ThreadProc, task, CREATE_SUSPENDED, NULL))
	{
		ResumeThread(m_thread);
		return true;
	}

	return false;
}

bool Worker::IsBusy()
{
	DWORD statusCode;
	GetExitCodeThread(m_thread, &statusCode);
	return statusCode == STILL_ACTIVE;
}	

Worker::~Worker()
{
	WaitForSingleObject(m_thread, INFINITE);
}

DWORD __stdcall Worker::ThreadProc(const LPVOID lpParam)
{
	auto task = (ITask*)lpParam;
	task->Execute();
	ExitThread(0);
}
