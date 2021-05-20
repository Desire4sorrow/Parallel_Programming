#include "Worker.h"
#include "Task.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <string>


int main(int argc, const char** argv)
{
	if (argc != 2)
	{
		return 1;
	}
	int numberOfThreads = std::stoi(argv[1]);

	try
	{
		IWorker* worker = new Worker();
		for (int i = 0; i < numberOfThreads; i++)
		{
			ITask* task = new Task(i + 1);
			//модель ситуации с запросом двух потоков на один объект
			bool abc = worker->ExecuteTask(task);
			std::cout << std::to_string(abc) ;

		}
		delete worker;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}



}
