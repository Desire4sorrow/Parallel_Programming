
#include "Task.h"
#include <iostream>
#include <string>

Task::Task(int number)
	: m_number(number)
{
}

void Task::Execute()
{
	std::cout << "thread number " + std::to_string(m_number) + " is working\n";
}